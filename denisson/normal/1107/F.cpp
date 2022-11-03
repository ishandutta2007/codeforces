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

struct ST {
  ll a, b, k;
} a[555];

int n;

ll dp[2][505][505];


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].a >> a[i].b >> a[i].k;
  }

  sort(a, a + n, [](const ST& a, const ST& b) {
    return a.b < b.b;
  });

  int uk = 0;

  for (int i = 0; i < n; ++i) {


    for (int w1 = 0; w1 <= 500; ++w1) {
      for (int w2 = 0; w2 <= 500; ++w2) {
        dp[uk ^ 1][w1][w2] = dp[uk][w1][w2];
      }
    }

    for (int w1 = 0; w1 <= 500; ++w1) {
      for (int w2 = 0; w2 <= 500; ++w2) {
        // dp[uk ^ 1][w1][w2] = dp[uk][w1][w2];
        
        if (w1 && a[i].k <= 500)
        uax(dp[uk ^ 1][w1 - 1][w2], dp[uk][w1][w2] + a[i].a - a[i].b * a[i].k);
        if (w2)
        uax(dp[uk ^ 1][w1][w2 - 1], dp[uk][w1][w2] + a[i].a - a[i].b * (w2 - 1));

      }
    }

    uk ^= 1;
  }


  cout << dp[uk][0][0];
}