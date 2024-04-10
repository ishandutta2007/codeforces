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

ll n, m, q;
vector<pair<int, int> > g[2222];

ll dp[2002][2002];

ll cross(pair<ll, ll> w1, pair<ll, ll> w2) {
  return ceil((w2.y - w1.y) / (db)(w1.x - w2.x));
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m >> q;
  for (int i = 0; i < m; ++i) {
    int w1, w2, w3;
    cin >> w1 >> w2 >> w3;
    --w1; --w2;
    g[w1].pb(mp(w2, w3));
    g[w2].pb(mp(w1, w3));
  }

  int res = 0;

  for (int i = 0; i < 2002; ++i) fill(dp[i], dp[i] + 2002, (ll)-1e18);

  dp[0][0] = 0;

  for (int i = 0; i <= n; ++i) {
    for (int v = 0; v < n; ++v) for (auto [to, w] : g[v]) uax(dp[i + 1][to], dp[i][v] + w);
  }


  for (int i = 1; i <= min(q, n); ++i) {
    ll ma = 0;
    for (int v = 0; v < n; ++v) uax(ma, dp[i][v]);
    add(res, ma % mod);
  }


  if (q > n) {

    vector<pair<ll, ll>> t;

    for (int v = 0; v < n; ++v) for (auto [to, w] : g[v]) {
      t.pb(mp(w, dp[n][v] - n * (ll)w));
    }

    sort(all(t));

    // pper(t);

    vector<pair<ll, pair<ll, ll>>> st;

  //  pper(t);

    for (auto [k, b] : t) {
      
      while (st.size()) {
        if (st.back().y.x == k) st.pop_back();
        else {
          ll pos_x = cross(st.back().y, mp(k, b));
          if (pos_x <= st.back().x) {
            st.pop_back();
            // st.pb(mp(pos_x, mp(k, b)));
          } else break;
        }
      }

      if (st.size() == 0) {
        st.pb(mp(0, mp(k, b)));  // continue;
      } else {
        st.pb(mp(  cross(st.back().y, mp(k, b)) , mp(k, b)));
      }

    }

   // pper(st);

    st.pb(mp(1e18, mp(0, 0)));

    for (int i = 0; i + 1 < st.size(); ++i) {

      if (st[i].x > q) break;

      ll le = max(n + 1, st[i].x);
      ll ri = min(q + 1, st[i + 1].x) - 1;

      if (le > ri) continue;

      auto get_sum = [](ll le, ll ri) {
        ll now = ri * (ri + 1) / 2;
        now -= (le - 1) * le / 2;
        return now % mod;
      };

      st[i].y.y %= mod;
      if (st[i].y.y < 0) st[i].y.y += mod;

      add(res, ((ri - le + 1) * (ll)st[i].y.y) % mod);

      add(res, (st[i].y.x * get_sum(le, ri)) % mod);


     // for (ll x = ; x < ; ++x) add(res, (x * (ll)st[i].y.x + st[i].y.y) % mod);
    }

  }

  cout << res;
}