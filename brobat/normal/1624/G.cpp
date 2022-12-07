#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

struct Edge {
    int x, y, w;
    bool operator <(const Edge& b) const {
        if(w == b.w) {
            if(x == b.x) return y < b.y;
            return x < b.x;
        }
        return w < b.w;
    }
};

int n, m;
set <Edge> e;
int ans[30];

vector<int> parent, sz;

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(d!=c) {
        if(sz[d] > sz[c]) {
            swap(c, d);
        }
        parent[d] = c;
        sz[c] += sz[d];
    }
}

bool connected() {
    parent.resize(n);
    forn(i, 0, n) parent[i] = i;
    sz.resize(n, 1);
    for(auto edge : e) {
        unite(edge.x, edge.y);
    }
    int p = find(0);
    forn(i, 1, n) {
        if(p != find(i)) return false;
    }
    return true;
}

void pre() {
    cin >> n >> m;
    e.clear();
    forn(i, 0, 30) ans[i] = 1;
    forn(i, 0, m) {
        Edge t;
        cin >> t.x >> t.y >> t.w;
        t.x--; t.y--;
        e.insert(t);
    }

}

void solve() {
    pre();
    for(int i = 29; i >= 0; i--) {
        // Check if the i^th bit can be made 0 or not.
        vector <Edge> rem;
        set <Edge>::iterator it;
        for(auto edge : e) {
            if((edge.w|(1<<i)) == edge.w) {
                rem.push_back(edge);
            }
        }
        for(auto r : rem) e.erase(r);
        if(connected()) {
            ans[i] = 0;
        }
        else {
            for(auto r : rem) e.insert(r);
        }
    }
    int f = 0;
    forn(i, 0, 30) f += (ans[i] << i);
    cout << f << endl;
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