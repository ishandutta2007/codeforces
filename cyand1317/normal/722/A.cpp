#include <cstdio>

int main()
{
    int fmt, h, m;
    scanf("%d", &fmt);
    scanf("%d:%d", &h, &m);

    if (m >= 60) m = m % 10;
    if (fmt == 24) {
        if (h >= 24) h = h % 10;
    } else if (h > 12 || h == 0) {
        if (h % 10 != 0) h = h % 10;
        else h = 10;
    }
    printf("%02d:%02d\n", h, m);

    return 0;
}