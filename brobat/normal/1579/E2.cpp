#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int func(int a, int b) {
    return a + b;
}

int query(vector<int> &st, int v, int tl, int tr, int l, int r) {
    if(l > r) return 0; // Return appropriate value, for example INF for find_min.
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return func(query(st, v*2, tl, tm, l, min(r, tm)), query(st, v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

void update(vector<int> &st, int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val; // Assign value here.
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(st, v*2, tl, tm, pos, new_val);
        else update(st, v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = func(st[v*2], st[v*2 + 1]);
    }
}

int funcG(int a, int b) {
    return a + b;
}

int queryG(vector<int> &st, int v, int tl, int tr, int l, int r) {
    if(l > r) return 0; // Return appropriate value, for example INF for find_min.
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return funcG(queryG(st, v*2, tl, tm, l, min(r, tm)), queryG(st, v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

void updateG(vector<int> &st, int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val; // Assign value here.
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) updateG(st, v*2, tl, tm, pos, new_val);
        else updateG(st, v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = funcG(st[v*2], st[v*2 + 1]);
    }
}

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

bool compG(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector <int> v(n), st(4*n, 0);
    vector <pair<int, int>> c(n);
    forn(i, 0, n) {
        cin >> v[i];
        c[i] = {v[i], i};
    }
    sort(c.begin(), c.end(), comp);
    vector <int> g(n);
    forn(i, 0, n) {
        int ind = c[i].second;
        g[ind] = query(st, 1, 0, n-1, 0, ind);
        update(st, 1, 0, n-1, ind, 1);
    }
    vector <int> stG(4*n, 0);
    vector <int> gG(n);
    sort(c.begin(), c.end(), compG);
    forn(i, 0, n) {
        int ind = c[i].second;
        // cout << ind << " ";
        gG[ind] = queryG(stG, 1, 0, n-1, 0, ind);
        updateG(stG, 1, 0, n-1, ind, 1);
    }
    // forn(i, 0, n) cout << gG[i] << " ";
    // cout << endl;
    forn(i, 0, n) ans += min(g[i], gG[i]);
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}