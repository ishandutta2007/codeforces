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

int n;
vector<int> g[100007];
pair<int, int> z[100007];
vector<pair<int, int> > d[100007];

int h[100007];
int tin[100007];
int tout[100007];
int tt = 0;
vector<int> heh;

int up[17][100007];

void dfs(int v = 0, int p = 0, int hh = 0) {

  up[0][v] = p;
  for (int i = 1; i < 17; ++i) up[i][v] = up[i - 1][up[i - 1][v]];

  heh.pb(hh);
  h[v] = hh;
  tin[v] = tt++;
  for (int to : g[v]) if (to != p) dfs(to, v, hh + 1);
  tout[v] = tt - 1;
}

struct Tree {
  int t[4 * 100007];
  int p[4 * 100007];

  void build(int v, int vl, int vr) {
    if (vl == vr) {
      t[v] = heh[vl];
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
      t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }

  void push(int v) {
    if (p[v] != 0) {
      t[v] += p[v];
      if (v * 2 + 1 < 4 * 100007) p[v * 2 + 1] += p[v];
      if (v * 2 + 2 < 4 * 100007) p[v * 2 + 2] += p[v];
      p[v] = 0;
    }
  }

  void add(int v, int vl, int vr, int l, int r, int val) {
    push(v);
    if (r < vl || l > vr) return;
    if (vl >= l && vr <= r) {
    //  per(v, vl, vr, l, r, val);
      p[v] += val;
      push(v);
    } else {
      int vm = (vl + vr) >> 1;
      add(v * 2 + 1, vl, vm, l, r, val);
      add(v * 2 + 2, vm + 1, vr, l, r, val);
      t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }

  int get(int v, int vl, int vr, int l, int r) {
    push(v);
    if (l > r) return -1;
    if (r < vl || l > vr) return -1;
    if (vl >= l && vr <= r) return t[v];
    int vm = (vl + vr) >> 1;
    return max(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
  }

} tr;

int ans[100007];

bool isPred(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int getK(int v, int k) {
  for (int i = 0; i < 17; ++i) if ((k >> i) & 1) v = up[i][v];
  return v;
}

int getLCA(int a, int b) {
  if (isPred(a, b)) return a;
  if (isPred(b, a)) return b;
  for (int i = 16; i >= 0; --i) if (!isPred(up[i][a], b)) a = up[i][a];
  return up[0][a];
}

void go(int v = 0, int p = -1) {

  //pper(v);
  //for (int i = 0; i < tt; ++i) cout << tr.get(0, 0, tt - 1, i, i) << ' ';
  //cout << endl;

  for (auto [i, w] : d[v]) {

    if (isPred(v, w)) {

      int dist = h[w] - h[v];
      int node = getK(w, dist >> 1);
      uax(ans[i], tr.get(0, 0, tt - 1, 0, tin[node] - 1));
      uax(ans[i], tr.get(0, 0, tt - 1, tout[node] + 1, tt - 1));

    } else if (isPred(w, v)) {

      int dist = h[v] - h[w];
      int node = getK(v, dist >> 1);
      uax(ans[i], tr.get(0, 0, tt - 1, tin[node], tout[node]));

    } else {

      int sum = h[w] + h[v] - 2 * h[getLCA(v, w)];

      // per("AAA: ", sum, h[v], h[w]);

      if (h[v] <= h[w]) {

        int node = getK(w, (sum - 1) >> 1);
        uax(ans[i], tr.get(0, 0, tt - 1, 0, tin[node] - 1));
        uax(ans[i], tr.get(0, 0, tt - 1, tout[node] + 1, tt - 1));

      } else {

        int node = getK(v, sum >> 1);
        uax(ans[i], tr.get(0, 0, tt - 1, tin[node], tout[node]));

      }

    }

  }

  for (int to : g[v]) if (to != p) {
    // per("TIN TOUT: ", to, tin[to], tout[to]);
    tr.add(0, 0, tt - 1, 0, tt - 1, 1);
    tr.add(0, 0, tt - 1, tin[to], tout[to], -2);
    go(to, v);
    tr.add(0, 0, tt - 1, 0, tt - 1, -1);
    tr.add(0, 0, tt - 1, tin[to], tout[to], 2);
  }

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    z[i] = mp(w1, w2);
    d[w1].pb(mp(i, w2)) ;
    d[w2].pb(mp(i, w1));
  }

  dfs();

  tr.build(0, 0, tt - 1);

  go();

  for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}