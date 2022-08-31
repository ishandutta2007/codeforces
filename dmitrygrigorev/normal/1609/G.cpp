#include <bits/stdc++.h>
#define ll long long
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

vector<pair<ll, ll> > rmq;
vector<ll> p;
vector<ll> minimum;

void uu(int v, int l, int r, ll x) {
  rmq[v].x += (ll) x * (r - l);
  rmq[v].y += (ll) x * (r - l) * (r - l + 1) / 2;
  p[v] += x;
  minimum[v] += x;
}

void push(int i, int l, int r) {
  if (r - l <= 1) return;
  ll x = p[i];
  p[i] = 0;

  if (x == 0) return;
  int mid = (l + r) / 2;
  
  uu(2*i+1, l, mid, x);
  uu(2*i+2, mid, r, x);
}

void build(int i, int l, int r, vector<ll> &v) {
  if (r - l == 1) {
    rmq[i] = mp(v[l], v[l]);
    p[i] = 0;
    minimum[i] = v[l];
    return;
  }
  int mid = (l+r)/2;
  build(2*i+1, l, mid, v);
  build(2*i+2, mid, r, v);

  int len = (r - mid);

  rmq[i].x = rmq[2*i + 1].x + rmq[2*i + 2].x;
  rmq[i].y = rmq[2*i + 2].y + rmq[2*i + 1].y + rmq[2*i + 1].x * len;
  minimum[i] = min(minimum[2 * i + 1], minimum[2 * i + 2]);
}

void upd(int i, int l, int r, int l1, int r1, ll d) {

  push(i, l, r);

  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    uu(i, l, r, d);
    return;
  }

  int mid = (l + r) / 2;
  upd(2*i+1, l, mid, l1, min(r1, mid), d);
  upd(2*i+2, mid, r, max(l1, mid), r1, d);

  int len = (r - mid);

  rmq[i].x = rmq[2*i + 1].x + rmq[2*i + 2].x;
  rmq[i].y = rmq[2*i + 2].y + rmq[2*i + 1].y + rmq[2*i + 1].x * len;
  minimum[i] = min(minimum[2 * i + 1], minimum[2 * i + 2]);

}

int cumul = 0;
ll ans = 0;
ll S = 0;

void get(int i, int l, int r, int l1, int r1) {

  push(i, l, r);

  if (l1 >= r1) return;
  if (l == l1 && r == r1) {
    ans += rmq[i].y;
    ans += rmq[i].x * cumul;

    S += rmq[i].x;
    cumul += (r - l);
    return;
  }

  int mid = (l+r)/2;
  get(2*i+2, mid, r, max(l1, mid), r1);
  get(2*i+1, l, mid, l1, min(r1, mid));

}

int get_less(int i, int l, int r, ll x) {

  push(i, l, r);

  if (r - l == 1) {
    if (minimum[i] <= x) return 1;
    return 0;
  }

  int mid = (l+r)/2;
  if (minimum[2*i+2] <= x) {
    return (mid - l) + get_less(2*i+2, mid, r, x);
  }
  return get_less(2*i+1, l, mid, x);

}

int main(){
#ifdef LOCAL
  freopen("G_input.txt", "r", stdin);
  //freopen("G_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q;
  cin >> n >> m >> q;

  vector<ll> a(n);
  vector<ll> b(m);

  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  vector<ll> da(n - 1);
  vector<ll> db(m - 1);

  for (int i = 1; i < n; ++i) {
    da[i - 1] = a[i] - a[i - 1];
  }
  for (int i = 1; i < m; ++i) {
    db[i - 1] = b[i] - b[i - 1];
  }

  rmq.resize(4 * m - 4);
  p.assign(4 * m - 4, 0);
  minimum.assign(4 * m - 4, 1e9);

  build(0, 0, m - 1, db);

  ll qans = (a[0] + b[0]) * (n + m - 1);

  for (int i = 0; i < q; ++i) {
  //  per(i);
    int t, k, d;
    cin >> t >> k >> d;

    if (t == 1) {
      if (k == n) {
        qans += (ll) d * (n + m - 1);
        --k;
      }
      for (int i = 0; i < k; ++i) {
        da[da.size() - i - 1] += d;
      }
    }

    else {
      if (k == m) {
        qans += (ll) d * (n + m - 1);
        --k;
      }

      int index = db.size() - k;
      db[index] += d;
      upd(0, 0, m - 1, index, m - 1, d);
    }

    int last = n + m - 2;
    int taken = 0;

    ll ttt = qans;

   // per(da);
   // per(db);
   // per(ttt);

    for (auto x : da) {
     // per(x);
      int W = get_less(0, 0, m - 1, x);
     // per(W);
      int dop = W - taken;

      cumul = 0, S = 0, ans = 0;
      get(0, 0, m - 1, taken, W);

     // per(S, ans);

      ans += S * (last - dop);
      last -= dop;
      taken += dop;

      ttt += ans;
      ttt += x * last;
      last--;
     // per(ttt);
    }

//    exit(0);

    int W = m - 1;
    int dop = W - taken;

    cumul = 0, S = 0, ans = 0;
    get(0, 0, m - 1, taken, W);

    ans += S * (last - dop);
    last -= dop;
    taken += dop;

    ttt += ans;

    cout << ttt << '\n';

  }

}