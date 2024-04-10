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

int k,b,n;
map<int,int> c;
int tec[100001];

int main()
{
    cin >> k >> b >> n;
    ll ans = 0;
    tec[0] = 0;
    c[0]++;
    int cnt_zero =0;
    for (int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        if (!a)cnt_zero++;else cnt_zero=0;
        tec[i] = (tec[i-1]+a)%(k-1);
        int ff;
        if (!b)
           ans += cnt_zero;
        else
        if (b==k-1)
        {
                   if (cnt_zero!=(i+1))
                   {
                                       ans += c[tec[i]];
                                       if (tec[i-cnt_zero]==tec[i])
                                          ans -= cnt_zero;
                   }
        }else
        {
            ff = (tec[i]-b)%(k-1);
            if (ff<0)ff+=(k-1);
            ans += c[ff];
        }
        c[tec[i]]++;
    }
    cout << ans << endl;        
  //  system("pause");
    return 0;
}