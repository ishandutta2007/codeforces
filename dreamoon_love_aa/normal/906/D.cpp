#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

#define N 100000
using ll = long long;

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

bool flag;

ll pow(ll a, ll b, ll m) {
    if(!b) {
        return 1;
    }
    if(b & 1) {
        ll result = pow(a, b - 1, m);
        flag |= a * result >= m;
        return a * result % m;
    }
    ll result = pow(a, b >> 1, m);
    flag |= result * result >= m;
    return result * result % m;
}

int a[N], mod_num[N];
double lg[N];

void solve() {
    int n, k = 1;
    cin >> n >> mod_num[0];
    lg[0] = log2(mod_num[0]);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while(mod_num[k - 1] > 1) {
        mod_num[k] = phi(mod_num[k - 1]);
        lg[k] = log2(mod_num[k]);
        k++;
    }
    int q, l, r;
    ll result;
    cin >> q;
    while(q--) {
        cin >> l >> r;
        l--, r--;
        result = 1;
        flag = 0;
        for(int i = min(r, k - 1 + l); i >= l; i--) {
            flag |= i - l + 1 < k && result >= lg[i - l];
            if(a[i] == 1) {
                flag = 0;
            }
            if(flag) {
                result += mod_num[i - l + 1];
            }
            result = pow(a[i], result, mod_num[i - l]);
        }
        cout << result << '\n';
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}