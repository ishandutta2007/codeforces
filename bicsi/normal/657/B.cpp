#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD, INV2;

vector<ll> Primes = {
    485753385234779LL,
    1060631538332581LL
};
ll P[500000];
int Ans[500000];

void add(ll &a, ll b) {
    a += b;
    if(a >= MOD) a -= MOD;
}
void sub(ll &a, ll b) {
    a -= b;
    if(a < 0) a += MOD;
}
void inm(ll &a, ll b) {
    ll r = 0;
    while(b) {
        if(b % 2) add(r, a);
        add(a, a);
        b /= 2;
    }
    a = r;
}

int main() {

    int n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; ++i) {
        cin >> P[i];
    }

    for(auto x : Primes) {

        ll r = 0;
        MOD = x;
        INV2 = x + 1 >> 1;

        for(int i = n; i >= 0; --i) {
            add(r, r);
            add(r, P[i] >= 0 ? P[i] : P[i] + MOD);
        }

        int ans = 0;

        ll pw = 1, inv = 1;
        for(int i = 0; i <= n; ++i) {
            ll prod = r;
            inm(prod, inv);
            ll coef = P[i];
            sub(coef, prod);

            if(coef == 0 && i == n) break;
            if(coef <= k || coef >= MOD - k) {
                Ans[i] += 1;
            }

            add(pw, pw);
            inm(inv, INV2);
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; ++i)
        ans += (Ans[i] == Primes.size());
    cout << ans;
    return 0;
}