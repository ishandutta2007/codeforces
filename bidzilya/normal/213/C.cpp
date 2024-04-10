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
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
template<typename T>T gcd(T, T);

int n;
vector< vector<int> > a;
vector< vector< vector<int> > > res;

int main()
{
    cin >> n;
    a.resize(n);
    for (int i=0;i<n;i++)
        a[i].resize(n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> a[i][j];
    res.resize(2*n-1);
    for (int c=0,i=1;c<2*n-1;c++,i += ((c>=n)?-1:1))
    {
        res[c].resize(i);
        for (int j=0;j<i;j++)
            res[c][j].resize(i);
    }
    res[0][0][0] = a[0][0];
    for (int diag=1; diag<n; diag++)
        for (int y1=0; y1<res[diag].size(); y1++)
            for (int y2=0; y2<res[diag].size(); y2++)
            {
                int r;
                bool found = false;
                int prev_size = res[diag-1].size();
                if (y1<prev_size && y2<prev_size && (!found || res[diag-1][y1][y2]>r))
                {
                                 found = true;
                                 r = res[diag-1][y1][y2];
                }
                if (y1<prev_size && y2>0 && (!found || res[diag-1][y1][y2-1]>r))
                {
                                 found = true;
                                 r = res[diag-1][y1][y2-1];
                }
                if (y1>0 && y2<prev_size && (!found || res[diag-1][y1-1][y2]>r))
                {
                         found = true;
                         r = res[diag-1][y1-1][y2];
                }
                if (y1>0 && y2>0 && (!found || res[diag-1][y1-1][y2-1]>r))
                {
                         found = true;
                         r = res[diag-1][y1-1][y2-1];
                }
                r += a[y1][diag-y1];
                if (y1!=y2)
                   r += a[y2][diag-y2];
                res[diag][y1][y2] = r;
            }
    for (int diag=n; diag<2*n-1; diag++)
        for (int y1=0; y1<res[diag].size(); y1++)
            for (int y2=0; y2<res[diag].size(); y2++)
            {
                int r;
                bool found = false;
                if (!found || res[diag-1][y1][y2]>r)
                {
                           found = true;
                           r = res[diag-1][y1][y2];
                }
                if (!found || res[diag-1][y1][y2+1]>r)
                {
                           found = true;
                           r = res[diag-1][y1][y2+1];
                }
                if (!found || res[diag-1][y1+1][y2]>r)
                {
                           found = true;
                           r = res[diag-1][y1+1][y2];
                }
                if (!found || res[diag-1][y1+1][y2+1]>r)
                {
                           found = true;
                           r = res[diag-1][y1+1][y2+1];
                }
                int yy1 = y1+diag-n+1;
                int yy2 = y2+diag-n+1;
                r += a[yy1][n-y1-1];
                if (yy1!=yy2)
                   r += a[yy2][n-y2-1];
                res[diag][y1][y2] = r;
            }
    cout << res[2*n-2][0][0] << endl;
   // system("pause");
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