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

const int mod = 998244353;

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

int n, p, q;

int strong[2002];
int dp[2002];
int cp[2002][2002];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int w1, w2;
  cin >> n >> w1 >> w2;
  p = mult(w1, bp(w2, mod - 2));
  q = 1;
  dec(q, p);


  for (int i = 1; i <= 2000; ++i) {
    
    cp[i][i] = 1;
    cp[i][0] = 1;

    for (int j = 1; j < i; ++j) {

      cp[i][j] = mult(cp[i - 1][j], bp(p, j));
      add(cp[i][j], mult(cp[i - 1][j - 1], bp(q, i - j)));

    }

  }

  strong[1] = 1;
  for (int w = 2; w <= n; ++w) {
    strong[w] = 1;
    for (int sz = 1; sz < w; ++sz) {
      dec(strong[w], mult(strong[sz], cp[w][sz]));
    }
  }

  dp[1] = 0;
  for (int i = 2; i <= n; ++i) {
    
    int now = 0;

    for (int w = 1; w < i; ++w) {

      int val = dp[w];
      add(val, dp[i - w]);
      add(val, w * (w - 1) / 2);
      add(val, w * (i - w));

      add(now, mult(val, mult(strong[w], cp[i][w])));

    }

    add(now, mult(i * (i - 1) / 2, strong[i]));

    int coef = 1;
    dec(coef, strong[i]);
    dp[i] = mult(now, bp(coef, mod - 2));

  }


  cout << dp[n];
}