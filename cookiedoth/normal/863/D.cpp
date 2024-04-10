#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

struct query {
    ll l, r, t;
};

const ll mx = 500000;
ll n, qn, m, a[mx], b[mx];
vector<query> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> qn >> m;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    q.resize(qn);
    for (ll i = 0; i < qn; ++i) {
        cin >> q[i].t >> q[i].l >> q[i].r;
        q[i].l -= 1;
        q[i].r -= 1;
    }
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
        b[i] -= 1;
    }
    for (ll i = qn - 1; i >= 0; --i) {
        for (ll j = 0; j < m; ++j) {
            if (q[i].t == 1) {
                if (b[j] == q[i].l)
                    b[j] = q[i].r;
                else {
                    if (q[i].l < b[j] && b[j] <= q[i].r)
                        b[j] -= 1;
                }
            }
            else {
                if (q[i].l <= b[j] && b[j] <= q[i].r) {
                    b[j] = q[i].r - (b[j] - q[i].l);
                }
            }
        }
    }
    for (ll i = 0; i < m; ++i) {
        cout << a[b[i]] << " ";
    }
    return 0;
}