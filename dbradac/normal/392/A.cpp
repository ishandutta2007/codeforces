#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    ll n2, x, y, zx=-1, r=0;

    scanf("%d", &n);

    n2 = (ll) n * n;

    for (y=n, x=0; y>0; y--) {
        for (; y*y + x*x > n2; x--);
        for (; y*y + x*x <= n2; x++) {
            if (zx < x || ((x+1) * (x+1) + y*y) > n2) {
                r++;
                if (zx == x)
                    zx++;
                else
                    zx = x;
            }
        }
    }

    if (!n)
        printf("1\n");
    else
        printf("%I64d\n", r * 4);

    return 0;
}