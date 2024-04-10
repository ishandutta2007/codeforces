#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=300005;
int n;
vector<int> v[N];
string ini;
int p[N];
int pone[N];
int ptwo[N];
int depth[N];
int sz[N];
int big[N];
int head[N];
string s="$";
string t;
vector<int> st;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
const ll pr=31;
const ll mod=uniform_int_distribution<int>(100000000,2000000000)(gen);
ll pw[2*N];
ll hs[2*N];

void dfs(int a)
{
    depth[a]=depth[p[a]]+1;
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p[a]) continue;
        p[to]=a;
        dfs(to);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
    }
}

void decompose(int a,int hd)
{
    head[a]=hd;
    st.push_back(a);
    if(big[a]==0)
    {
        string tmp;
        for(int b:st) tmp+=ini[b];
        int pos=s.size();
        s+=tmp;
        for(int b:st) pone[b]=pos++;
        reverse(tmp.begin(),tmp.end());
        t+=tmp;
        pos=n+t.size();
        for(int b:st) ptwo[b]=pos--;
        st.clear();
    }
    else decompose(big[a],hd);
    for(int to:v[a])
    {
        if(to!=p[a]&&to!=big[a]) decompose(to,to);
    }
}

ll add(ll a,ll b){return (a+b)%mod;}
ll sub(ll a,ll b){return (a-b+mod)%mod;}
ll mul(ll a,ll b){return (a*b)%mod;}

void ini_hs()
{
    pw[0]=1;
    for(int i=1;i<=2*n;i++) pw[i]=mul(pw[i-1],pr);
    for(int i=1;i<=2*n;i++) hs[i]=add(mul(hs[i-1],pr),s[i]-'a');
}

ll h(int l,int r)
{
    return sub(hs[r],mul(pw[r-(l-1)],hs[l-1]));
}

vector<array<int,2>> paths(int a,int b)
{
    vector<array<int,2>> one,two;
    while(head[a]!=head[b])
    {
        if(depth[head[a]]>depth[head[b]])
        {
            one.push_back({ptwo[a],ptwo[head[a]]});
            a=p[head[a]];
        }
        else
        {
            two.push_back({pone[head[b]],pone[b]});
            b=p[head[b]];
        }
    }
    if(depth[a]<=depth[b]) two.push_back({pone[a],pone[b]});
    else one.push_back({ptwo[a],ptwo[b]});
    reverse(two.begin(),two.end());
    for(auto z:two) one.push_back(z);
    return one;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> ini;
    ini="$"+ini;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    decompose(1,1);
    s+=t;
    ini_hs();
    int q;
    cin >> q;
    while(q--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        vector<array<int,2>> one=paths(a,b);
        vector<array<int,2>> two=paths(c,d);
        int szx=one.size();
        int szy=two.size();
        int res=0;
        int x=0,y=0;
        while(x<szx&&y<szy)
        {
            auto &[lx,rx]=one[x];
            auto &[ly,ry]=two[y];
            int now=min(rx-lx+1,ry-ly+1);
            if(h(lx,lx+now-1)==h(ly,ly+now-1))
            {
                lx+=now;
                if(lx>rx) x++;
                ly+=now;
                if(ly>ry) y++;
                res+=now;
            }
            else
            {
                int l=0,r=now+1;
                while(l<r-1)
                {
                    int m=(l+r)/2;
                    if(h(lx,lx+m-1)==h(ly,ly+m-1)) l=m;
                    else r=m;
                }
                res+=l;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}