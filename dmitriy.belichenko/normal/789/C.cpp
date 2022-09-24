#include<math.h>
#include<set>
#include <map>
#include<deque>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
int n;
int main()
{
       cin >> n;
    vector<int> a(n);
 
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long  ans = 0;
    vector<int>d(n);
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2 == 0)
            d[i] = abs(a[i] - a[i + 1]);
        else
            d[i] = -abs(a[i] - a[i + 1]);
    }
    long long cur = 0;
    for (int i = n - 2; i >= 0; --i) {
        cur += d[i];
        cur = max(0LL, cur);
        if (i % 2 == 0)
        {
            ans = max(ans, cur);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2 == 1)
            d[i] = abs(a[i] - a[i + 1]);
        else
            d[i] = -abs(a[i] - a[i + 1]);
    }
    cur = min(0LL , cur);
    for (int i = n - 2; i >= 0; --i) {
        cur += d[i];
        cur = max(0LL, cur);
        if (i % 2 != 0)
        {
            ans = max(ans, cur);
        }
    }
 
    cout << ans << endl;
    return 0;
}