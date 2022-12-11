// _>
#include <cstdio>
#include <algorithm>
using std::swap;

int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    bool a[3] = { x == 0, x == 1, x == 2 };

    n %= 108;
    for (int i = n; i > 0; --i) {
        if (i & 1) swap(a[0], a[1]); else swap(a[1], a[2]);
    }

    puts(a[0] ? "0" : (a[1] ? "1" : "2"));
    return 0;
}