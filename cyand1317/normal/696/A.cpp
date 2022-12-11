#include <cstdio>
#include <algorithm>
#include <map>
typedef long long int64;
static const int MAXQ = 1007;

int q;
std::map<int64, int64> par_fee;

int main()
{
    scanf("%d", &q);

    int op, w;
    int64 u, v;
    do {
        scanf("%d%I64d%I64d", &op, &u, &v); //--u; --v;
        if (u > v) std::swap(u, v);
        if (op == 1) {  // Modification
            scanf("%d", &w);
            while (__builtin_clzll(u) > __builtin_clzll(v)) {
                par_fee[v] += w;
                v >>= 1;
            }
            while (u != v) {
                par_fee[u] += w;
                par_fee[v] += w;
                u >>= 1; v >>= 1;
            }
        } else {        // Query
            int64 ans = 0;
            while (__builtin_clzll(u) > __builtin_clzll(v)) {
                ans += par_fee[v];
                v >>= 1;
            }
            while (u != v) {
                ans += par_fee[u] + par_fee[v];
                u >>= 1; v >>= 1;
            }
            printf("%I64d\n", ans);
        }
    } while (--q);

    return 0;
}