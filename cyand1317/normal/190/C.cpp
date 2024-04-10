#include <cstdio>
#include <cstring>
static const int MAXN = 1e5 + 4;

int n;
bool is_pair[MAXN];

int check(int p)
{
    if (p == -1 || p >= n) return -1;
    return is_pair[p] ? check(check(p + 1)) : p + 1;
}
int print(int p)
{
    if (is_pair[p]) {
        printf("pair<");
        int t = print(p + 1);
        printf(",");
        t = print(t);
        printf(">");
        return t;
    } else {
        printf("int");
        return p + 1;
    }
}

int main()
{
    scanf("%*d");
    static char s[24];
    for (n = 0; scanf("%s", s) == 1; ++n) is_pair[n] = !strcmp(s, "pair");

    if (check(0) == n) print(0); else puts("Error occurred");

    return 0;
}