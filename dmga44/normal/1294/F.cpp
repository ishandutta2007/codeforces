#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

vector<int> g[MAXN];
vector<pip> len[MAXN];
vector<ppp> pos;
pii up[MAXN];
bool mk[MAXN];
int par[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto y : g[u])
        if(!mk[y])
        {
            par[y]=u;
            dfs(y);
            len[u].push_back(pip(len[y][0].first+1,pii(len[y][0].second.first,y)));
        }

    len[u].push_back(pip(0,pii(u,u)));

    sort(len[u].rbegin(),len[u].rend());
}

void dfs1(int u)
{
    mk[u]=1;
    if(len[u].size()>=3 && len[u][2].first<=up[u].first)
        pos.push_back(ppp(pii(len[u][0].first+len[u][1].first+up[u].first,len[u][0].second.first),pii(len[u][1].second.first,up[u].second)));
    else
    {
        if(len[u].size()==2)
            pos.push_back(ppp(pii(len[u][0].first+len[u][1].first+up[u].first,len[u][0].second.first),pii(len[u][1].second.first,up[u].second)));
        else if(len[u].size()>=3 && len[u][2].first>up[u].first)
            pos.push_back(ppp(pii(len[u][0].first+len[u][1].first+len[u][2].first,len[u][0].second.first),pii(len[u][1].second.first,len[u][2].second.first)));
    }
    for(auto v : g[u])
    {
        if(!mk[v])
        {
            pii p1=pii(-1,-1);
            if(len[u][0].second.second!=v)
                p1=pii(len[u][0].first+1,len[u][0].second.first);
            else
                p1=pii(len[u][1].first+1,len[u][1].second.first);

            up[v]=max(p1,pii(up[u].first+1,up[u].second));
            dfs1(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    par[0]=-1;
    dfs(0);
    for(int i=0;i<n;i++)
        mk[i]=0;

    up[0]=pii(0,0);
    dfs1(0);

    sort(pos.rbegin(),pos.rend());

//    for(int i=0;i<n;i++)
//    {
//        db(i)
//        for(int j=0;j<min(2,(int)len[i].size());j++)
//            cout << len[i][j].first << ' ' << len[i][j].second.first << ' ' << len[i][j].second.second << '\n';
//        cout << '\n';
//    }

    for(int i=0;i<1;i++)
    {
        db(pos[i].first.first)
        cout << pos[i].first.second+1 << ' ' << pos[i].second.first+1 << ' ' << pos[i].second.second+1 << '\n';
//        cout << '\n';
    }

    return 0;
}