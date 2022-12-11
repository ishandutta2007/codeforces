#include <cstdio>
#include <cstring>
#include <algorithm>
static const int MAXN = 1e5 + 4;

int s_len, t_len;
char s[MAXN], t[MAXN];
int pre[MAXN];
bool is_border[MAXN] = { false };
int f[MAXN] = { 0 }, g[MAXN] = { 0 };

void kmp_calc(int n, char *s, int *pre)
{
    pre[0] = -1; pre[1] = 0;
    int last = 0;
    for (int i = 2; i <= n; ++i) {
        while (last > 0 && s[last] != s[i - 1]) last = pre[last];
        if (s[last] != s[i - 1]) pre[i] = last = 0;
        else pre[i] = ++last;
    }
    //for (int i = 0; i <= n; ++i) printf("%d%c", pre[i], i == n ? '\n' : ' ');
}

int main()
{
    gets(s); s_len = strlen(s);
    gets(t); t_len = strlen(t);
    kmp_calc(t_len, t, pre);
    for (int i = pre[t_len]; i >= 0; i = pre[i]) is_border[i] = true;

    for (int i = t_len - 1; i < s_len; ++i) {
        bool valid = true;
        for (int j = i - t_len + 1; j <= i; ++j)
            if (s[j] != '?' && s[j] != t[j - (i - t_len + 1)]) { valid = false; break; }
        if (valid) {
            f[i] = (i == t_len - 1 ? 0 : g[i - t_len]) + 1;
            for (int j = i - t_len + 1; j < i; ++j)
                if (is_border[j - (i - t_len + 1) + 1]) f[i] = std::max(f[i], f[j] + 1);
        } else {
            f[i] = 0;
        }
        g[i] = std::max(g[i - 1], f[i]);
    }

    int ans = *std::max_element(f, f + s_len);
    printf("%d\n", ans);
    return 0;
}