#include <cstdio>
#include <cstdlib>
static const int MAXN = 59;
static const int PERI = 20000;

int n;
int dis, alti = +PERI;
char dir[10];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%s", &dis, dir);
        if (dir[0] == 'N') {
            if (alti > PERI - dis) { puts("NO"); return 0; }
            alti += dis;
        } else if (dir[0] == 'S') {
            if (alti < dis) { puts("NO"); return 0; }
            alti -= dis;
        } else {
            if (alti == PERI || alti == 0) { puts("NO"); return 0; };
        }
    }
    puts(alti == +PERI ? "YES" : "NO");
    return 0;
}