#include <cstdio>
static const int MAXN = 53;

int n, k;
bool valid[MAXN];
int ans[MAXN];

inline char *get_name(int id) {
    char *ret = new char[10]();
    int p = 0;
    do { ret[p] = id % 26 + (p == 0 ? 'A' : 'a'); id /= 26, ++p; } while (id);
    return ret;
}

int main()
{
    scanf("%d%d", &n, &k);
    char s[24];
    for (int i = 0; i <= n - k; ++i) {
        scanf("%s", s);
        valid[i] = (s[0] == 'Y');
    }
    for (int i = 0; i < k - 1; ++i) ans[i] = i;
    for (int i = k - 1; i < n; ++i) ans[i] = (valid[i - k + 1] ? i : ans[i - k + 1]);
    for (int i = 0; i < n; ++i) printf("%s%c", get_name(ans[i]), i == n - 1 ? '\n' : ' ');
    return 0;
}