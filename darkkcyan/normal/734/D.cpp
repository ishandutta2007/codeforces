#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
#define vi ve<int>
#define ii pair<int, int>

int n;
int kx, ky;
ve<bool> op[4];

void add(int u, int v) {
    if (u == 0) op[0][v > 0] = true;
    if (v == 0) op[1][u > 0] = true;
    if (u == v) op[2][u > 0] = true;
    if (u == -v) op[3][u > 0] = true;
}

bool checkr(int u, int v) {
    if (u == 0 and !op[0][v > 0]) return true;
    if (v == 0 and !op[1][u > 0]) return true;
    return false;
}

bool checkb(int u, int v) {
    if (u == v and !op[2][u > 0]) return true;
    if (u == -v and !op[3][u > 0]) return true;
    return false;
}

#define ll pair<long, long>
#define iii pair<ll, int>
ve<iii> a;

bool cmp(const iii& a, const iii& b) {
    return abs(a.xx.xx) + abs(a.xx.yy) < abs(b.xx.xx) + abs(b.xx.yy);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> kx >> ky;
    for (int i = 0; i < 4; ++i) op[i].resize(2);
    for (int i = 0; i < n; ++i) {
        char ch;
        long u, v; cin >> ws >> ch >> u >> v;
        u -= kx, v -= ky;
        a.push_back(iii(ii(u, v), ch));
    }
    sort(a.bb, a.ee, cmp);
    for (int i = 0; i < n; ++i) {
        long u = a[i].xx.xx, v = a[i].xx.yy, ch = a[i].yy;
        if (ch == 'B' and checkb(u, v)) cout << "YES", exit(0);
        else if (ch == 'R' and checkr(u, v)) cout << "YES", exit(0);
        else if (ch == 'Q' and (checkb(u, v) or checkr(u, v))) cout << "YES", exit(0);
        add(u, v);
    }
    cout << "NO";


    return 0;
}