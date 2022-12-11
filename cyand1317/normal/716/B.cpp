#include <cstdio>
static const int MAXN = 50002;

int n = 0;
char s[MAXN];
int ct[26] = { 0 };

inline bool check() {
    for (int i = 0; i < 26; ++i) if (ct[i] >= 2) return false;
    return true;
}

int main()
{
    while ((s[n] = getchar()) >= 'A' && s[n] <= 'Z' || s[n] == '?') ++n;
    if (n < 26) { puts("-1"); return 0; }

    int ans = -1;
    for (int i = 0; i < 26; ++i)
        if (s[i] != '?') ++ct[s[i] - 'A'];
    if (check()) ans = 0;
    if (ans == -1) for (int i = 26; i < n; ++i) {
        if (s[i] != '?') ++ct[s[i] - 'A'];
        if (s[i - 26] != '?') --ct[s[i - 26] - 'A'];
        if (check()) { ans = i - 25; break; }
    }

    if (ans == -1) puts("-1");
    else {
        for (int i = ans; i < ans + 26; ++i) if (s[i] == '?')
            for (int p = 0; p < 26; ++p) if (ct[p] == 0) {
                s[i] = 'A' + p; ct[p] = 1; break;
            }
        for (int i = 0; i < n; ++i) if (s[i] == '?') s[i] = 'W';
        puts(s);
    }

    return 0;
}