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

const int A = 100007;
int fact[A];
int rv[A];

int C(int n, int k) {
  return mult(fact[n], mult(rv[k], rv[n - k]));
}

const int N = 1507;
int prob[N][N];
int pl[N];
int pr[N];

int dp[2][2][N][2];

int uk = 0;

void recalc_nothing() {

  int p[2];
  p[0] = 0, p[1] = 0;

  for (int e = 0; e < N; ++e) {
    for (int f = 0; f < 2; ++f) {
      add(p[f], dp[uk][0][e][f]);
    }
  }

  for (int e = 0; e < N; ++e) {
    for (int f = 0; f < 2; ++f) {
      add(dp[uk ^ 1][0][e][f], mult(pl[e], p[f]));
      add(dp[uk ^ 1][1][e][f], mult(pl[e], p[f]));
    }
  }
}

int n, m, a, b, k;

vector<int> exactly;

void recalc_do() {

  for (int t = 0; t < 2; ++t) {
    for (int was = 0; was < 2; ++was) {
      int Z = 0;
      vector<int> rem(m + 1, 0);
      for (int want = 1; want < m; ++want) {
        add(Z, dp[uk][1 - t][m - want][was]);
        int happen = 0;

        if (t == 0) happen = mult(Z, pl[want]);
        else happen = mult(Z, pr[want]);

        //per(Z, happen);

        add(dp[uk ^ 1][t][want][was ^ 1], happen);
        add(rem[m - 1 - want], happen);
      }

      for (int i = m; i >= 0; --i) {
        add(dp[uk ^ 1][1 - t][i][was ^ 1], mult(rem[i], exactly[i]));
        int T = 1;
        dec(T, exactly[i]);
        if (i > 0) add(rem[i - 1], mult(T, rem[i]));
      }

    }
  }

}

int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < A; ++i) fact[i] = mult(i, fact[i - 1]);
  for (int i = 0; i < A; ++i) rv[i] = bp(fact[i], mod - 2); 

  cin >> n >> m >> a >> b >> k;

  int p_kill = mult(a, bp(b, mod - 2));
  int p_stay = mult(b - a, bp(b, mod - 2));

  exactly.assign(m + 1, 0);
  int v = 0;

  for (int i = 0; i <= m && i <= k; ++i) {
    int u = mult(C(k, i), mult(bp(p_kill, i), bp(p_stay, k - i)));
    add(v, u);
    exactly[i] = mult(u, bp(v, mod - 2));
  }


  for (int e = 0; e < m; ++e) {
    for (int f = 0; e + f < m && e + f <= 2 * k; ++f) {
      prob[e][f] = mult(C(k, e), mult(C(k, f), mult(bp(p_kill, e + f), bp(p_stay, 2 * k - (e + f)))));
    }
  }

  int tot = 0;
  for (int e = 0; e < N; ++e) for (int f = 0; f < N; ++f) add(tot, prob[e][f]);
  int G = bp(tot, n);
  int R = bp(tot, mod - 2);
  for (int e = 0; e < N; ++e) for (int f = 0; f < N; ++f) prob[e][f] = mult(prob[e][f], R);
  for (int e = 0; e < N; ++e) for (int f = 0; f < N; ++f) {
    add(pl[e], prob[e][f]);
    add(pr[f], prob[e][f]);
  }

  for (int e = 0; e < N; ++e) {
    for (int f = 0; f < N; ++f) {
      add(dp[0][0][e][0], prob[e][f]);
      add(dp[0][1][f][0], prob[e][f]);
    }
  }

  for (int i = 1; i < n; ++i) {
    for (int t = 0; t < 2; ++t) for (int j = 0; j < N; ++j) for (int e = 0; e < 2; ++e) dp[uk ^ 1][t][j][e] = 0;
    recalc_nothing();
    recalc_do();
    uk ^= 1;
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int f = 0; f < 2; ++f) {
      if (f%2==0) add(ans, dp[uk][0][i][f]);
      else dec(ans, dp[uk][0][i][f]); 
    }
  }

  ans = mult(ans, G);
  //per(mult(ans, 1000*(1<<9)));
  cout << ans;
  




}