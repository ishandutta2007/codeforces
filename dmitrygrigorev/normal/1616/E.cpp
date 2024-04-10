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


struct FenwickTree1 {
  vector<ll> t;

  int MAX_SIZE;

  // Sum [0..v]
  ll get(int v) {
    if (v < 0) return 0;
    ll res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }

  // Sum [vl..vr]
  ll get(int vl, int vr) {
    ll res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return res;
  }

  FenwickTree1(int n) {
    t.assign(2*n, 0);
    MAX_SIZE = 2*n;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      t[v] += val;
    }
  }
};

void solve() {

  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  vector<vector<int> > pos(26);
  for (int i = 0; i < s.size(); ++i) {
    pos[s[i] - 'a'].pb(i);
  }

  for (auto &x : pos) reverse(all(x));
  FenwickTree1 f(s.size());

  ll ans = 1e18;
  ll tot = 0;

  for (int i = 0; i < s.size(); ++i) {
    int M = 1e9;
    for (int j = 0; j < t[i] - 'a'; ++j) {
      if (pos[j].size()) {
        M = min(M, pos[j].back());
      }
    }

    if (M != 1e9) {

      int dop = f.get(0, M);
      ans = min(ans, tot + M - dop);

    }

    int Q = t[i] - 'a';
    if (!pos[Q].size()) {
      if (ans == 1e18) cout << "-1\n";
      else cout << ans << '\n';
      return;
    }

    int Z = pos[Q].back() + f.get(pos[Q].back() + 1, s.size());
    f.up(pos[Q].back(), 1);
    pos[Q].pop_back();

    tot += Z;
    tot -= i;
  }

  if (ans == 1e18) cout << "-1\n";
  else cout << ans << '\n';



}

int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();



}