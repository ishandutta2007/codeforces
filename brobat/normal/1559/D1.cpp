#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 1100
#define MOD 1000000007

void _print(int t) {cerr << t << " ";}
void _print(string t) {cerr << t << " ";}
void _print(char t) {cerr << t << " ";}
void _print(double t) {cerr << t << " ";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}\n";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T, class V> void _print(unordered_map <T, V> umap) {cerr << "{ "; for(auto i : umap) {cerr << "{";_print(i.first); cerr << ", "; _print(i.second); cerr << "} ";} cerr << "}\n";}

int n, m1, m2;
int p1[MAXN];
int p2[MAXN];
int parent[MAXN];

map<pair<int, int>, vector<vector<int>>> adj;
map<pair<int, int>, pair<int, int>> m;
map<pair<int, int>, bool> visited;
vector<pair<int, int>> ans;
map<pair<int, int>, bool> hbl;

int f1(int x) {
    if(x == p1[x]) return x;
    else return p1[x] = f1(p1[x]);
}
int f2(int x) {
    if(x == p2[x]) return x;
    else return p2[x] = f2(p2[x]);
}
void u1(int c, int d) {
    int a = f1(c);
    int b = f1(d);
    if(a!=b) p1[b] = a;
}
void u2(int c, int d) {
    int a = f2(c);
    int b = f2(d);
    if(a!=b) p2[b] = a;
}
pair<int, int> find(pair<int, int> x) {
    if(m[x] == x) return x;
    else return m[x] = find(m[x]);
}

void pre() {
    cin >> n >> m1 >> m2;
    int t1, t2;
    forn(i, 0, n) {
        p1[i] = i;
        p2[i] = i;
    }
    forn(i, 0, m1) {
        cin >> t1 >> t2;
        t1--; t2--;
        u1(t1, t2);
    }
    forn(i, 0, m2) {
        cin >> t1 >> t2;
        t1--; t2--;
        u2(t1, t2);
    }
    forn(i, 0, n) {
        f1(i);
        f2(i);
    }
    // forn(i, 0, n) cerr << p1[i] << " ";
    // cerr << endl;
    // forn(i, 0, n) cerr << p2[i] << " ";
    // cerr << endl;
}

void solve() {
    pre();
    forn(i, 0, n) {
        forn(j, i, n) {
            // if(p1[i]!=p1[j] && p2[i]!=p2[j]) {
            if(f1(i)!=f1(j) && f2(i)!=f2(j)) {
                ans.push_back({i, j});
                u1(i, j);
                // p2[p2[i]] = p2[j];
                u2(i, j);
                // f1(i); f1(j); f2(i); f2(j);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}