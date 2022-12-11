#include <cstdio>
static const int MAXN = 104;
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n = 0;
bool s[MAXN];

int main()
{
    char ch;
    while ((ch = getchar()) >= 'A' && ch <= 'Z') {
        s[n] = (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U') || (ch == 'Y');
        ++n;
    }

    int ans = 0, last = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i]) { ans = max(ans, i - last); last = i; }
    }

    ans = max(ans, n - last);
    printf("%d\n", ans);
    return 0;
}