#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define lim numeric_limits
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()

int n, m, k;
ve<vi> a;
void read() {
    cin >> n >> m >> k;
    a.resize(n + 2, vi(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int f = 1; f <= m; ++f) {
            char ch; cin >> ws >> ch;
            if (ch == '.') a[i][f] = 1;
            else a[i][f] = 0;
        }
    }
    for (int i = 0; i <= n + 1; ++i) a[i][0] = a[i][m + 1] = 1;
    for (int f = 0; f <= m + 1; ++f) a[0][f] = a[n + 1][f] = 1;
}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};
ve<ii> cnt;
void floodfill(int r, int c, int oid, int nid) {
    if (r < 0 or r >= n + 2 or c < 0 or c >= m + 2) return;
    if (a[r][c] != oid) return;
    ++cnt[nid].xx;
    a[r][c] = nid;
    for (int i = 0; i < 4; ++i) {
        floodfill(r + dr[i], c + dc[i], oid, nid);
    }
}

set<int> fillset;
long ans = 0;
void process() {
    cnt.resize(3, ii(lim<int>::max(), 0));
    cnt.back().yy = 2;
    floodfill(0, 0, 1, 2);
    for (int i = 1; i <= n; ++i) {
        for (int f = 1; f <= m; ++f) {
            if (a[i][f] != 1) continue;
            cnt.push_back(ii(0, cnt.size()));
            floodfill(i, f, 1, cnt.size() - 1);
        }
    }
    sort(cnt.bb + 3, cnt.ee);
    for (int i = 3; k < sz(cnt) - i; ++i) {
        ans += cnt[i].xx;
        fillset.insert(cnt[i].yy);
    }
}

void print() {
    for (int i = 1; i <= n; ++i) {
        for (int f = 1; f <= m; ++f) {
            if (a[i][f] == 0) cout << '*';
            else if (fillset.count(a[i][f])) cout << '*';
            else cout << '.';
        }
        cout << '\n';
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0); cin.tie(0);
    read();
    process();
    cout << ans << '\n';
    print();

    return 0;
}