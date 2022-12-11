#include <cstdio>
typedef long long int64;
static const int MAXN = 1004;

int n; int64 x; int TwT = 0;
char ch; int d_i;

int main()
{
    scanf("%d%I64d", &n, &x);

    for (int i = 0; i < n; ++i) {
        getchar(); scanf("%c%d", &ch, &d_i);
        if (ch == '+') x += d_i;
        else if (x >= d_i) x -= d_i;
        else ++TwT;
    }

    printf("%I64d %d\n", x, TwT);
    return 0;
}