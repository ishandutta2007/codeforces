#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

vector<int> g[MAXN],nodes;
bool mk[MAXN],nr[MAXN];

void dfs(int u)
{
    mk[u]=1;
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk[v] && !nr[v])
            dfs(v);
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    u=0;
    while(1)
    {
        dfs(u);

        int sz=nodes.size();
        if(sz==1)
        {
            cout << "! " << nodes[0]+1 << endl;
            break;
        }
        else if(sz==2)
        {
            int w;
            cout << "? " << nodes[0]+1 << ' ' << nodes[1]+1 << endl;
            cin >> w;
            cout << "! " << w << endl;
            break;
        }
        else
        {
            for(int i=0;i<n;i++)
                if(mk[i])
                {
                    vector<int> oks;
                    for(auto y : g[i])
                        if(mk[y])
                            oks.push_back(y);
                    if(oks.size()>1)
                    {
                        int w;
                        cout << "? " << oks[0]+1 << ' ' << oks[1]+1 << endl;
                        cin >> w;
                        w--;
                        if(i!=w)
                            nr[i]=1;
                        if(oks[0]!=w)
                            nr[oks[0]]=1;
                        if(oks[1]!=w)
                            nr[oks[1]]=1;

                        u=w;
                        break;
                    }
                }
        }

        nodes.clear();
        for(int i=0;i<n;i++)
            mk[i]=0;
    }

    return 0;
}