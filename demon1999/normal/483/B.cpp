#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define r_s(a, j) a.resize(j)
#define p_b(a, j) a.push_back(j)
#define sz(a) a.size()
#define forn(i, n) for(int i = 0; i < n; i++)
#define fork(i, j, n) for(int i = j; i < n; i++)
#define ford(i, n) for(int i = n - 1; i >= 0; i--)
#define ford1(i, j, n) for(int i = n - 1; i >= j; j--)
typedef long long ll;
using namespace std;
const long ma = 131072;
ll k, n, cn1, cn2, x, y, mid, j, p, q, l, r;
bool ok(ll k)
{
    j = k - k / x;
    q = k - k / y;
    p = k - k / (x * y);
    if(j < cn1 || q < cn2 || p < cn1 + cn2)return false;
    return true;
}
int main()
{
    cin >> cn1 >> cn2 >> x >> y;
    l = 1; r = 1000000000;r = r * r + 1;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(ok(mid))r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}