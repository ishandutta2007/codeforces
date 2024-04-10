#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector<int> parent;

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(d!=c) parent[d] = c;
}

void solve() {
    int n;
    cin >> n;
    parent.resize(n);
    vector<pair<int, int>> v(n);
    forn(i, 0, n) {
        cin >> v[i].first;
        v[i].second = i;
        parent[i] = i;
    }
    sort(v.begin(), v.end());
    int left = 0;
    int right = v[0].second;
    for(int i = 0; i < n; i++) {
        // cout << i << " " << v[i].second << " " << left << " " << right << endl;
        if(v[i].second > right && i > right) {
            // cout << "New component" << endl;
            for(int j = left; j < right; j++) {
                // cout << "Uniting " << j << " " << j + 1 << endl;
                unite(j, j + 1);
            }
            left = i;
            right = v[i].second;
        }
        right = max(right, v[i].second);
    }
    for(int j = left; j < right; j++) {
        unite(j, j + 1);
    }
    set <int> s;
    for(int i = 0; i < n; i++) {
        s.insert(find(i));
        // cerr << find(i) << " ";
    }
    cout << (int)s.size() << endl;
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