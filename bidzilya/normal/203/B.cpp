#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int n,m,s[1001][1001];

bool check(int x, int y)
{
 for (int dx=0;dx<3;dx++)
     for (int dy=0;dy<3;dy++)
     {
      int nx = x+dx,
          ny = y+dy;
      if (nx>=1 && nx<=n && ny>=1 && ny<=n)
      {
                s[nx][ny]++;
                if (s[nx][ny]==9)
                   return true;
      }    
     }     
 return false;
}

int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            s[i][j]=0;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        if (check(x,y))
        {
                       cout << i+1;
                       cin >> n;
                       return 0;
        }
    }
    cout << -1;
    return 0;
}