#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

const int N = 200010;
const int sN = 450;

ll Fb[N];
ll Fa[N];
ll A[N];
ll a, b, kk, n;

void actu(ll *F, int idx, ll ma, ll val) {
    while (idx < ma) {
        F[idx] += val;
        idx += idx&(-idx);
    }
}

ll que(ll *F, int idx) {
    ll val = 0;
    while (idx > 0) {
        val += F[idx];
        idx -= idx&(-idx);
    }
    return val;
}

void quer() {
    ll idx, d;
    cin >> idx >> d;
    if (A[idx] + d > b) {
        ll tt = max(b - A[idx], 0ll);
        actu(Fb, idx, N, tt);
    }
    else actu(Fb, idx, N, d);
    if (A[idx] + d > a) {
        ll tt = max(a - A[idx], 0ll);
        actu(Fa, idx, N, tt);
    }
    else actu(Fa, idx, N, d);
    A[idx] += d;
}

ll resp() {
    ll idx;
    cin >> idx;
    ll res =  que(Fb, idx - 1) + que(Fa, N - 1) - que(Fa, idx + kk - 1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> kk >> a >> b;
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) quer();
        else cout << resp() << endl;
    }
}