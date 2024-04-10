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

__int128 read() {
  string s;
  cin >> s;

  __int128 ans = 0;

  for (auto x : s) {
    ans *= 10;
    ans += (x - '0');
  }

  return ans;

}

__int128 gcd(__int128 x, __int128 y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

struct Rmq {

  vector<__int128> rmq;

  void upd(int i, int l, int r, int index, __int128 val) {
    if (r - l == 1) {
      rmq[i] = val;
      return;
    }
    int mid = (l+r)/2;
    if (index < mid) upd(2*i+1, l, mid, index, val);
    else upd(2*i+2, mid, r, index, val);
    rmq[i] = gcd(rmq[2*i+1], rmq[2*i+2]);
  }

  void build(int i, int l, int r, vector<__int128> &v) {
    if (r - l == 1) {
      rmq[i] = v[l];
      return;
    }
    int mid = (l+r)/2;
    build(2*i+1, l, mid, v);
    build(2*i+2, mid, r, v);
    rmq[i] = gcd(rmq[2*i+1], rmq[2*i+2]);
  }

  Rmq(vector<__int128> v) {
    int n = v.size();
    rmq.assign(4*n, 0);
    build(0, 0, n, v);
  }

  Rmq() {

  }

};

void print(__int128 x) {
  string s = "";
  while (x > 0) {
    s.pb((char) ('0' + x%10));
    x /= 10;
  }
  reverse(all(s));
  cout << s << " ";
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<__int128> a(n), b(m);
  for (auto &x : a) {
    x = read();
  }

  for (auto &x : b) {
    x = read();
  }

  vector<Rmq> ra, rb;
  for (int i = 0; i < n; ++i) {
    vector<__int128> v;
    for (int j = 0; j < m; ++j) {
      auto g = gcd(a[i], b[j]);
      v.pb(a[i] / g);
    }
    ra.pb(Rmq(v));
  }

  for (int i = 0; i < m; ++i) {
    vector<__int128> v;
    for (int j = 0; j < n; ++j) {
      auto g = gcd(a[j], b[i]);
      v.pb(b[i] / g);
    }
    rb.pb(Rmq(v));
  }

  vector<bool> aa(n, true), ab(m, true);

 // rb[1].upd(0, 0, n, 1, 0);


 // for (int i = 0; i < m; ++i) per((ll) rb[i].rmq[0]);

  while (true) {
    //per((ll) ra[1].rmq[0]);
    //per(aa, ab);
    int s1 = 0, s2 = 0;
    for (auto x : aa) s1 += x;
    for (auto x : ab) s2 += x;
    if (!s1 || !s2) {
      cout << "NO\n";
      return;
    }

    bool ok = 1;
    for (int i = 0; i < n && ok; ++i) {
      if (!aa[i]) continue;
      if (ra[i].rmq[0] == 1) continue;

      aa[i] = 0;

      ok = 0;
      for (int j = 0; j < m; ++j) {
        if (!ab[j]) continue;
        rb[j].upd(0, 0, n, i, 0);
      }
    }

    for (int i = 0; i < m && ok; ++i) {
      if (!ab[i]) continue;
      if (rb[i].rmq[0] == 1) continue;

      ab[i] = 0;

      ok = 0;
      for (int j = 0; j < n; ++j) {
        if (!aa[j]) continue;
        ra[j].upd(0, 0, m, i, 0);
      }
    }

    if (ok) break;
  }

  cout << "YES\n";
  vector<__int128> la, lb;
  for (int i = 0; i < n; ++i) if (aa[i]) la.pb(a[i]);
  for (int i = 0; i < m; ++i) if (ab[i]) lb.pb(b[i]);

  cout << la.size() << " " << lb.size() << '\n';
  for (auto x : la) print(x);
  cout << '\n';

  for (auto x : lb) print(x);
  cout << '\n';


}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();



}