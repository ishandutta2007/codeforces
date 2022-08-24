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

const ll INF = 1e18;

struct Rmq {

  vector<ll> minimum;
  vector<ll> maximum;

  vector<pair<ll, ll> > p;

  ll base;

  void build(int i, int l, int r, vector<ll> &arr) {
    if (r - l == 1) {
      minimum[i] = arr[l];
      maximum[i] = arr[l];
      return;
    }

    int mid = (l+r) / 2;
    build(2*i+1, l, mid, arr);
    build(2*i+2, mid, r, arr);

    minimum[i] = min(minimum[2*i+1], minimum[2*i+2]);
    maximum[i] = max(maximum[2*i+1], maximum[2*i+2]);

  }

  void push(int i, int l, int r) {
    if (r - l <= 1) return;
    if (p[i].x != INF) {
      ll T = p[i].x;

      p[2*i+1] = mp(T, 0);
      p[2*i+2] = mp(T, 0);
      minimum[2*i+1] = T;
      maximum[2*i+1] = T;

      minimum[2*i+2] = T;
      maximum[2*i+2] = T;

      p[i].x = INF;
    }

    ll T = p[i].y;

    p[2*i+1].y += T;
    p[2*i+2].y += T;
    minimum[2*i+1] += T;
    maximum[2*i+1] += T;

    minimum[2*i+2] += T;
    maximum[2*i+2] += T;

    p[i].y = 0;
  }

  void add(int i, int l, int r, int l1, int r1, ll x) {
    push(i, l, r);
    if (l1 >= r1) return;
    if (l == l1 && r == r1) {
      minimum[i] += x, maximum[i] += x, p[i].y += x;
      return;
    }
    int mid = (l+r)/2;
    add(2*i+1, l, mid, l1, min(r1, mid), x);
    add(2*i+2, mid, r, max(l1, mid), r1, x);

    minimum[i] = min(minimum[2*i+1], minimum[2*i+2]);
    maximum[i] = max(maximum[2*i+1], maximum[2*i+2]);
  }

  void remove_all_positive(int i, int l, int r) {
    push(i, l, r);
    if (minimum[i] > 0) {
      minimum[i] = -INF, maximum[i] = -INF, p[i].x = -INF;
      return;
    }
    if (maximum[i] <= 0) return;
    int mid = (l+r)/2;
    remove_all_positive(2*i+1, l, mid);
    remove_all_positive(2*i+2, mid, r);

    minimum[i] = min(minimum[2*i+1], minimum[2*i+2]);
    maximum[i] = max(maximum[2*i+1], maximum[2*i+2]);
  }

  void assign(int i, int l, int r, int l1, int r1, ll x) {
    push(i, l, r);
    if (l1 >= r1) return;
    if (l == l1 && r == r1) {
      minimum[i] = x, maximum[i] = x, p[i].x = x;
      return;
    }
    int mid = (l+r)/2;
    assign(2*i+1, l, mid, l1, min(r1, mid), x);
    assign(2*i+2, mid, r, max(l1, mid), r1, x);

    minimum[i] = min(minimum[2*i+1], minimum[2*i+2]);
    maximum[i] = max(maximum[2*i+1], maximum[2*i+2]);
  }

  ll get(int i, int l, int r, int index) {
    push(i, l, r);
    if (r - l == 1) return minimum[i];
    int mid = (l+r)/2;
    if (index < mid) return get(2*i+1, l, mid, index);
    return get(2*i+2, mid, r, index);
  }

  Rmq() {}
  Rmq(ll n, vector<ll> arr) {

    for (auto &x : arr) {
      x -= n;
      if (x > 0) x = -INF;
    }

    minimum.assign(4 * arr.size(), INF);
    maximum.assign(4 * arr.size(), -INF);

    p.assign(4 * arr.size(), mp(INF, 0));

    base = n;
    build(0, 0, arr.size(), arr);

  }

};

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<Rmq> cur;
  vector<ll> deg;

  deg.pb(1);
  for (int i = 1; i < 10; ++i) deg.pb(deg.back() * 42);
  vector<ll> arr(n);

  for (auto &x : arr) cin >> x;

  for (auto x : deg) cur.pb(Rmq(x, arr));

  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;

    if (t == 1) {
      int x;
      cin >> x;
      --x;
      cout << cur[9].get(0, 0, n, x) + deg.back() << '\n';
    }

    else if (t == 2) {
      int a, b, x;
      cin >> a >> b >> x;
      a--;

      for (int i = 0; i < 10; ++i) {
        cur[i].assign(0, 0, n, a, b, (ll) x - deg[i]);
        cur[i].remove_all_positive(0, 0, n);
      }
    }

    else {
      int a, b, x;
      cin >> a >> b >> x;
      a--;

      for (int i = 0; i < 10; ++i) {
        cur[i].add(0, 0, n, a, b, x);
        cur[i].remove_all_positive(0, 0, n);
      }

      while (true) {
        bool st = true;
        for (int i = 0; i < 10; ++i) {
         // per(cur[i].maximum[0]);
          if (cur[i].maximum[0] == 0) st = false;
        }
        if (st) break;

        for (int i = 0; i < 10; ++i) {
          cur[i].add(0, 0, n, a, b, x);
          cur[i].remove_all_positive(0, 0, n);
        }
      }

    }

  } 


}