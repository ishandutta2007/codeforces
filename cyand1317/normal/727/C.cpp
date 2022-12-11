#include <cstdio>
#include <cstdlib>
static const int MAXN = 5004;

int n;
int a[MAXN];

inline int ask(int i, int j) {
    printf("? %d %d\n", i, j); fflush(stdout);
    int answer; scanf("%d", &answer); return answer;
}

int main()
{
    srand(114514);
    scanf("%d", &n);

    int x = ask(1, 2), y = ask(2, 3), z = ask(3, 1);
    a[1] = (x - y + z) / 2; a[2] = (x + y - z) / 2; a[3] = (-x + y + z) / 2;
    for (int i = 4; i <= n; ++i) {
        int p = rand() % (i - 1) + 1;   // :P
        a[i] = ask(p, i) - a[p];
    }

    putchar('!'); for (int i = 1; i <= n; ++i) printf(" %d", a[i]); putchar('\n');
    return 0;
}