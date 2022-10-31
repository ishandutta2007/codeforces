#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    int r=0, i;

    scanf("%I64d", &n);

    for (i=1;; i++) {
        if (3 * (ll) i * (i+1) / 2 - i > n)
            break;
        if (!((n + i) % 3))
            r++;
    }

    printf("%d\n", r);

    return 0;
}