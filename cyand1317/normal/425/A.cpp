#include <cstdio>
#include <set>
static const int INF = 0x7fffffff;
static const int MAXN = 205;
static const int MAXK = 12;
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n, k, a[MAXN];
int f[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int ans = -INF;
    for (int i = 0; i < n; ++i) {
        std::multiset<int> inner, outer;
        int inner_sum = 0;
        for (int j = 0; j < n; ++j) outer.insert(a[j]);
        for (int j = i; j < n; ++j) {
            inner.insert(a[j]); inner_sum += a[j];
            outer.erase(outer.find(a[j]));
            int cur = inner_sum;
            std::multiset<int>::iterator p = inner.begin();
            std::multiset<int>::reverse_iterator q = outer.rbegin();
            upd_max(ans, cur);
            for (int i = 0; i < k && p != inner.end() && q != outer.rend(); ++i, ++p, ++q) {
                cur += (*q - *p);
                upd_max(ans, cur);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}