#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>
#include <chrono>
#include <random>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1000 * 1000 + 228;

ll q1 = -1;
ll q2 = -1;
ll p1 = -1;
ll p2 = -1;

bool is_prime(ll x) {
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }

    for (ll i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// YA EBAL VAS PIDORI
void gen_fuck(ll &q, ll &p) {
    ll st = 1000 * 1000 * 1000;
    ll to_add = 1000 * 1000 * 100;

    p = st + rng() % to_add;
    while (!is_prime(p)) {
        p = st + rng() % to_add;
    }

    st -= to_add;

    q = st + rng() % to_add;
    while (q == p || !is_prime(q)) {
        q = st + rng() % to_add;
    }
}

int n, m;
char st[MAX_N];
char gg[MAX_N];
ll hs1[MAX_N];
ll hs2[MAX_N];
ll pw1[MAX_N];
ll pw2[MAX_N];

ll get(int l, int r, ll hs[], ll pw[], ll p) {
    ll ans = (hs[r] - hs[l - 1] * pw[r - l + 1]) % p;
    if (ans < 0) ans += p;
    return ans;
}

pair<ll, ll> get(int l, int r) {
    return {get(l, r, hs1, pw1, p1), get(l, r, hs2, pw2, p2)};
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    gen_fuck(q1, p1);
    gen_fuck(q2, p2);

    scanf("%s", st);
    scanf("%s", gg);

    m = strlen(st);
    n = strlen(gg);

    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw1[i] = pw1[i - 1] * q1 % p1;
        pw2[i] = pw2[i - 1] * q2 % p2;
        hs1[i] = (hs1[i - 1] * q1 + gg[i - 1]) % p1;
        hs2[i] = (hs2[i - 1] * q2 + gg[i - 1]) % p2;
    }

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < m; ++i) {
        cnt0 += (st[i] == '0');
        cnt1 += (st[i] == '1');
    }

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ll other = n - i * cnt0;
        if (other < 0 || other % cnt1 != 0) {
            continue;
        }
        ll j = other / cnt1;
        if (j <= 0) {
            continue;
        }

        int ptr = 1;
        pair<ll, ll> on_fr;
        pair<ll, ll> on_sc;
        bool fr_fr = true;
        bool fr_sc = true;
        bool ok = true;
        for (int k = 0; k < m && ok; ++k) {
            if (st[k] == '0') {
                pair<ll, ll> cur = get(ptr, ptr + i - 1);
                if (fr_fr) {
                    fr_fr = false;
                    on_fr = cur;
                }
                if (cur != on_fr) {
                    ok = false;
                    break;
                }
                ptr += i;
            } else {
                pair<ll, ll> cur = get(ptr, ptr + j - 1);
                if (fr_sc) {
                    fr_sc = false;
                    on_sc = cur;
                }
                if (cur != on_sc) {
                    ok = false;
                    break;
                }
                ptr += j;
            }
        }

        if (ok && on_fr != on_sc) {
            ++ans;
        }
    }

    printf("%lld\n", ans);

    return 0;
}