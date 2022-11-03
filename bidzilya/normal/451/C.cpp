#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
  
typedef long long ll;

ll n, k, d1, d2, d;

ll x[3];

bool test()
{
    sort(x, x + 3);
    ll t = 0;
    for (int i = 0; i < 3; ++i)
        t += x[2] - x[i];
    if (t > d) return false;
    if ((d - t) % 3 != 0) return false;
    t = 0;
    for (int i = 0; i < 3; ++i)
        t += x[i];
    if (t > k) return false;
    if ((k - t) % 3 != 0) return false;
    return true;
}

bool test1()
{
    if (d1 - d2 < 0) return false;
    x[0] = 0;
    x[1] = d1;
    x[2] = d1 - d2;
    return test();
}

bool test2()
{
    x[0] = 0;
    x[1] = d1;
    x[2] = d1 + d2;
    return test();
}

bool test3()
{
    x[0] = d1;
    x[1] = 0;
    x[2] = d2;
    return test();
}

bool test4()
{
    if (d2 - d1 < 0) return false;
    x[0] = d2 - d1;
    x[1] = d2;
    x[2] = 0;
    return test();
}

bool test5()
{
    x[0] = d2 + d1;
    x[1] = d2;
    x[2] = 0;
    return test();
}

int main()
{
    ios_base::sync_with_stdio(false);
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cin >> n >> k >> d1 >> d2;
        d = n - k;
        if (test1() || test2() || test3() || test4() || test5()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    cout.flush();

    return 0;
}