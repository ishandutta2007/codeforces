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

const int MAXn = 3005;
vector<int> v[MAXn];
int u[MAXn], p[MAXn];

vector<int> dt;

ll qr(int x) {
    assert(x < SZ(dt) && x >= 1);
    cout << "? " << x + 1;
    for (int i = 0; i <= x; i++)
        cout << " " << dt[i];
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    queue<int> q;
    q.push(1);
    u[1] = 1;
    while (SZ(q)) {
        ll t = q.front(); q.pop();
        dt.pb(t);
        for (ll k : v[t])
            if (!u[k])
                u[k] = 1, q.push(k), p[k] = t;
    }
    int goal = qr(SZ(dt) - 1);

    int l = 0, r = SZ(dt);
    while (l != r - 1) {
        ll h = (l + r) / 2;
        if (qr(h) == goal)
            r = h;
        else
            l = h;
    }
    cout << "! " << dt[r] << " " << p[dt[r]] << endl;
}