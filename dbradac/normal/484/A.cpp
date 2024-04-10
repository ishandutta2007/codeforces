#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int Pcount(ll x)
{
    int r=0;
    ll i;

    for (i=0; i<63; i++)
        if ((1ll << i) & x)
            r++;
    return r;
}

int main()
{
    int n;
    ll l, r, i, rje, tl, tr;

    scanf("%d", &n);

    for (; n; n--) {
        scanf("%I64d%I64d", &l, &r);
        for (i=62, rje=0; i>=0; i--) {
            tl = l & (1ll << i);
            tr = r & (1ll << i);
            if (tl != tr) {
                rje += tr - 1;
                break;
            }
            rje += tl;
        }
        if (Pcount(r) > Pcount(rje))
            rje = r;
        printf("%I64d\n", rje);
    }

    return 0;
}