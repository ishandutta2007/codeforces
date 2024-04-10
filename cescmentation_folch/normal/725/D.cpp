#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<ll> vll;

bool comp(pi a, pi b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vpi V(n - 1);
    pi L;
    cin >> L.first >> L.second;
    for (ll i = 0; i < n - 1; ++i) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end(), comp);
    ll res = n;
    ll i = 0;
    priority_queue<ll> Q;
    while (res > 1) {
        while (i < n - 1 and V[i].first > L.first) {
            Q.push(-(V[i].second - V[i].first + 1));
            ++i;
        }
        res = min((ll)Q.size() + 1, res);
        if ((ll)Q.size() == 0) break;
        ll k = -Q.top();
//        cerr << k << '\n';
        if (k <= L.first) {
            Q.pop();
            L.first -= k;
        }
        else break;
    }
    cout << res << '\n';
}