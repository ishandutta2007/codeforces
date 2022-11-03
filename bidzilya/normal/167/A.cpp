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
const double eps = 1e-7;

int main()
{
    int n,a,d;
    cin >> n >> a >> d;
    double tt = sqrt(2.0*d/a);
    double pt = 0.0;
    cout << setprecision(8);
    for (;n>0;n--)
    {
          int t,v;
          cin >> t >> v;
          double t1 = 1.0*v/a;
          double t2 = tt;
          if (t2>t1)
          {
                        double dd = d - t1*a*t1/2.0;
                        t2 = t1 + dd/v;
          }
          t2 = max(t2+t, pt);
          cout << t2 << endl;
          pt = t2;
    }
    return 0;
}