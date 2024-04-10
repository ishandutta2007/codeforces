#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, m;

ll BrManjJed(ll br)
{
    int i;
    ll r=0;

    for (i=1; i<=n; i++)
        r += min(br / i, (ll) m);

    return r;
}

int main()
{
    ll lo, mid, hi, k;

    scanf("%d%d%I64d", &n, &m, &k);

    for (lo=1, hi=(ll)n*m; lo<hi; ) {
        mid = (lo + hi) / 2;
        if (BrManjJed(mid) < k)
            lo = mid + 1;
        else
            hi = mid;
    }

    printf("%I64d\n", lo);

    return 0;
}