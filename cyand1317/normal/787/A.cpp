// I'm friends with the monster that's under my bed
#include <cstdio>

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    int ans = -1;
    for (int i = 0; i <= 220; ++i) {
        int t = b + a * i;
        if (t >= d && (t - d) % c == 0) { ans = t; break; }
    }

    printf("%d\n", ans);
    return 0;
}