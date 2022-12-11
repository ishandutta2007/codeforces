#include <cstdio>
#include <algorithm>
static const int MAXN = 1e5 + 4;

int n;
char s[MAXN];

int main()
{
    for (n = 0; (s[n] = getchar()) != '\n'; ++n) ; s[n] = '\0';

    int best_negative_pos = -1;
    for (int i = 0; i < n - 1; ++i) if (!(s[i] & 1)) {
        if (s[i] < s[n - 1]) {
            std::swap(s[i], s[n - 1]); puts(s); return 0;
        } else {
            best_negative_pos = i;
        }
    }

    if (best_negative_pos == -1) puts("-1");
    else {
        std::swap(s[best_negative_pos], s[n - 1]);
        puts(s);
    }

    return 0;
}