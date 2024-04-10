#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    cin >> k;
    const ll mod=1000000007;
    map<string,int> h={{"white",0},{"yellow",1},{"green",2},{"blue",3},{"red",4},{"orange",5}};
    map<ll,set<ll>> v;
    map<ll,array<ll,6>> dp;
    map<ll,int> col;
    int n;
    cin >> n;
    while(n--)
    {
        ll a;
        string c;
        cin >> a >> c;
        col[a]=h[c];
        while(a!=1)
        {
            v[a/2].insert(a);
            a/=2;
        }
    }
    auto good=[&](int c)->vector<int>
    {
        vector<int> r;
        for(int i=0;i<6;i++) if(i/2!=c/2) r.push_back(i);
        return r;
    };
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    auto fpow=[&](ll b,ll e)->ll
    {
        ll r=1;
        while(e)
        {
            if(e&1) r=mul(r,b);
            b=mul(b,b);
            e/=2;
        }
        return r;
    };
    function<void(ll)> dfs=[&](ll a)
    {
        dp[a]={0,0,0,0,0,0};
        if(v[a].empty()) dp[a][col[a]]=1;
        else
        {
            for(ll to:v[a]) dfs(to);
            for(int i=0;i<6;i++)
            {
                ll t=1;
                for(ll to:v[a])
                {
                    ll s=0;
                    for(int g:good(i)) s=add(s,dp[to][g]);
                    t=mul(t,s);
                }
                dp[a][i]=t;
            }
            if(col.find(a)!=col.end()) for(int i=0;i<6;i++) if(i!=col[a]) dp[a][i]=0;
        }
    };
    dfs(1);
    ll t=0;
    for(int i=0;i<6;i++) t=add(t,dp[1][i]);
    cout << mul(t,fpow(4,(1ll<<k)-1-(int)dp.size())) << "\n";
    return 0;
}