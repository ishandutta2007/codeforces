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
    int n,m;
    cin >> n >> m;
    int a[1111],b[1111];
    for (int i=0;i<m;i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    int min_sum = 0;
    int max_sum = 0;
    for (int i=0;i<n;i++)
    {
        int mn = -1;
        int mx = -1;
        for (int j=0;j<m;j++)
            if (a[j]!=0 && (mn==-1 || a[j]<a[mn]))
               mn = j;
        for (int j=0;j<m;j++)
            if (mx==-1 || b[j]>b[mx])
               mx = j;
        max_sum += b[mx];
        min_sum += a[mn];
        a[mn]--;
        b[mx]--;
    }
    cout << max_sum << " " << min_sum << endl;
    
  //  system("pause");
    return 0;
}