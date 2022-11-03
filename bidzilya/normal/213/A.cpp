#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
using namespace std;

typedef long long ll;
const ll MD = 10007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
template<typename T>T gcd(T, T);

int n;
int nv[200];
vector< vector<int> > g;

int go(int v)
{
    bool b[200];
    for (int i=0;i<n;i++) b[i] = false;
    int cnt = 0;
    int tec = 0;
    while (1)
    {
          for (int itr=0;itr<n;itr++)
              for (int i=0;i<n;i++)
                  if (!b[i] && nv[i]==v)
                  {
                        bool may = true;
                        for (int j=0;j<g[i].size();j++)
                            if (!b[g[i][j]])
                            {
                                            may = false;
                                            break;
                            }
                        if (may)
                        {
                                b[i] = true;
                                tec++;
                                cnt++;
                        }
                  }      
          if (cnt==n)break;
          
          v++;
          if (v==4)v=1;
          tec++;
    }
    return tec;
}

int main()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> nv[i];
    g.resize(n);
    for (int i=0;i<n;i++)
    {
        int k;
        cin >> k;
        g[i].resize(k);
        for (int j=0;j<k;j++)
        {
            cin >> g[i][j];
            g[i][j]--;
        }
    }
    int ans = MAX_INT;
    for (int i=1;i<4;i++)
        ans = min(ans,go(i));
    cout << ans << endl;
  //  system("pause");
    return 0;
}

/**************************************************/
template<typename T>T gcd(T x, T y)
{
                 while (x>0 && y>0)
                       if (x>=y)
                          x %= y;
                       else
                           y %= x;
                 return (x+y);
}