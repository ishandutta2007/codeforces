#include <cstdio>
#include <cstring>
static const int MAXN = 1006;
static const int MAXLEN = 512;

int pol, eny, shared = 0;
char s[MAXN][MAXLEN];
char t[MAXLEN];

int main()
{
    scanf("%d%d", &pol, &eny); getchar();
    for (int i = 0; i < pol; ++i) gets(s[i]);
    for (int i = 0; i < eny; ++i) {
        gets(t);
        for (int j = 0; j < pol; ++j)
            if (strcmp(s[j], t) == 0) { ++shared; break; }
    }

    puts((shared - shared / 2 + (pol - shared) > shared / 2 + (eny - shared)) ? "YES" : "NO");
    return 0;
}