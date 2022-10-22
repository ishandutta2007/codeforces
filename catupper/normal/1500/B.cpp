#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define PRIM 3
#define INF (1 << 29)
#define LINF (1LL << 60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

vector<int> posa(1100000, -1);
vector<int> posb(1100000, -1);
int n, m, a, b;
Int k;

Int gcd(Int x, Int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

P extgcd(Int x, Int y)
{
    if (x == 0)
        return {0, 1};
    P tmp = extgcd(y % x, x);
    Int a = tmp.first;
    Int b = tmp.second;
    return {b - a * (y / x), a};
}

Int crt(Int x1, Int mod1, Int x2, Int mod2)
{
    auto tmp = extgcd(mod1, mod2);
    Int g = tmp.first * mod1 + tmp.second * mod2;
    if ((x2 - x1) % g != 0)
        return -1;
    Int a = tmp.first;
    a *= (x2 - x1) / g;
    Int ans = mod1 * a + x1;
    Int p = mod1 * mod2 / g;
    ans %= p;
    if (ans < 0)
        ans += p;
    return ans;
}

Int g, period;
vector<Int> ok;
Int cnt(Int x)
{
    Int ans = x;
    for (auto m : ok) {
        ans -= x / period;
        if (x % period > m)
            ans--;
    }
    return ans;
}

int main()
{
    scanf("%d%d%lld", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        posa[a] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b);
        posb[b] = i;
    }
    g = gcd(n, m);
    period = Int(n) * Int(m) / g;
    for (int i = 0; i < 1100000; i++) {
        if (posa[i] == -1 || posb[i] == -1)
            continue;
        int x = posa[i], y = posb[i];
        Int r = crt(x, n, y, m);
        if (r == -1)
            continue;
        ok.push_back(r);
    }

    Int bottom = k - 1, top = 1e18;
    while (top - bottom > 1) {
        Int mid = (top + bottom) / 2;
        if (cnt(mid) >= k)
            top = mid;
        else
            bottom = mid;
    }
    cout << top << endl;
    return 0;
}