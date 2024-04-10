#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
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

Int nxt(Int lb, Int x, Int b)
{
    while (lb > x)
        x += b;
    return x;
}

void solve()
{
    char x[100];
    scanf(" IAO'%s", x);
    Int l = strlen(x);
    Int lb = 1989;
    Int b = 1;
    Int num = 0;
    for (int i = l - 1; i >= 0; i--) {
        num += b * (x[i] - '0');
        b *= 10;
        lb = nxt(lb, num, b) + 1;
    }
    lb--;
    printf("%lld\n", lb);
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
        solve();
    return 0;
}