#include <cstdio>
static const int MAXN = 12;

int n;
int q[MAXN], ct[MAXN];

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) {
        q[i] = getchar() - '0';
        ++ct[q[i]];
    }

    puts(
        (!!ct[1]) + (!!ct[4]) + (!!ct[7]) > 0 &&
        (!!ct[3]) + (!!ct[6]) + (!!ct[9]) > 0 &&
        (!!ct[1]) + (!!ct[2]) + (!!ct[3]) > 0 &&
        (!!ct[7]) + (!!ct[0]) + (!!ct[9]) > 0 ||
        (!!ct[0]) > 0 && (!!ct[1]) + (!!ct[2]) + (!!ct[3]) > 0 ?
        "YES" : "NO"
    );
    return 0;
}