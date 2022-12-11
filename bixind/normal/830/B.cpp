#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>


using namespace std;

typedef long long ll;

const long long inf = 2000000000000000000;

ll tr[400100];
ll pos[400100];

void upd(int v, int p, ll x, int l1, int r1) {
    if (l1 > p || r1 < p)
        return;
    if (l1 == r1) {
        tr[v] = x;
        pos[v] = p;
        return;
    }
    int mid = (l1 + r1) / 2;
    upd(2*v, p, x, l1, mid);
    upd(2*v + 1, p, x, mid + 1, r1);
    if (tr[2 * v] <= tr[2 * v + 1])
    {
        tr[v] = tr[2 * v];
        pos[v] = pos[2 * v];
    } else {
        tr[v] = tr[2 * v + 1];
        pos[v] = pos[2 * v + 1];
    }
}

pair<int, ll> find(int v, int l, int r, int l1, int r1) {
    if (l1 > r || r1 < l) {
        return {-1, inf};
    }
    if (l <= l1 && r1 <= r) {
        return {pos[v], tr[v]};
    }
    int mid = (l1 + r1) / 2;
    auto p1 = find(v * 2, l, r, l1, mid);
    auto p2 = find(v * 2 + 1, l, r, mid + 1, r1);
    if (p1.second <= p2.second) {
        return p1;
    } else {
        return p2;
    }
}



void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (ll i = 0; i < n; ++i) {
        upd(1, i, v[i], 0, n - 1);
    }
    ll ans = 0;
    ll cnt = n;
    ll str = 0;
    int prv = -1;
    for (int i = 0; i < n; ++i) {
        auto p = find(1, prv + 1, n - 1, 0, n - 1);
        auto p1 = find(1, 0, n - 1, 0, n - 1);
        if (p.first == -1 || p1.second < p.second) {
            ans += cnt;
            cnt -= str;
            str = 0;
            p = p1;
        }
        prv = p.first;
        //cout << p.first << ' ' << p.second << endl;
        ++str;
        upd(1, prv, inf, 0, n - 1);
    }
    ans += cnt;
    cout << ans << endl;
}


int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}