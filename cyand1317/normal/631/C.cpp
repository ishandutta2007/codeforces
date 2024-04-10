#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
static const int MAXN = 200004;
static const int MAXM = 200004;

int n, m, a[MAXN], b[MAXN];
int t[MAXM], r[MAXM];
std::vector<int> aff;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d%d", &t[i], &r[i]);

    int last_r = 0;
    for (int i = m - 1; i >= 0; --i) {
        if (r[i] > last_r) aff.push_back(i), last_r = r[i];
    }
    std::reverse(aff.begin(), aff.end());

    int last_t = -1;
    last_r = -1;
    int p, q, parity;
    for (int i = 0; i < aff.size(); ++i) {
        int op = aff[i];//, nx = (i + 1 == aff.size() ? -1 : aff[i + 1]);
        if (last_t == -1) {
            if (t[op] == 1) std::sort(a, a + r[op], std::less<int>());
            else std::sort(a, a + r[op], std::greater<int>());
            for (int j = 0; j < n; ++j) b[j] = a[j];
            last_t = t[op], last_r = r[op];
            p = 0, q = r[op], parity = 0;
        } else if (last_t != t[op]) {
            for (int j = last_r - 1; j >= r[op]; --j)
                a[j] = b[parity ? (p++) : (--q)];
            last_t = t[op], last_r = r[op], parity ^= 1;
        }
    }
    for (int j = last_r - 1; j >= 0; --j)
        a[j] = b[parity ? (p++) : (--q)];

    for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    return 0;
}