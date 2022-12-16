#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int TT;

int od = 1;
struct person {
    ll l, r, i;
    person() {}
    person(int a, int b, int c) : l(a), r(b), i(c) {}
    bool operator < (const person& o) const {
        if (l == o.l && r == o.r) return false;
        if (od == 1) {
            return (l == o.l ? r < o.r : l < o.l);
        } else {
            return (r == o.r ? l < o.l : r < o.r);
        }
    }
    bool operator > (const person& o) const {
        if (l == o.l && r == o.r) return false;
        if (od == 1) {
            return (l == o.l ? r > o.r : l > o.l);
        } else {
            return (r == o.r ? l > o.l : r > o.r);
        }
    }
};

vector<person> by_right;
vector<person> by_left;
ll n, s; 

int8_t used[200200];

bool check(ll g) {
    od = 1;
    memset(used, 0, n);
    priority_queue<person> pq;
    for (int i=n-1; i >=0 && by_right[i].r >= g; --i) {
        pq.push(by_right[i]);
    }
    if (pq.size() < (n+1)/2) return false;

    ll so_far = 0;
    for (int i=0; i<(n+1)/2; ++i) {
        //cerr << " " << i << " vs " << (n+1)/2 << endl;
        person p = pq.top(); pq.pop();
        so_far += max(g, p.l);
        used[p.i] = 1;
        //cerr << " top " << p.i << endl;
    }
    for (int i=0; i<n; ++i) {
        if (!used[by_right[i].i]) {
            so_far += by_right[i].l;
            //cerr << " bot " << by_right[i].i << endl;
        }
    }
    return so_far <= s;
}

ll solve() {
    by_right = vector<person>();
    cin >> n >> s;
    for (int i=0; i<n; ++i) {
        ll l, r;
        cin >> l >> r;
        by_right.emplace_back(l, r, i);
    }
    od = 0;
    sort(by_right.begin(), by_right.end());
    ll lo = 0, hi = 1e14;
    while (lo < hi) {
        ll m = (lo+hi)/2;
        if (check(m)) {
            lo = m+1;
        } else {
            hi = m;
        }
    }
    return lo-1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> TT;
    for (int tt=1; tt<=TT; ++tt) {
        cout << solve() << "\n";
    }
    return 0;
}