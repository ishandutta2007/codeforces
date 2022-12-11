#include <cstdio>
#include <utility>
static const int MAXN = 1005;

int n;
bool s[MAXN] = { false };

int pops;
int ans[2] = { -1, -1 };

inline int query(bool *s)
{
    fputs("? ", stdout);
    for (int i = 0; i < n; ++i) putchar(s[i] ? '1' : '0');
    fputc('\n', stdout);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

inline std::pair<int, int> query_range(int l, int r)
{
    for (int i = l; i < r; ++i) s[i] = true;
    int delta = query(s) - ::pops;
    for (int i = l; i < r; ++i) s[i] = false;
    int len = r - l;
    return std::make_pair((len + delta) / 2, (len - delta) / 2);
}

int main()
{
    scanf("%d", &n);

    pops = query(s);
    int l = 0, r = n, mid;
    while (l < r - 1) {
        mid = (l + r) >> 1;
        std::pair<int, int> result = query_range(l, mid);
        if (result.first > 0 && result.second > 0) {
            r = mid;
        } else if (result.first == 0) {
            ans[1] = l;
            if (ans[0] == -1 && r - l == 2) ans[0] = mid;
            l = mid;
        } else {    // if (result.second == 0) {
            ans[0] = l;
            if (ans[1] == -1 && r - l == 2) ans[1] = mid;
            l = mid;
        }
    }

    printf("! %d %d\n", ans[0] + 1, ans[1] + 1);
    fflush(stdout);
    return 0;
}