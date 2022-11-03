#include <algorithm>
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
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;

int main()
{
    int n;
    int r1;
    cin >> n;
    cin >> r1;
    for (int i=1;i<n;i++)
    {
        int a;
        cin >> a;
        r1 = max(a,r1);
    }
    int m;
    cin >> m;
    int x[5000];
    for (int i=0;i<m;i++)cin >> x[i];
    int k;
    cin >> k;
    int y[5000];
    for (int i=0;i<k;i++)cin >> y[i];
    int a,b;
    cin >> a >> b;
    double r2;
    bool found = false;
    for (int i=0;i<m;i++)
        for (int j=0;j<k;j++)
        {
            double tr = sqrt(1.0*x[i]*b*r1*r1/(y[j]*a+x[i]*b));
            if (tr<r1 && (!found || tr>r2))
            {
                       found = true;
                       r2 = tr;
            }
        }
    cout << setprecision(15) << r2 << endl;
  //  system("pause");
    return 0;
}