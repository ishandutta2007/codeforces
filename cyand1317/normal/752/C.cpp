#include <cstdio>
static const int MAXN = 2e5 + 8;

int n;
char s[MAXN];

inline char mov_id(const char ch) {
    switch (ch) {
        case 'L': return 0;
        case 'R': return 1;
        case 'U': return 2;
        case 'D': return 3;
        default: return -1;
    }
}

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) s[i] = mov_id(getchar());

    int ans = 0;
    bool mark[4] = { false };
    for (int i = 0; i < n; ++i) {
        if (mark[s[i] ^ 1]) {
            ++ans;
            mark[0] = mark[1] = mark[2] = mark[3] = false;
        }
        mark[s[i]] = true;
    }

    printf("%d\n", ans + 1);
    return 0;
}