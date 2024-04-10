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
using Int = long long;
using Real = long double;
using CP = complex<Real>;
using P = pair<Int, Int>;

const Int MOD = 1000000007;
const Int MOD2 = 998244353;
const Int LINF = (1LL << 60);
const int INF = (1000000007);
const Real EPS = 1e-10;
const long double PI = 3.141592653589793238462643383279502884L;

int n;
int a[60];

void solve()
{
    scanf("%d", &n);
    Int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum == 0) {
        puts("NO");
        return;
    }
    puts("YES");
    sort(a, a + n);
    if (sum > 0)
        reverse(a, a + n);

    int zerocnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            zerocnt++;
            continue;
        }
        printf("%d ", a[i]);
    }
    for (int i = 0; i < zerocnt; i++)
        printf("0 ");
    puts("");
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        solve();
    return 0;
}