#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <map>
#include <fstream>
#include <cstdio>
using namespace std;

typedef long long lli;
const int MAXN = 50;
const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,1,-1,0};
char a[MAXN][MAXN+1];
bool b[MAXN][MAXN];
int n,m;

void dfs(int x, int y)
{
     b[x][y] = true;
     for (int i=0;i<4;i++)
     {
         int nx = x + dx[i];
         int ny = y + dy[i];
         if (nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]!='.' && !b[nx][ny])
            dfs(nx, ny);
     }
}
     
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++)scanf("%s",a[i]);
    int cnt = 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='.')continue;
 
               cnt++;                 
               for (int i1=0;i1<n;i1++)
                   for (int j1=0;j1<m;j1++)
                       b[i1][j1]=false;
               a[i][j]='.';
               for (int k=0;k<4;k++)
               {
                   int nx = i + dx[k];
                   int ny = j + dy[k];
                   if (nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]!='.')
                   {
                       dfs(nx, ny);
                       break;
                   }            
               }
               for (int i1=0;i1<n;i1++)
                   for (int j1=0;j1<m;j1++)
                       if (!b[i1][j1] && a[i1][j1]!='.')
                       {
                                      printf("1");
                                      return 0;
                       }
               a[i][j]='#';
            }
    if (cnt>2)
       printf("2");
    else
        printf("-1");
    return 0;
}