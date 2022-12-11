#include <cstdio>
#include <cstring>
static const int MAXN = 1004;
static const int MAXLEN = 12;

int n;
char s[MAXLEN], t[MAXLEN], u[MAXLEN], v[MAXLEN];

int main()
{
    scanf("%s%s", s, t);
    scanf("%d", &n);
    printf("%s %s\n", s, t);
    for (int i = 0; i < n; ++i) {
        scanf("%s%s", u, v);
        if (strcmp(s, u) == 0) strcpy(s, v);
        else if (strcmp(s, v) == 0) strcpy(s, u);
        else if (strcmp(t, u) == 0) strcpy(t, v);
        else strcpy(t, u);
        printf("%s %s\n", s, t);
    }
    return 0;
}