#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int n;
int f[55][55][55][55][2];
char s[55][55];
void update(int &x,int y)
{
    if (x>y)x=y;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    rep(i,n)rep(j,n)rep(k,n)rep(p,n)for(int q=0;q<=1;q++)f[i][j][k][p][q]=10000000;
    rep(i,n)rep(j,n)f[i][i][j][j][0]=(s[i][j]=='#'?1:0);
    rep(i,n)rep(j,n)f[i][i][j][j][1]=0;

    rep(i,n)rep(j,n)rep(k,n-i+1)rep(p,n-j+1)
    {
            int t1=k+i-1;
            int t2=p+j-1;
            int w; if (i>j)w=i; else w=j;
            for (int x=k;x<t1;x++)
            {

                update(f[k][t1][p][t2][0],f[k][x][p][t2][0]+f[x+1][t1][p][t2][0]);
                update(f[k][t1][p][t2][1],f[k][x][p][t2][1]+f[x+1][t1][p][t2][1]);
                update(f[k][t1][p][t2][0],f[k][x][p][t2][1]+f[x+1][t1][p][t2][1]+w);
            }
            for (int y=p;y<t2;y++)
            {
                update(f[k][t1][p][t2][0],f[k][t1][p][y][0]+f[k][t1][y+1][t2][0]);
                update(f[k][t1][p][t2][1],f[k][t1][p][y][1]+f[k][t1][y+1][t2][1]);
                update(f[k][t1][p][t2][0],f[k][t1][p][y][1]+f[k][t1][y+1][t2][1]+w);
            }
    }
    cout<<f[1][n][1][n][0]<<endl;
}