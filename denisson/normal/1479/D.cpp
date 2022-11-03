#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
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
  ull h = 0;
  int vl = -1, vr = -1;
};

std::vector<Node> t;
struct Tree {

  static int up(int v, int vl, int vr, int pos, ull val) {
    int now = t.size();
    t.emplace_back();

    if (vl == vr) {

      t[now].h = val;
      if (v != -1) t[now].h ^= t[v].h;

    } else {
      if (v != -1) {
        t[now].vl = t[v].vl;
        t[now].vr = t[v].vr;
      }

      int vm = (vl + vr) >> 1;
      if (pos <= vm) {
        t[now].vl = up(v == -1 ? -1 : t[v].vl, vl, vm, pos, val);
      } else {
        t[now].vr = up(v == -1 ? -1 : t[v].vr, vm + 1, vr, pos, val);
      }

      t[now].h = 0;
      if (t[now].vl != -1) t[now].h ^= t[t[now].vl].h;
      if (t[now].vr != -1) t[now].h ^= t[t[now].vr].h;
    } 

    return now;
  }


  static int get(int w1, int w2, int w3, int w4, int vl, int vr, int l, int r) {
    if (r < vl || l > vr) return -1;
    
    auto getH = [](int v) -> ull {
      return v == -1 ? 0 : t[v].h;
    };

    ull now = ((getH(w1) ^ getH(w2)) ^ getH(w3)) ^ getH(w4);

  //  per(w1, w2, w3, w4, vl, vr, now);
  //  per(t[w1].h, t[w2].h);

    if (now == 0) return -1;

    if (vl == vr) {
      return vl;
    } else {
      int vm = (vl + vr) >> 1;

      int ww1 = w1;
      int ww2 = w2;
      int ww3 = w3;
      int ww4 = w4;

      if (w1 != -1) ww1 = t[w1].vl;
      if (w2 != -1) ww2 = t[w2].vl;
      if (w3 != -1) ww3 = t[w3].vl;
      if (w4 != -1) ww4 = t[w4].vl;

      int now = get(ww1, ww2, ww3, ww4, vl, vm, l, r);
      if (now != -1) return now;

      ww1 = w1;
      ww2 = w2;
      ww3 = w3;
      ww4 = w4;

      if (w1 != -1) ww1 = t[w1].vr;
      if (w2 != -1) ww2 = t[w2].vr;
      if (w3 != -1) ww3 = t[w3].vr;
      if (w4 != -1) ww4 = t[w4].vr;

      now = get(ww1, ww2, ww3, ww4, vm + 1, vr, l, r);
      return now;
    }
  }


};



int n, q;
vector<int> g[300007];
int color[300007];

ull MAGIC[300007];

int tin[300007];
int tout[300007];
int up[300007][20];

int tt;

void dfs(int v, int p = 0) {
  tin[v] = tt++;

  up[v][0] = p;
  for (int i = 1; i < 20; ++i) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }

  for (int to : g[v]) if (to != p) {
    dfs(to, v);
  }

  tout[v] = tt++;
}

bool isPred(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int getLCA(int a, int b) {
  if (isPred(a, b)) return a;
  if (isPred(b, a)) return b;

  for (int i = 19; i >= 0; --i) if (!isPred(up[a][i], b)) a = up[a][i];

  return up[a][0];
}

int to_root[300007];

void go(int v, int p = -1, int prev_root = 0) {

 // per(v, color[v], MAGIC[color[v]]);

  to_root[v] = Tree::up(prev_root, 1, n, color[v], MAGIC[color[v]]);

  for (int to : g[v]) if (to != p) {

    go(to, v, to_root[v]);

  }
}

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  cin >> n >> q;
  readArr(color, color + n);

  for (int i = 0; i <= n; ++i) {
    MAGIC[i] = myRand64();
  }


  for (int i = 0; i + 1 < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  dfs(0);


  t.emplace_back();
  go(0);

  while (q--) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    --u; --v;
    int lca = getLCA(u, v);


    int pr = to_root[up[lca][0]];
    if (lca == 0) pr = -1;

  //  per(u, v, lca, up[lca][0]);

    cout << Tree::get(to_root[u], to_root[v], to_root[lca], pr, 1, n, l, r) << "\n";

  }

}