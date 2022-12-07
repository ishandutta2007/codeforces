#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
struct poi
{
    int y, x;
};
poi cu, nel;
int main()
{
    //ifstream in("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, level=1;
    cin>>n>>m>>k;
    if(k%2==0)
    {
        queue <poi> qu;
        char fi[n][m], le[4]={'D', 'L', 'R', 'U'};
        int lev[n][m];
        poi go[4];
        go[0].y=1, go[0].x=0;
        go[1].y=0, go[1].x=-1;
        go[2].y=0, go[2].x=1;
        go[3].y=-1, go[3].x=0;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                cin>>fi[a][b];
                if(fi[a][b]=='X')
                {
                    cu.y=a, cu.x=b;
                    qu.push(cu);
                    lev[a][b]=0;
                }
                else lev[a][b]=-1;
            }
        }
        while(qu.size()!=0)
        {
            int q=qu.size();
            for(int a=0; a<q; a++)
            {
                int y=qu.front().y, x=qu.front().x;
                for(int b=0; b<4; b++)
                {
                    nel.y=y+go[b].y, nel.x=x+go[b].x;
                    if(nel.y>=0 and nel.y<n and nel.x>=0 and nel.x<m)
                    {
                        if(fi[nel.y][nel.x]!='*' and lev[nel.y][nel.x]==-1)
                        {
                            lev[nel.y][nel.x]=level;
                            qu.push(nel);
                        }
                    }
                }
                qu.pop();
            }
            level++;
        }
        bool fo;
        vector <char> ans;
        while(k>0)
        {
            fo=0;
            for(int a=0; a<4; a++)
            {
                int ny=cu.y+go[a].y, nx=cu.x+go[a].x;
                if(ny>=0 and ny<n and nx>=0 and nx<m)
                {
                    if(lev[ny][nx]!=-1 and lev[ny][nx]<=k-1)
                    {
                        cu.y=ny, cu.x=nx, fo=1, k--;
                        ans.push_back(le[a]);
                        break;
                    }
                }
            }
            if(fo==0) break;
        }
        if(fo) for(int a=0; a<ans.size(); a++) cout<<ans[a];
        else cout<<"IMPOSSIBLE";
    }
    else cout<<"IMPOSSIBLE";
}