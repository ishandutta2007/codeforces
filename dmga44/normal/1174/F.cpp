#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

vector<int> g[MAXN];
bool mk[MAXN],mk2[MAXN],ok[MAXN];
int p[MAXN],l[MAXN],sons[MAXN][2];

void dfs(int u)
{
    mk[u]=1;
    for(auto y : g[u])
        if(!mk[y] && !mk2[y])
        {
            l[y]=l[u]+1;
            dfs(y);
            p[y]=u;
        }
}

void dfs1(int u)
{
    mk[u]=1;
    if(ok[u])
        sons[u][0]++;
    for(auto y : g[u])
        if(!mk[y] && !mk2[y])
        {
            dfs1(y);
            sons[u][0]+=sons[y][0];
            sons[u][1]=max(sons[y][0],sons[u][1]);
        }
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    p[0]=-1;
    dfs(0);

    cout << "d 1" << '\n';
    cout.flush();
    int level;
    cin >> level;
    int cont=0;
    for(int i=0;i<n;i++)
        if(l[i]==level)
        {
            ok[i]=1;
            cont++;
        }
    for(int i=0;i<n;i++)
        mk[i]=0;
    int r=0;
    while(cont>1)
    {
        dfs1(r);
        for(int i=0;i<n;i++)
            if(sons[i][0]>cont/2 && sons[i][1]<=cont/2)
            {
                cout << "d" << ' ' << i+1 << '\n';
                cout.flush();
                int x;
                cin >> x;
                if(x==level-l[i])
                {
                    mk2[i]=1;
                    cout << "s" << ' ' << i+1 << '\n';
                    cout.flush();
                    cin >> r;
                    r--;
                    cont=sons[r][0];
                }
                else
                {
                    mk2[i]=1;
                    cont-=sons[i][0];
                }
                break;
            }
        for(int i=0;i<n;i++)
            mk[i]=sons[i][0]=sons[i][1]=0;
    }

    dfs1(r);

    for(int i=0;i<n;i++)
        if(mk[i] && ok[i])
        {
            cout << "! " << i+1 << '\n';
            break;
        }

    return 0;
}