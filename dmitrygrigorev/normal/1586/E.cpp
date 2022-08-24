#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

struct Node {
  int p, r, f;
};

struct DSU {
  static const int SZ = 300007;
  Node t[SZ];

  DSU() { reset(SZ); }

  void reset(int n) {
    for (int i = 0; i < n; ++i) {
      t[i].p = i;
      t[i].r = 0;
      t[i].f = 1;
    }
  }

  int get(int v) {
    if (t[v].p == v) return v;
    return t[v].p = get(t[v].p);
  }

  int get_func(int v) {
    return t[get(v)].f;
  }

  void merge(int a, int b) {
    a = get(a), b = get(b);
    if (a != b) {
      if (t[a].r < t[b].r) swap(a, b);
      t[b].p = a;
      t[a].f += t[b].f;
      if (t[a].r == t[b].r) ++t[a].r;
    }
  }
};

DSU dsu;

vector<vector<int> > gr;
vector<vector<int> > t;

vector<vector<int> > paths;

void dfs(int vertex, int last, int need, vector<int> &path) {
  path.pb(vertex);
  if (vertex == need) {
    paths.pb(path);
  }

  for (auto to : gr[vertex]) {
    if (to == last) continue;
    dfs(to, vertex, need, path);
  }

  path.pop_back();

}

void upd(int x, int y) {
  for (int i = 0; i < gr[x].size(); ++i) {
    if (gr[x][i] == y) {
      t[x][i] ^= 1;
    }
  }
}

pair<int, int> dfs2(int vertex, int last, int z) {

  int ans = 0;
  int way = 0;

  for (int i = 0; i < gr[vertex].size(); ++i) {
    int to = gr[vertex][i];
    if (to == last) continue;
    auto res = dfs2(to, vertex, t[vertex][i]);
    ans += res.x;

    if (way && res.y) {
      ans++;
      way = 0;
    }
    else {
      way ^= res.y;
    }
  }

  if (z) way = 1;
  if (z == 0 && way == 1) {
    ans++;
    way = 0;
  }

  return mp(ans, way);
}

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  gr.assign(n, {});
  t.assign(n, {});

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;

    if (dsu.get(x) != dsu.get(y)) {
      gr[x].pb(y);
      gr[y].pb(x);
      t[x].pb(0);
      t[y].pb(0);
      dsu.merge(x, y);
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;

    a--, b--;

    vector<int> path;
    dfs(a, -1, b, path);

    auto Q = paths.back();
    for (int i = 0; i + 1 < Q.size(); ++i) {
      upd(Q[i], Q[i + 1]);
      upd(Q[i + 1], Q[i]);
    }
  }

  auto p = dfs2(0, -1, 0);

  int R = p.x + p.y;
  if (R == 0) {
    cout << "YES\n";
    for (auto x : paths) {
      cout << x.size() << '\n';
      for (auto y : x) cout << y+1 << " ";
      cout << '\n';
    }
  }

  else {
    cout << "NO\n";
    cout << R;
  }


}