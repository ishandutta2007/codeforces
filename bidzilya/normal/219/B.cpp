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
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
const double eps = 1e-8;


int main()
{
    ll p,d,pp;
    cin >> p >> d;
    pp = p;
    int a[19];
    int len = 0;
    while (p>0)
    {
          a[len]=p%10;
          p /= 10;
          len++;
    }
    int ta = 0;
    while (ta<len && a[ta]==9)ta++;
    ll ts =0;
    ll tst=1;
    for (int i=0;i<ta;i++){ts=ts+tst*9;tst*=10;}
    ll teca = pp;
    for (int i=ta;i<len-1;i++)
    {
        ts = ts+tst*a[i];
        tst *= 10;
        if (a[i+1]>0 && ts+1<=d)
                     teca = pp-ts-1;
    }
    cout << teca << endl;
   // system("pause");
    return 0;
}