#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

struct S {
    int a, b, c, q;
    bool operator <(const S & x) const {
        return q > x.q;
    }
};

int query(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    int x; cin >> x;
    return x;
}

pair<int, int> find(int a, int b, int c, int d) {
    // Find which two to choose from a, b, c, d.
    vector<S> v;
    int x;
    x = query(a, b, c);
    v.push_back({a, b, c, x});
    x = query(a, b, d);
    v.push_back({a, b, d, x});
    x = query(a, c, d);
    v.push_back({a, c, d, x});
    x = query(b, c, d);
    v.push_back({b, c, d, x});
    sort(v.begin(), v.end());
    map<int, int> occ;
    forn(i, 0, 2) {
        occ[v[i].a]++; occ[v[i].b]++; occ[v[i].c]++;
    }
    vector <int> ans;
    for(auto i : occ) {
        if(i.second == 2) ans.push_back(i.first);
    }
    return {ans[0], ans[1]};
}


void solve() {
    int n;
    cin >> n;
    pair<int, int> f = find(1, 2, 3, 4);
    for(int i = 5; i < n; i += 2) {
        f = find(f.first, f.second, i, i + 1);
    }
    if(n % 2 == 0) {
        cout << "! " << f.first << " " << f.second << endl;
    } else {
        int dummy = -1;
        for(int i = 1; i <= n; i++) {
            if(i != f.first && i != f.second) {
                dummy = i;
                break;
            }
        }
        f = find(f.first, f.second, dummy, n);
        cout << "! " << f.first << " " << f.second << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}