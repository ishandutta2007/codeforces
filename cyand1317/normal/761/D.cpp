#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 1e5 + 4;
using std::max_element;
using std::min_element;

int64 n, l, r;
int64 a[MAXN], b[MAXN], c[MAXN], c_id[MAXN];

int main()
{
    scanf("%I64d%I64d%I64d", &n, &l, &r);
    for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
    for (int i = 0; i < n; ++i) { scanf("%I64d", &c[i]); c_id[--c[i]] = i; }

    b[c_id[0]] = 0;
    for (int i = 1; i < n; ++i) {
        b[c_id[i]] = b[c_id[i - 1]] + (a[c_id[i]] - a[c_id[i - 1]] + 1);
    }

    int64 range = *max_element(b, b + n) - *min_element(b, b + n);
    if (range > r - l) { puts("-1"); return 0; }
    int64 delta = l - *min_element(b, b + n);
    for (int i = 0; i < n; ++i) printf("%I64d%c", b[i] + delta, i == n - 1 ? '\n' : ' ');

    return 0;
}