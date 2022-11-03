#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;

const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,-1,1,0};

bool us[501][501];
char mp[501][501];
int n, m;

vector<int> aT,aX,aY;
int sz = 0;

void dfs(int x, int y, bool p=false)
{
   us[x][y] = 1;
   aT.push_back(0);
   aX.push_back(x);
   aY.push_back(y);
   ++sz;
   for (int i=0; i<4; ++i)
   {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if (nx > 0 && nx <=n && ny > 0 && ny <= m && 
            !us[nx][ny] && mp[nx][ny] == '.')
         dfs(nx, ny, true);
   }
   if (p)
   {
      aT.push_back(1);
      aX.push_back(x);
      aY.push_back(y);
      sz += 2;
   }
}

int main()
{
   scanf("%d%d\n",&n,&m);
   for (int i=1; i<=n; ++i)
   {
      for (int j=1; j<=m; ++j)
         scanf("%c",&mp[i][j]);
      scanf("\n");
   }
   for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
         if (!us[i][j] && mp[i][j]=='.')
            dfs(i,j);
   printf("%d\n", sz);
   for (int i=0; i<aT.size(); ++i)
      if (!aT[i])
         printf("B %d %d\n", aX[i], aY[i]);
      else
         printf("D %d %d\nR %d %d\n", aX[i], aY[i], aX[i], aY[i]);
   return 0;
}