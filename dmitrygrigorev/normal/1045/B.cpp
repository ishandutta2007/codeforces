#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll Q = 1e9 + 5;
const ll P = 1e9 + 7;

vector <ll> manaker(vector <ll> &a) {
    int n = a.size();
    vector <ll> res(n, 0);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; i++) {
        if (i <= r) {
            res[i] = min(res[r + l - i], r - i);
        }
        while (i - res[i] - 1 >= 0 && i + res[i] + 1 < n && a[i - res[i] - 1] == a[i + res[i] + 1]) {
            res[i]++;
        }
        if (i + res[i] > r) {
            l = i - res[i];
            r = i + res[i];
        }
    }
    return res;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, m;
    cin >> n >> m;
    ll sum = 0;
    vector <ll> t;
    ll pr;
    cin >> pr;
    vector <ll> a(n);
    a[0] = pr;
    for (ll i = 1; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = x;
        t.push_back(x - pr);
        if (i != n - 1) {
            t.push_back(-1);
        }
        pr = x;
    }
    vector <ll> res;
    auto man = manaker(t);
    for (ll i = 0; i < n; i++) {
        ll x = (a[i] + a[0]) % m;
        if (i != n - 1 && a[i + 1] + a[n - 1] != m + x) {
            continue;
        }
        //cout << i + n - 1 << " " << man[i + n - 1] << "\n";
        if ((2 * i - 2 < 0 || man[i - 1] == i - 1) && (2 * i + 2 > 2 * n - 4 || man[i + n - 1] == n - i - 3)) {
            res.push_back(x);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (ll x : res) {
        cout << x << " ";
    }
}