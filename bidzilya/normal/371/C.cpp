#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

typedef unsigned long long ll;

string s;
ll nb, ns, nc;
ll cb, cs, cc;
ll pb, ps, pc;
ll r;

bool may(ll cnt) {
    ll cost = 0;
    if (cnt * cb > nb) {
        cost += pb * (cnt * cb - nb);
    } 
    if (cnt * cs > ns) {
        cost += ps * (cnt * cs - ns);
    }
    if (cnt * cc > nc) {
        cost += pc * (cnt * cc - nc);
    }
    return cost <= r;
}

int main() {
    cin >> s;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    cb = cs = cc = 0;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == 'B')
            ++cb;
        else if (s[i] == 'S')
            ++cs;
        else
            ++cc;
    ll ans = 0;
    ll ans_l = 1, ans_r = 1e14;
    while (ans_l <= ans_r) {
        ll ans_m = (ans_l + ans_r) >> 1;
        if (may(ans_m)) {
            ans = ans_m;
            ans_l = ans_m + 1;
        } else {
            ans_r = ans_m - 1;
        }
    }
    cout << ans << endl;
    return 0;
}