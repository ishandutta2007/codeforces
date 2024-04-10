#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back


ll n;
ll qr(ll l, ll r) {
    assert(l < r && l >= 1 && r <= n);
    cout << "? " << l << " " << r << endl;
    ll res;
    cin >> res;
    return res;
}

void ans(ll x) {
    assert(x >= 1 && x <= n);
    cout << "! " << x << endl;
    exit(0);
}

int main() {
    cin >> n;
    ll snd = qr(1, n);
    ll l, r;
    if (snd == 1) l = 2, r = n;
    else if (snd == n) l = 1, r = n - 1;
    else {
        ll tmp = qr(1, snd);
        if (tmp == snd) l = 1, r = snd - 1;
        else l = snd + 1, r = n;
    }
    while (l != r) {
        ll h = (l + r) / 2, x;
        if (h < snd) {
            x = qr(h + 1, snd);
            if (x == snd) l = h + 1;
            else r = h;
        } else {
            x = qr(snd, h);
            if (x == snd) r = h;
            else l = h + 1;
        }
    }
    ans(l);
     
}