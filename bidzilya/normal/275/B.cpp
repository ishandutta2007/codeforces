#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int n,m;
int sumStr[51][51];
int sumStl[51][51];
char a[51][51];

bool isPathStr(int str, int x, int y)
{
    if (y<x)swap(x,y);
    return (sumStr[str][y]-sumStr[str][x-1]==y-x+1);
}
bool isPathStl(int stl, int x, int y)
{
    if (y<x)swap(x,y);
    return (sumStl[stl][y]-sumStl[stl][x-1]==y-x+1);
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin >> a[i][j];
            sumStr[i][j]=sumStr[i][j-1];
            sumStl[j][i]=sumStl[j][i-1];
            if (a[i][j]=='B')
            {
                sumStr[i][j]++;
                sumStl[j][i]++;
            }
        }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i][j]=='B')
                for (int i1=1; i1<=n; i1++)
                    for (int j1=1; j1<=n; j1++)
                        if (a[i1][j1]=='B')
                            if (!(isPathStr(i,j1,j)&&isPathStl(j1,i,i1) ||
                                  isPathStl(j,i,i1)&&isPathStr(i1,j,j1)))
                                  {
                                      cout << "NO" << endl;
                                      return 0;
                                  }
    cout << "YES" << endl;
    return 0;
}