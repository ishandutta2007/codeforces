#include <cstdio>
static const int MAXN = 102;

int n;
int p[MAXN], ct[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]); getchar();
    char ch;
    for (int i = 0; i < n; ++i) {
        ct[i] = 0;
        while ((ch = getchar()) >= 'a' && ch <= 'z' || ch == ' ') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
                ++ct[i];
        }
    }

    for (int i = 0; i < n; ++i) if (ct[i] != p[i]) {
        puts("NO"); return 0;
    }
    puts("YES");
    return 0;
}