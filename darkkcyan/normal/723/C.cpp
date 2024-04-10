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

int n, m;
vi a;
void read() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
}

int ans, ec;
ve<ii> cnt;
set<ii> se;

int nxt() {
    if (ec) {
        --ec;
        return find_if(a.bb, a.ee, [](int t) {return t >= m;}) - a.bb;
    }
    ii t = *(--se.ee);
    se.erase(t);
    t.xx--;
    se.insert(t);
    return find(a.bb, a.ee, t.yy) - a.bb;
}

void process() {
    cnt.resize(m);
    ec = 0;
    for (int i = 0; i < m; ++i) cnt[i].yy = i;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= m) ++ec;
        else cnt[a[i]].xx ++;
    }
    se = set<ii>(cnt.bb, cnt.ee);
    int u = n / m;
    while (se.bb->xx < u) {
        ii t = *(se.bb);
        se.erase(se.bb);
        t.xx ++;
        se.insert(t);
        a[nxt()] = t.yy;
        ++ans;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    read();
    process();
    cout << (n / m) << ' ' << ans << endl;
    for (int i = 0; i < n; ++i) cout << a[i] + 1<< ' ';

    return 0;
}