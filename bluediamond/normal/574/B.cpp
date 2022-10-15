#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=4000+7;

int n,m;
vector<int>g[N];
bool stiu[N][N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
                int x,y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
                stiu[x][y]=stiu[y][x]=1;
        }
        int ans=(1<<30);
        for(int a=1;a<=n;a++)
        {
                for(auto &b:g[a])
                {
                        for(auto &c:g[b])
                        {
                                /// a stie b
                                /// b stie c
                                /// a stie c?
                                if(stiu[a][c])
                                {
                                        ans=min(ans,(int)g[a].size()+(int)g[b].size()+(int)g[c].size()-6);
                                }
                        }
                }
        }
        if(ans==(1<<30))
        {
                cout<<"-1\n";
                return 0;
        }
        cout<<ans<<"\n";
        return 0;
}
/**

**/