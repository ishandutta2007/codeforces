#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

struct cosa {
    ll t;
    ll d;
    ll idx;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, b;
    cin >> n >> b;
    queue<cosa> Q;
    ll f = 0;
    ll next = 0;
    vi Res(n, -1);
    
    for (ll i = 0; i < n; ++i) {
        cosa tt;
        cin >> tt.t >> tt.d;
        tt.idx = i;
        if (Q.size() > 0 and next <= tt.t) {
            Res[Q.front().idx] = max(Q.front().t, next) + Q.front().d;
            next = Res[Q.front().idx];
            Q.pop();
        }
//         cerr << Q.size() << endl;
        if (Q.size() < b) Q.push(tt);
    }
    while (Q.size() > 0) {
        Res[Q.front().idx] = max(Q.front().t, next) + Q.front().d;
        next = Res[Q.front().idx];
        Q.pop();
    }
    for (ll i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << Res[i];
    }
    cout << endl;
}