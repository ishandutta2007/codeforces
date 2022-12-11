#include <cstdio>

int y1, y2, y3;
int x;

template <typename T> inline void swap(T &a, T &b) {
    static T t; t = a; a = b; b = t;
}
inline void sort() {
    if (y1 < y2) swap(y1, y2);
    if (y1 < y3) swap(y1, y3);
    if (y2 < y3) swap(y2, y3);
}

int main()
{
    scanf("%d%d", &x, &y1); y2 = y3 = y1;

    int ans = 0;
    while (y1 < x) {
        y3 = y1 + y2 - 1;
        sort();
        //printf("%d %d %d\n", y1, y2, y3);
        ++ans;
    }
    y1 = x;
    if (y2 != x) ++ans;
    if (y3 != x) ++ans;
    printf("%d\n", ans);

    return 0;
}