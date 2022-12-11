#include <cstdio>
#include <cstring>
static const int MAXN = 1e5 + 3;
static const int ALPHABET = 28;

char good[ALPHABET];
bool g[ALPHABET] = { false };
int n;
char t[MAXN], s[MAXN];
bool pfx[MAXN] = { false }, sfx[MAXN] = { false };

int main()
{
    scanf("%s", good);
    int good_ct = strlen(good);
    for (int i = 0; i < good_ct; ++i) g[good[i] - 'a'] = true;

    scanf("%s", t);
    int tl = strlen(t);
    int ast = -1;
    for (int i = 0; i < tl; ++i)
        if (t[i] == '*') { ast = i; break; }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int sl = strlen(s);

        for (int j = 0; j < sl && j < tl; ++j)
            pfx[j] = (j == 0 ? true : pfx[j - 1]) && (t[j] == s[j] || (t[j] == '?' && g[s[j] - 'a']));
        for (int j = 0; j < sl && j < tl; ++j)
            sfx[j] = (j == 0 ? true : sfx[j - 1]) && (t[tl - 1 - j] == s[sl - 1 - j] || (t[tl - 1 - j] == '?' && g[s[sl - 1 - j] - 'a']));

        if (ast == -1) {
            puts(tl == sl && pfx[tl - 1] ? "YES" : "NO");
        } else {
            bool flag = true;
            for (int i = ast; i <= sl - (tl - ast); ++i) flag &= !g[s[i] - 'a'];
            puts(tl <= sl + 1 && (ast == 0 ? true : pfx[ast - 1]) && (ast == tl - 1 ? true : sfx[tl - 2 - ast]) && flag ? "YES" : "NO");
        }
    }

    return 0;
}