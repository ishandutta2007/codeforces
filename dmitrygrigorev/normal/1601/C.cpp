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

struct Vertex {
  int sum;
  int min_prefix_sum;
};

vector<Vertex> rmq;

void build(int i, int l, int r) {
  if (r - l == 1) {
    rmq[i].sum = 1;
    rmq[i].min_prefix_sum = 0;
    return;
  }

  int mid = (l+r)/2;
  build(2*i+1, l, mid);
  build(2*i+2, mid, r);

  rmq[i].sum = rmq[2*i+1].sum + rmq[2*i+2].sum;
  rmq[i].min_prefix_sum = min(rmq[2*i+1].min_prefix_sum, rmq[2*i+1].sum + rmq[2*i+2].min_prefix_sum);
}

void upd(int i, int l, int r, int index, int w) {
  if (r - l == 1) {
    rmq[i].sum = w;
    rmq[i].min_prefix_sum = w;
    return;
  }

  int mid = (l+r)/2;
  if (index < mid) upd(2*i+1, l, mid, index, w);
  else upd(2*i+2, mid, r, index, w);

  rmq[i].sum = rmq[2*i+1].sum + rmq[2*i+2].sum;
  rmq[i].min_prefix_sum = min(rmq[2*i+1].min_prefix_sum, rmq[2*i+1].sum + rmq[2*i+2].min_prefix_sum);

}

struct FenwickTree1 {
  
  vector<int> t;
  int n;

  int get(int v) {
    int res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }

  // Sum [vl..vr]
  int get(int vl, int vr) {
    if (vl > vr) return 0;
    int res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return res;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < n; v = v | (v + 1)) {
      t[v] += val;
    }
  }

  FenwickTree1(int n_) {
    n = n_;
    t.assign(n, 0);
  }

};

void solve() {

  int n, m;
  cin >> n >> m;

  FenwickTree1 f(n);

  vector<pair<int, int> > farr;
  vector<int> sarr(m);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    farr.pb(mp(x, i));
  }

  for (auto &x : sarr) cin >> x;
  sort(all(farr));
  sort(all(sarr));

  rmq.assign(4 * n, {});
  build(0, 0, n);

  int cur = 0;
  ll ans = 0;

  int u = 0;
  int tt = 0;

  for (auto x : sarr) {
    while (u < farr.size() && farr[u].x < x) {
      cur++;
      upd(0, 0, n, farr[u++].y, -1);
    }
    tt = max(tt, u);
    while (tt < farr.size() && farr[tt].x == x) {
      upd(0, 0, n, farr[tt++].y, 0);
    }
    //per(cur, rmq[0].min_prefix_sum);
    ans += cur + rmq[0].min_prefix_sum;
  }

  for (int i = 0; i < farr.size(); ++i) {
    ans += f.get(farr[i].y, n - 1);
    f.up(farr[i].y, 1);
  }

  cout << ans <<'\n';

}

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}