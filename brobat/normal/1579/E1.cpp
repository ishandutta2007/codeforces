#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

pair<int, int> func(pair<int, int> a, pair<int, int> b) {
    if(a.first < b.first) return a;
    return b;
}

pair<int, int> query(vector<pair<int, int>> &st, int v, int tl, int tr, int l, int r) {
    if(l > r) return {MOD, -1}; // Return appropriate value, for example INF for find_min.
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return func(query(st, v*2, tl, tm, l, min(r, tm)), query(st, v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

void update(vector<pair<int, int>> &st, int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = {new_val, tl}; // Assign value here.
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(st, v*2, tl, tm, pos, new_val);
        else update(st, v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = func(st[v*2], st[v*2 + 1]);
    }
}

void solve() {
    int n; cin >> n;
    vector <int> v(n);
    vector <pair<int, int>> st(4*n, {MOD, -1});
    map<int, bool> done;
    queue <int> q;
    forn(i, 0, n) {
        cin >> v[i];
        update(st, 1, 0, n-1, i, v[i]);
    }
    int curr_final = n - 1;
    while(curr_final > 0) {
        auto x = query(st, 1, 0, n - 1, 0, curr_final);
        q.push(x.first);
        done[x.first] = true;
        curr_final = x.second - 1;
    }
    forn(i, 0, n) {
        if(!done[v[i]]) q.push(v[i]);
    }
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
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