#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int K=5900;
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r)->int{return uniform_int_distribution<int>(l,r)(gen);};
    const ll mod=1000000007;
    array<ll,2> p={rng(26,135),rng(26,135)};
    if(p[0]==p[1]) p[1]++;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    int n;
    cin >> n;
    vector<string> s(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        s[i]="$"+s[i];
    }
    int sz=(int)s[1].size()-1;
    vector<array<ll,2>> pw(sz+1,{1,1});
    for(int i=1;i<=sz;i++) for(int z=0;z<2;z++) pw[i][z]=mul(pw[i-1][z],p[z]);
    vector<vector<array<ll,2>>> h(n+1,vector<array<ll,2>>(sz+1,{0,0}));
    for(int i=1;i<=n;i++) for(int j=1;j<=sz;j++) for(int z=0;z<2;z++) h[i][j][z]=add(mul(h[i][j-1][z],p[z]),s[i][j]-'a');
    auto g=[&](int i,int l,int r)->array<ll,2>{return {sub(h[i][r][0],mul(h[i][l-1][0],pw[r-(l-1)][0])),sub(h[i][r][1],mul(h[i][l-1][1],pw[r-(l-1)][1]))};};
    vector<vector<int>> inc(n+1,vector<int>(sz+1,0));
    for(int i=1;i<=n;i++)
    {
        int l=1;
        while(l<=sz)
        {
            int r=l;
            while(r+1<=sz&&s[i][r]<=s[i][r+1]) r++;
            for(int j=l;j<=r;j++) inc[i][j]=r;
            l=r+1;
        }
    }
    vector<pair<array<int,26>,int>> cnt(n+1);
    for(int i=1;i<=n;i++)
    {
        cnt[i].first.fill(0);
        cnt[i].second=i;
        for(int j=1;j<=sz;j++) cnt[i].first[s[i][j]-'a']++;
    }
    ll res=0;
    vector<vector<int>> groups;
    vector<int> tmp;
    sort(cnt.begin(),cnt.end());
    for(int i=1;i<=n;i++)
    {
        tmp.push_back(cnt[i].second);
        if((i<n&&cnt[i].first!=cnt[i+1].first)||i==n)
        {
            res+=(ll(tmp.size())*(i-tmp.size())*1337);
            groups.push_back(tmp);
            tmp.clear();
        }
    }
    if(n<=K)
    {
        for(vector<int> &group:groups)
        {
            for(int a:group)
            {
                for(int b:group)
                {
                    if(a>=b) continue;
                    int l=0,r=sz;
                    while(l<r-1)
                    {
                        int m=(l+r)/2;
                        if(h[a][m]==h[b][m]) l=m;
                        else r=m;
                    }
                    int one=r;
                    l=1,r=sz+1;
                    while(l<r-1)
                    {
                        int m=(l+r)/2;
                        if(g(a,m,sz)==g(b,m,sz)) r=m;
                        else l=m;
                    }
                    int two=l;
                    if(inc[a][one]>=two||inc[b][one]>=two) res++;
                    else res+=2;
                }
            }
        }
    }
    else
    {
        vector<vector<array<ll,2>>> halpha(sz+1,vector<array<ll,2>>(26,{0,0}));
        for(int i=1;i<=sz;i++) for(int j=0;j<26;j++) for(int z=0;z<2;z++) halpha[i][j][z]=add(mul(halpha[i-1][j][z],p[z]),j);
        auto hsort=[&](array<int,26> &c)->array<ll,2>
        {
            array<ll,2> t={0,0};
            for(int i=0;i<26;i++) for(int z=0;z<2;z++) t[z]=add(mul(t[z],pw[c[i]][z]),halpha[c[i]][i][z]);
            return t;
        };
        vector<vector<array<ll,2>>> opt(n+1);
        for(int i=1;i<=n;i++)
        {
            vector<array<ll,2>> now;
            for(int l=1;l<=sz;l++)
            {
                array<int,26> c;
                c.fill(0);
                for(int r=l;r<=sz;r++)
                {
                    c[s[i][r]-'a']++;
                    array<ll,2> t={0,0};
                    for(int z=0;z<2;z++)
                    {
                        t[z]=h[i][l-1][z];
                        t[z]=add(mul(t[z],pw[r-l+1][z]),hsort(c)[z]);
                        t[z]=add(mul(t[z],pw[sz-r][z]),g(i,r+1,sz)[z]);
                    }
                    now.push_back(t);
                }
            }
            sort(now.begin(),now.end());
            for(int j=0;j<(int)now.size();j++) if(j==0||now[j]!=now[j-1]) opt[i].push_back(now[j]);
        }
        for(vector<int> &group:groups)
        {
            int gsz=group.size();
            res+=(2*ll(gsz)*(gsz-1)/2);
            vector<array<ll,2>> v;
            for(int a:group) for(array<ll,2> t:opt[a]) v.push_back(t);
            sort(v.begin(),v.end());
            for(int a:group)
            {
                res-=(upper_bound(v.begin(),v.end(),h[a][sz])-lower_bound(v.begin(),v.end(),h[a][sz])-1);
            }
        }
    }
    cout << res << "\n";
    return 0;
}