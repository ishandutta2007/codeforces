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

int n, m;
char s[110000];
int val[110000];
int pop_count[1 << 20];

vector<Int> trans(vector<Int> x)
{
    Int n = x.size();
    for (int width = 2; width <= n; width *= 2) {
        for (int i = 0; i < n; i += width) {
            for (int j = i; j < i + width / 2; j++) {
                int a = x[j];
                int b = x[j + width / 2];
                x[j] = a + b;
                x[j] %= MOD;
                x[j + width / 2] = a - b;
                x[j + width / 2] %= MOD;
            }
        }
    }
    return x;
}

int main()
{
    scanf("%d%d", &n, &m);
    vector<Int> cost(1 << n, 0), cnt(1 << n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            val[j] += (s[j] - '0') << i;
        }
    }
    for (int i = 0; i < m; i++)
        cnt[val[i]]++;
    for (int i = 1; i < (1 << n); i++) {
        pop_count[i] = pop_count[i / 2] + i % 2;
        cost[i] = min(pop_count[i], n - pop_count[i]);
    }
    auto a = trans(cnt);
    auto b = trans(cost);
    for (int i = 0; i < a.size(); i++)
        (a[i] *= b[i]) %= MOD;
    a = trans(a);
    for (auto &x : a) {
        if (x < 0)
            x += MOD;
        for (int i = 0; i < n; i++) {
            if (x % 2)
                x += MOD;
            x /= 2;
        }
    }
    cout << *min_element(a.begin(), a.end()) << endl;
    return 0;
}