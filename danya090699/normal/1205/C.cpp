#include <bits/stdc++.h>
using namespace std;
const int sz=55;
int n, fi[sz][sz];
int que(int x, int y, int x2, int y2)
{
    if(x>x2 or y>y2) swap(x, x2), swap(y, y2);
    cout<<"? "<<x+1<<" "<<y+1<<" "<<x2+1<<" "<<y2+1<<"\n";
    int re;
    cin>>re;
    return re;
}
void dfs(int x, int y)
{
    for(int a=0; a<=2; a++)
    {
        for(int b=0; b<2; b++)
        {
            int dx=a, dy=2-a;
            if(b) dx=-dx, dy=-dy;
            int nx=x+dx, ny=y+dy;
            if(nx>=0 and nx<n and ny>=0 and ny<n and fi[nx][ny]==-1)
            {
                fi[nx][ny]=fi[x][y]^1^que(x, y, nx, ny);
                dfs(nx, ny);
            }
        }
    }
}
bool dp[2][sz][sz][sz][sz];
main()
{
    cin>>n;
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) fi[a][b]=-1;
    fi[0][0]=1, dfs(0, 0), fi[0][1]=0, dfs(0, 1);
    for(int l=0; l<=(n-1)*2; l++)
    {
        for(int x=0; x<n; x++)
        {
            for(int y=0; y<n; y++)
            {
                for(int dx=0; dx<=l; dx++)
                {
                    int dy=l-dx, nx=x+dx, ny=y+dy;
                    if(nx<n and ny<n)
                    {
                        for(int i=0; i<2; i++)
                        {
                            if(fi[x][y]^((x+y)&1&i) == fi[nx][ny]^((nx+ny)&1&i))
                            {
                                if(l<2) dp[i][x][y][nx][ny]=1;
                                else
                                {
                                    for(int dx2=0; dx2<2; dx2++)
                                    {
                                        for(int dnx2=0; dnx2<2; dnx2++)
                                        {
                                            int dy2=1-dx2, dny2=1-dnx2;
                                            int x2=x+dx2, y2=y+dy2, nx2=nx-dnx2, ny2=ny-dny2;
                                            if(x2<=nx2 and y2<=ny2)
                                            {
                                                if(dp[i][x2][y2][nx2][ny2]) dp[i][x][y][nx][ny]=1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        if(dp[0][x][y][nx][ny]!=dp[1][x][y][nx][ny] and l>1)
                        {
                            int re=que(x, y, nx, ny), an=0;
                            if(re!=dp[0][x][y][nx][ny]) an=1;
                            cout<<"!\n";
                            for(int a=0; a<n; a++)
                            {
                                for(int b=0; b<n; b++) cout<<(fi[a][b]^(an&(a+b)&1));
                                cout<<"\n";
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
}