#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 300005

bool mk[MAXN];
int level[MAXN],lims[MAXN][2],rmq[MAXN][19],lg[MAXN];
vector<int> g[MAXN],euler;

void dfs(int u)
{
    mk[u]=1;
    lims[u][0]=euler.size();
    for(auto y: g[u])
        if(!mk[y])
        {
            euler.push_back(u);
            level[y]=level[u]+1;
            dfs(y);
        }
    lims[u][1]=euler.size();
    euler.push_back(u);
}

int query(int l,int r)
{
    if(l>=r)
        swap(l,r);
    int p=lg[r-l+1];
    if(level[rmq[l][p]]<level[rmq[r-(1<<p)+1][p]])
        return rmq[l][p];
    else
        return rmq[r-(1<<p)+1][p];
}

int dist(int u,int v)
{
    int lca=query(lims[u][0],lims[v][0]);
    return level[u]+level[v]-2*level[lca];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=lg[i-1]+!(i&(i-1));

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    int le=euler.size();
    for(int i=0;i<le;i++)
        rmq[i][0]=euler[i];
    for(int j=1;j<=lg[le];j++)
        for(int i=0;i+(1<<j)<=le;i++)
            rmq[i][j]=(level[rmq[i][j-1]]<level[rmq[i+(1<<(j-1))][j-1]]) ? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1];
//    for(int i=0;i<le;i++)
//        cout << euler[i] << ' ';
//    db("")
//    for(int i=0;i<4;i++,cout << '\n')
//        for(int j=0;j<10;j++)
//            cout << rmq[j][i] << ' ';
//    db("")
    int q;
    cin >> q;
    while(q--)
    {
        int x,y,a,b,k;
        cin >> x >> y >> a >> b >> k;
        x--,y--;
        b--,a--;
        int d1=dist(a,b);
        int d2=dist(a,x)+dist(y,b)+1;
        int d3=dist(b,x)+dist(y,a)+1;
//        cout << dist(a,x) << ' ' << dist(y,b) << ' ' << dist(b,x) << ' ' << dist(y,a) << '\n';
//        cout << d1 << ' ' << d2 << ' ' << d3 << '\n';
        if(((d1<=k) && ((d1&1)==(k&1))) || ((d2<=k) && ((d2&1)==(k&1))) || ((d3<=k) && ((d3&1)==(k&1))))
            db("YES")
        else
            db("NO")
    }

    return 0;
}