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
    int n,k;
    cin >> n >> k;
    int a[222];
    for (int i=0;i<=2*n;i++)cin >> a[i];
    for (int i=1;k && i<=2*n;i+=2)
        if (a[i]-1>a[i-1] && a[i]-1>a[i+1])
        {
                          a[i]--;
                          k--;
        }
    for (int i=0;i<=2*n;i++)cout << a[i] << " ";
    cout << endl;
   // system("pause");
    return 0;
}