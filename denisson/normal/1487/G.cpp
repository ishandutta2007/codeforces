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

int n;
int cnt[26];

int dp[2][204][204][3];

int f1[204][204];
int f2[204][204];


class NTT{
public:
  #define db long double 
  #define ll long long
  const static int mod = 998244353;
  const static int root = 646; // 646^(2^20) == 1 (998244353)
  const static int rev_root = 208611436;
  const static int root_deg = 1 << 20;
  const static int MAX_SIZE = 1 << 21;

  void add(int &a, int b){
    a += b;
    if (a < 0) a += mod;
    if (a >= mod) a -= mod;
  }

  int sum(int a, int b){
    add(a, b);
    return a;
  }

  int mult(int a, int b){
    return a * (ll)b % mod;
  }

  int bp(int a, int n) {
    int res = 1;
    while (n) {
      if (n & 1) res = mult(res, a);
      a = mult(a, a);
      n >>= 1;
    }
    return res;
  }

  int rev(int a){
    return bp(a, mod - 2);
  }

  int n;
  int a[MAX_SIZE * 2 + 7], b[MAX_SIZE * 2 + 7];

  int getReverse(int a, int k){
    int ans = 0;
    for (int i = 0; i < k; i++) if ((a >> i) & 1) ans ^= (1 << (k - i - 1));
    return ans;
  }

  void ntt(int *a, int type){
    int k = -1;
    for (int i = 0; i < 25; i++) if ((n >> i) & 1){ 
      k = i;
      break;
    }
    for (int i = 0; i < n; i++){
      int j = getReverse(i, k);
      if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len *= 2){
      int w = bp(root, root_deg / len);
      if (type == -1) w = bp(rev_root, root_deg / len);
      for (int i = 0; i < n; i += len){
        int g = 1;
        for (int j = 0; j < len / 2; j++){
          int x = a[i + j];
          int y = mult(a[i + j + len / 2], g);
          a[i + j] = sum(x, y);
          a[i + j + len / 2] = sum(x, mod - y);
          g = mult(g, w);
        }
      }
    }
    if (type == -1){ 
      int rev_n = rev(n);
      for (int i = 0; i < n; i++) a[i] = mult(a[i], rev_n);
    }
  }

  vector<int> mult(int* w1, int* w2, int sz1, int sz2){
    n = 1;
    while(n < sz1 + sz2) n *= 2;
    
    /* for (int i = 0; i < w1.size(); i++){
      a[i] = w1[i];
      a[i] %= mod;
      if (a[i] < 0) a[i] += mod;
    }
    for (int i = 0; i < w2.size(); i++){
      b[i] = w2[i];
      b[i] %= mod;
      if (b[i] < 0) b[i] += mod;
    } */

    std::copy(w1, w1 + sz1, a);
    std::copy(w2, w2 + sz2, b);
    std::fill(a + sz1, a + n, 0);
    std::fill(b + sz2, b + n, 0);

    ntt(a, 1);
    ntt(b, 1);
    for (int i = 0; i < n; i++) a[i] = mult(a[i], b[i]);
    ntt(a, -1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) ans[i] = a[i];
    while(ans.size() && ans.back() == 0) ans.pop_back();
    return ans;
  }
} nt;

int ans[205][205];

int g1[205];
int g2[205];

int dp2[2][205][2];

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(cnt, cnt + 26);

  int n1 = (n + 1) >> 1;
  int n2 = n - n1;

  int res = mult(26, bp(25, n1 - 1));
  res = mult(res, mult(26, bp(25, n2 - 1)));


  int uk = 0;

  dp[0][0][0][2] = 24;
  dp[0][1][0][0] = 1;
  dp[0][0][1][1] = 1;

  for (int i = 1; i < 202; ++i) {

    for (int w1 = 0; w1 <= i + 1; ++w1) {
      for (int w2 = 0; w2 <= i + 1; ++w2) {
        for (int last = 0; last < 3; ++last) {
          dp[uk ^ 1][w1][w2][last] = 0;
        }
      }
    }

    if (i == n1) {
      for (int w1 = 0; w1 < 202; ++w1) for (int w2 = 0; w2 < 202; ++w2) {
        add(f1[w1][w2], dp[uk][w1][w2][0]);
        add(f1[w1][w2], dp[uk][w1][w2][1]);
        add(f1[w1][w2], dp[uk][w1][w2][2]);
      }
    }

    if (i == n2) {

      for (int w1 = 0; w1 < 202; ++w1) for (int w2 = 0; w2 < 202; ++w2) {
        add(f2[w1][w2], dp[uk][w1][w2][0]);
        add(f2[w1][w2], dp[uk][w1][w2][1]);
        add(f2[w1][w2], dp[uk][w1][w2][2]);
      }
    }

    for (int w1 = 0; w1 <= i; ++w1) {
      for (int w2 = 0; w2 <= i; ++w2) {

        add(dp[uk ^ 1][w1][w2][2], mult(dp[uk][w1][w2][2], 23));
        add(dp[uk ^ 1][w1][w2][2], mult(dp[uk][w1][w2][0], 24));
        add(dp[uk ^ 1][w1][w2][2], mult(dp[uk][w1][w2][1], 24));

        add(dp[uk ^ 1][w1 + 1][w2][0], dp[uk][w1][w2][1]);
        add(dp[uk ^ 1][w1 + 1][w2][0], dp[uk][w1][w2][2]);

        add(dp[uk ^ 1][w1][w2 + 1][1], dp[uk][w1][w2][0]);
        add(dp[uk ^ 1][w1][w2 + 1][1], dp[uk][w1][w2][2]);

      }
    }

    uk ^= 1;
  }

  for (int w1 = 0; w1 <= 102; ++w1) {
    for (int w2 = 0; w2 <= 102; ++w2) {
      auto now = nt.mult(f1[w1], f2[w2], 102, 102);
      for (int i = 0; i < min((int)now.size(), 205); ++i) add(ans[w1 + w2][i], now[i]);
    }
  }

 // cout << f1[5][2] << endl;

 // cout << ans[1][2] << ' ' << ans[2][1] << endl;

  for (int c1 = 0; c1 < 26; ++c1) for (int c2 = c1 + 1; c2 < 26; ++c2) {
    for (int i = cnt[c1] + 1; i <= 202; ++i) for (int j = cnt[c2] + 1; j <= 202; ++j) add(res, ans[i][j]);
  }

  uk = 0;

  dp2[0][0][1] = 25;
  dp2[0][1][0] = 1;

  for (int i = 1; i < 202; ++i) {
    for (int w = 0; w <= i + 1; ++w) dp2[uk ^ 1][w][0] = dp2[uk ^ 1][w][1] = 0;


    if (i == n1) {
      for (int w = 0; w < 202; ++w) {
        add(g1[w], dp2[uk][w][0]);
        add(g1[w], dp2[uk][w][1]);
      }
    }

    if (i == n2) {
      for (int w = 0; w < 202; ++w) {
        add(g2[w], dp2[uk][w][0]);
        add(g2[w], dp2[uk][w][1]);
      }
    }

    for (int w = 0; w <= i; ++w) {
      add(dp2[uk ^ 1][w][1], mult(dp2[uk][w][1], 24));
      add(dp2[uk ^ 1][w][1], mult(dp2[uk][w][0], 25));
        
      add(dp2[uk ^ 1][w + 1][0], dp2[uk][w][1]);

    }

    uk ^= 1;

  }

  for (int c = 0; c < 26; ++c) {
    for (int w1 = 0; w1 <= 202; ++w1) for (int w2 = 0; w2 <= 202; ++w2) if (w1 + w2 > cnt[c]) {

    //  if (mult(g1[w1], g2[w2]) != 0)
  //    per(c, w1, w2, mult(g1[w1], g2[w2]));

      dec(res, mult(g1[w1], g2[w2]));
    }
  }

  cout << res;

}