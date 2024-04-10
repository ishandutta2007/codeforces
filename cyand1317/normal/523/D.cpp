#include <cstdio>
#include <set>
typedef long long int64;
static const int MAXN = 1e5 + 6;

int n, k;
std::multiset<int64> s;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) s.insert(0);

    int si, mi;
    int64 ans;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &si, &mi);
        if (*s.begin() <= si) ans = si + mi;
        else ans = *s.begin() + mi;
        s.erase(s.begin());
        s.insert(ans);
        printf("%I64d\n", ans);
    }

    return 0;
}