//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=40;
vector <int> sv[sz];
int an[sz][2], ch[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
set <pair <int, int> > ma;
void dfs(int v, int pr, int x, int y, int le)
{
    an[v][0]=x, an[v][1]=y;
    ma.insert(make_pair(x, y));
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            for(int b=0; b<4; b++)
            {
                int px=x+ch[b][0]*(1<<(le+1)), py=y+ch[b][1]*(1<<(le+1));
                int nx=x+ch[b][0]*(1<<le), ny=y+ch[b][1]*(1<<le);
                if(ma.find(make_pair(px, py))==ma.end() and ma.find(make_pair(nx, ny))==ma.end())
                {
                    dfs(ne, v, nx, ny, le-1);
                    break;
                }
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, pos=1;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
    }
    for(int a=0; a<n; a++) if(sv[a].size()>4) pos=0;
    if(pos)
    {
        cout<<"YES\n";
        dfs(0, -1, 0, 0, 29);
        for(int a=0; a<n; a++) cout<<an[a][0]<<" "<<an[a][1]<<"\n";
    }
    else cout<<"NO";
}