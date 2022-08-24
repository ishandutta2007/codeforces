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

vector<vector<int> > gr;
int n, k;

vector<int> h;
vector<int> sz;
vector<int> pos;
vector<int> euler;
vector<int> closed;
vector<int> father;

void dfs(int vertex, int last) {

  euler.pb(vertex);

  sz[vertex] = 1;
  pos[vertex] = euler.size() - 1;

  int z = -1;
  father[vertex] = last;

  for (int i = 0; i < gr[vertex].size(); ++i) {
    if (gr[vertex][i] == last) z = i;
  }
  if (z != -1) {
    swap(gr[vertex][z], gr[vertex].back());
    gr[vertex].pop_back();
  }
  for (auto to : gr[vertex]) {
    dfs(to, vertex);
    sz[vertex] += sz[to];
  }
}

vector<pair<int, int> > rmq;
vector<int> p;

void dfs2(int vertex, int x) {
  h[vertex] = x;
  for (auto to : gr[vertex]) {
    dfs2(to, x + 1);
  }
}

void build(int i, int l, int r) {
  if (r - l == 1) {
    rmq[i] = mp(h[euler[l]], euler[l]);
    return;
  }
  int mid = (l+r)/2;
  build(2*i+1, l, mid);
  build(2*i+2, mid, r);
  rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
}

void do_push(int i, int W) {
  if (W==0) return;
  rmq[i].x -= W;
  p[i] += W;
}

void push(int i, int l, int r) {
  if (r-l <= 1)return;
  int mid = (l+r)/2;

  do_push(2*i+1, p[i]);
  do_push(2*i+2, p[i]);
  p[i] = 0;
}

void upd(int i, int l, int r, int l1, int r1) {

  if (l1 >= r1) return;
  push(i, l, r);
  if (l == l1 && r == r1) {
    do_push(i, 1);
    return;
  }

  int mid = (l+r)/2;
  upd(2*i+1, l, mid, l1, min(r1, mid));
  upd(2*i+2, mid, r, max(l1, mid), r1);
  rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);

}

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  gr.assign(n, {});

  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    gr[x].pb(y);
    gr[y].pb(x);
  }

  father.assign(n, -1);
  sz.resize(n);
  pos.resize(n);

  dfs(0, -1);
  int Q = 0;
  for (auto x : gr) if (x.empty()) Q++;
  if (Q <= k) {
    k = min(k, max(n / 2, Q));
    cout << (ll) k * (n - k);
    return 0;
  }

  h.assign(n, -1);
  closed.assign(n, 0);

  dfs2(0, 1);
  rmq.assign(4*n, mp(-1e9, -1));
  p.assign(4*n, 0);
  build(0, 0, n);

  int total = 0;
  for (int i = 0; i < k; ++i) {
    int x = rmq[0].y;
    vector<int> path;
    path.pb(x);

    while (true) {
      int W = father[path.back()];
      if (W == -1 || closed[W]) break;
      path.pb(W);
    }

    reverse(all(path));

    for (auto x : path) {
      closed[x] = 1;
      int L = pos[x], R = pos[x] + sz[x] - 1;
      upd(0, 0, n, L, R + 1);
    }

    total += path.size();
  }

  ll tans = 1e18;
  for (int p = 0; p <= n - total; ++p) {
    tans = min(tans, (ll) (n - k - p) * (k - p)); 
  }

  cout << tans;


}