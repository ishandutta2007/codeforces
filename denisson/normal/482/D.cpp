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
vector<int> g[100007];
int dp[100007][2];

int d[4][2];
int d2[4][2];


int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x; cin >> x;
    g[x - 1].pb(i - 1);
  }

  for (int i = n - 1; i >= 0; --i) {

    fill((int*)d, (int*)d + 8, (int)0);

    d[0][1]= 1;

    for (int to : g[i]) {

      copy((int*)d, (int*)d + 8, (int*)d2);

      for (int c = 0; c < 2; ++c) {

        for (int w1 = 0; w1 < 4; ++w1) for (int w2 = 0; w2 < 2; ++w2) {
          add(d2[w1 | (1 << w2)][c ^ w2], mult(d[w1][c], dp[to][w2]));
        }

      }

      copy((int*)d2, (int*)d2 + 8, (int*)d);

    }

    for (int c = 0; c < 2; ++c) {
      add(dp[i][c], d[0][c]);
      add(dp[i][c], d[1][c]);
      add(dp[i][c], d[2][c]);
      add(dp[i][c], d[3][c]);
      
      if (c == 1) {

     //   per("=====: ", 2, c, f, d[2][c][f]);

        add(dp[i][c], d[2][c]);
        add(dp[i][c], d[3][c]);

      } else {

        add(dp[i][c], d[1][c]);
        add(dp[i][c], d[3][c]);

      }

    //  per(i, c, dp[i][c]);

    }

  }

  int res = 0;
  add(res, dp[0][0]);
  add(res, dp[0][1]);

  cout << res;

}