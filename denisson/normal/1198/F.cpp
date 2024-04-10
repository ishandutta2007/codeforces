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
int a[100007];

int was[11][11];
int was1[11];
int was2[11];

int ans[100007];

vector<int> fac(int x) {
  vector<int> res;

  int uk = 2;
  while (uk * uk <= x) {
    if (x % uk == 0) res.pb(uk);
    while (x % uk == 0) x /= uk;
    ++uk;
  }
  if (x > 1) res.pb(x);

  return res;
}

pair<pair<int, int>, pair<int, int>> dp[1 << 9][1 << 9];

void dfs() {
  int v1 = myRand32() % n;
  int v2 = myRand32() % n;
  if (v1 == v2) return;
  
  auto t1 = fac(a[v1]);
  auto t2 = fac(a[v2]);
  
  for (int i = 0; i < 11; ++i) for (int j = 0; j < 11; ++j) was[i][j] = was1[i] = was2[i] = 0;

  vector<int> d;

  fill(ans, ans + n, 1);

  for (int i = 0; i < n; ++i) if (i != v1 && i != v2) {

    int need = 1;
    for (int w1 = 0; w1 < t1.size() && need; ++w1) if (a[i] % t1[w1] != 0) {
      for (int w2 = 0; w2 < t2.size() && need; ++w2) if (a[i] % t2[w2] != 0) {
        if (was[w1][w2] == 0) {
          d.pb(i);
          was[w1][w2] = 1;
          need = 0;
        }
      }
    }

    if (need) {
      for (int w1 = 0; w1 < t1.size() && need; ++w1) if (a[i] % t1[w1] != 0 && was1[w1] == 0) {
        was1[w1] = 1;
        d.pb(i); need = 0;
      } 
      for (int w2 = 0; w2 < t2.size() && need; ++w2) if (a[i] % t2[w2] != 0 && was2[w2] == 0) {
        d.pb(i);
        was2[w2] = 1;
        need = 0;
      }
    }

  }

  for (int i = 0; i < (1 << t1.size()); ++i)
  for (int j = 0; j < (1 << t2.size()); ++j)
    dp[i][j] = mp(mp(-1, -1), mp(-1, -1));

  dp[0][0] = mp(mp(1e9, -1), mp(-1, -1));

  for (int i = 0; i < d.size(); ++i) {
    int mm1 = 0, mm2 = 0;
    for (int j = 0; j < t1.size(); ++j) if (a[d[i]] % t1[j] != 0) mm1 ^= 1 << j;
    for (int j = 0; j < t2.size(); ++j) if (a[d[i]] % t2[j] != 0) mm2 ^= 1 << j;
    
    for (int m1 = (1 << t1.size()) - 1; m1 >= 0; --m1) for (int m2 = (1 << t2.size()) - 1; m2 >= 0; --m2)
      if (dp[m1][m2].x.x != -1) {
        if (dp[m1 | mm1][m2].x.x == -1)
          dp[m1 | mm1][m2] = mp(mp(d[i], 1), mp(m1, m2));
        if (dp[m1][m2 | mm2].x.x == -1)
          dp[m1][m2 | mm2] = mp(mp(d[i], 2), mp(m1, m2));
      }  
  }

  int f1 = (1 << t1.size()) - 1;
  int f2 = (1 << t2.size()) - 1;

  if (dp[f1][f2].x.x == -1) return;

 // pper(d);

  while ((f1 | f2) > 0) {
    auto [g1, g2] = dp[f1][f2].y;

   // cout << dp[f1][f2] << endl;

    int v = dp[f1][f2].x.x;
    ans[v] = dp[f1][f2].x.y;

    f1 = g1;
    f2 = g2;
  }

  ans[v1] = 1;
  ans[v2] = 2;

  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
  exit(0);



}




int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);
 
  int cnt = min(100, 1 + (1000000 / n));
  
  for (int it = 0; it < cnt; ++it) dfs();
  
  cout << "NO";
}