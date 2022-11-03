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

const int N = 507;
const int INF = 1e9 + 7;

int dp[2][N][N];

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  vector<vector<int>> gr(m + 1, vector<int>(2, 0));
  for (int len = 0; len <= m; ++len) {
    for (int it = 0; it < 2; ++it) {
      string tt = t.substr(0, len);
      tt += (char) ('0' + it);
      int mx = 0;
      
      for (int len1 = 0; len1 <= tt.size(); ++len1) {
        if (t.substr(0, len1) == tt.substr(tt.size() - len1, len1)) {
          uax(mx, len1);
        }
      }
      gr[len][it] = mx;
      //per(len, it, gr[len][it]);
    }
  }
  int uk = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      dp[0][i][j] = INF;
    }
  }
  dp[0][0][0] = 0;
  
  for (int i = 0; i < n; ++i) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        dp[uk ^ 1][i][j] = INF;
      }
    }
    for (int occ = 0; occ < N; ++occ) {
      for (int len = 0; len <= m; ++len) {
        if (dp[uk][occ][len] == INF) continue;
        
        for (int it = 0; it < 2; ++it) {
          int add = (s[i] - '0') != it;
          
          int nxt = gr[len][it];
          int nocc = occ + (nxt == m);

          uin(dp[uk ^ 1][nocc][nxt], dp[uk][occ][len] + add);
          //per(i, nocc, nxt, dp[uk ^ 1][nocc][nxt]);
        }
      }
    }
    uk ^= 1;
  }
  for (int k = 0; k <= n - m + 1; ++k) {
    int res = INF;
    for (int lst = 0; lst <= m; ++lst) {
      uin(res, dp[uk][k][lst]);
    }
    cout << (res == INF ? -1 : res) << " ";
  }
  cout << "\n";
}