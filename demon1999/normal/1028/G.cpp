#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;
const int mod = int(1e9) + 7;
const ll maxk = 10000LL;
ll r = 10004205361450474LL;
int n;
map<pair<pair<ll, ll>, ll>, vector<ll> > cp;

ll count_cnt(ll p) {
    ll c = maxk, cnt = 1;
    while (c < p) {
        cnt++;
        if ((p - maxk) / c < maxk + 1)
            return c;
        c = maxk + c * (maxk + 1LL);
    }
    return cnt;
}

ll get_cnt(ll u) {
    ll ans = maxk;
    for (int i = 2; i <= u; i++) {
        ans = maxk + ans * (maxk + 1LL);
    }
    return ans;
}

bool solve(ll l, ll r, ll k) {
    if (l > r) return true;
    if (r - l + 1 <= min(l, maxk)) {
        return true;
    }
    if (k == 1) {
        return false;
    }
    if (cp.find(mp(mp(l, r), k)) != cp.end()) {
        return true;        
    }
    if (l >= maxk && count_cnt(r - l + 1) > k) {
        return false;
    }
    ll cc = get_cnt(k - 1);
    ll nr = r; 
    vector<ll> q;
    while (nr - cc + 1 >= maxk) {
        q.push_back(nr - cc);
        nr -= cc;
        nr--;
    }
    if (sz(q) > l) return false;
    ll nl = l;
    ll pppp = sz(q);
    forn (i, l - pppp) {
        ll ql = nl, qr = min(r + 1, maxk + 1);
        while (qr - ql > 1) {
            ll mid = (ql + qr) / 2;
            if (solve(nl, mid - 1, k - 1)) {
                ql = mid;
            } else
                qr = mid;
        }
        q.push_back(ql);
        nl = ql + 1;
    }
    if (!solve(nl, nr, k - 1)) return false;
    cp[mp(mp(l, r), k)] = q;
    return true;
}  
void okk(ll l, ll r, ll k);

void ask(ll l, ll r, ll k, vector<ll> q) {
    sort(q.begin(), q.end());
    cout << sz(q) << endl;
    forn (i, sz(q))
        cout << q[i] << " ";
    cout << endl;
    int p;
    cin >> p;
    if (p == -1) {
        exit(0);
    }
    if (p == -2) {
        assert(0);
    }
    if (p == 0) okk(l, q[p] - 1, k - 1);
    else
    if (p == sz(q)) okk(q[sz(q) - 1] + 1, r, k - 1);
    else
        okk(q[p - 1] + 1, q[p] - 1, k - 1);
}

void okk(ll l, ll r, ll k) {
    if (l > r) return;
    if (r - l + 1 <= min(l, maxk)) {
        cout << r - l + 1 << endl;
        for (ll i = l; i <= r; i++) cout << i << " ";
            cout << endl;
        return;
    }
    if (l >= maxk && count_cnt(r - l + 1) > k) {
        cout << l << " " << (r - l + 1) << " " << count_cnt(r - l + 1) << "\n";
        cout << "khe\n";
        exit(0);
        assert(0);
    }
    if (l >= maxk) {
        ll c = get_cnt(k - 1);
        vector<ll> q;
        ll sm = l + c;
        while (sm <= r) {
            q.push_back(sm);
            sm += c + 1;
        }
        ask(l, r, k, q);  
        return;
    }
    
    auto q = cp[mp(mp(l, r), k)];
    ask(l, r, k, q);
}

int main() {
    //iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //cout << solve(2047,  - get_cnt(4) - 1, ) << "\n";
    solve(1, r, 5);
    okk(1, r, 5);
    return 0;
}