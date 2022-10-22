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

int n, k;
int a[60];
char s[110000];

void solve()
{
    scanf("%d%d", &n, &k);
    scanf("%s", s);

    int bonus = 0;
    int sum = 0;
    vector<int> vs;
    if (s[0] == 'W')
        vs.push_back(0);
    int length = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            bonus = 0;
            length++;
        }
        else {
            if (length > 0) {
                vs.push_back(length);
                length = 0;
            }
            sum++;
            sum += bonus;
            bonus = 1;
        }
    }

    if (sum == 0) {
        printf("%d\n", max(0, k * 2 - 1));
        return;
    }
    sort(vs.rbegin(), vs.rend() - 1);
    while (vs.size() > 1 && k >= vs.back()) {
        k -= vs.back();
        sum += 2 * vs.back();
        sum++;
        vs.pop_back();
    }
    sum += k * 2;
    sum = min(sum, n * 2 - 1);
    printf("%d\n", sum);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        solve();
    return 0;
}