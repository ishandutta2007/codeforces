/**
 *
 * With Love from New York
 *
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 4000 + 7;

struct kid {
        ll vol;
        ll dep;
        ll put;
        ll id;
};

ll n;
kid a[N];

/**void print() {
        cout << "Printing : \n";
        for (ll i = 1; i <= n; i++) {
                cout << a[i].put << " ";
        }
        cout << "\n";
} **/

void cause2(ll i) {
        for (ll j = i + 1; j <= n; j++) {
                a[j].put -= a[i].dep;
        }
        for (ll j = i; j < n; j++) {
                a[j] = a[j + 1];
        }
        n--;
        while (1) {
                bool g = 0;
                for (ll j = 1; j <= n; j++) {
                        if (a[j].put < 0) {
                                cause2(j);
                                g = 1;
                                break;
                        }
                }
                if (g == 0) {
                        break;
                }
        }
}

vector <ll> res;
void cause1() {
        res.push_back(a[1].id);
        ll vol = a[1].vol;
        for (ll i = 1; i < n; i++) {
                a[i] = a[i + 1];
                if (vol >= 0) {
                        a[i].put -= vol;
                }
                vol--;
        }
        n--;
        while (1) {
                bool g = 0;
                for (ll j = 1; j <= n; j++) {
                        if (a[j].put < 0) {
                                cause2(j);
                                g = 1;
                                break;
                        }
                }
                if (g == 0) {
                        break;
                }
        }
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n;
        for (ll i = 1; i <= n; i++) {
                cin >> a[i].vol >> a[i].dep >> a[i].put;
                a[i].id = i;
        }
        while (n > 0) {
                cause1();
        }
        cout << (ll) res.size() << "\n";
        for (auto &it : res) {
                cout << it << " ";
        }
        cout << "\n";
}
/**

**/