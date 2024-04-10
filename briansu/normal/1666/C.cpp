#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

vector<pair<pii, pii>> ans;

void add(int x1, int y1, int x2, int y2) {
    pii p1 = {x1, y1};
    pii p2 = {x2, y2};
    if (p1 == p2)
        return;
    assert(x1 == x2 || y1 == y2);
    ans.pb({p1, p2});
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<pii> v;
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        v.pb({a, b});
    }
    sort(ALL(v));
    int mnx = v[0].X, mxx = v[0].X, mny = v[0].Y, mxy = v[0].Y;
    for (auto &[x, y] : v)
        mnx = min(mnx, x), mxx = max(mxx, x), mny = min(mny, y), mxy = max(mxy, y);
    add(v[1].X, mny, v[1].X, mxy);
    add(v[0].X, v[0].Y, v[1].X, v[0].Y);
    add(v[2].X, v[2].Y, v[1].X, v[2].Y);
    cout << SZ(ans) << "\n";
    for (auto &[p1, p2] : ans)
        cout << p1.X << " " << p1.Y << " " << p2.X << " " << p2.Y << "\n";
     
}