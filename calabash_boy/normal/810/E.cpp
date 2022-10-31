#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MODD = 1e9 + 7;
int q;
ll a, b, u, v, k;

ll calc(ll u, ll v, ll k, ll o = 0) {
    if (u > v) swap(u, v);
    if (u < 1 || k <= 0) return 0;

    ll p = 1, res = 0;
    while (p*2LL <= v) p *= 2LL;

    ll tmp = min(p, k);

    if (u <= p) {
        res = (tmp*(tmp+1)/2 % MODD) * u % MODD;
        res += (o * tmp % MODD) * u % MODD + calc(u, v-p, k-p, o+p);
        res %= MODD;
    } else {
        res = (tmp*(tmp+1)/2 % MODD) * p % MODD;
        res += (o * tmp % MODD) * p % MODD;
        res += calc(u-p, v-p, k, o)+calc(p, v-p, k-p, o+p)+calc(u-p, p, k-p, o+p);
    }

    return res;
}

int main() {
    scanf("%d", &q);

    while (q --> 0) {
        scanf("%I64d %I64d %I64d %I64d %I64d", &a, &b, &u, &v, &k);

        ll res = (calc(u,v,k) + calc(a-1,b-1,k)) % MODD;
        res = (res - calc(a-1,v,k) - calc(u,b-1,k) + MODD*MODD) % MODD;
        printf("%lld\n", res);
    }
    return 0;
}