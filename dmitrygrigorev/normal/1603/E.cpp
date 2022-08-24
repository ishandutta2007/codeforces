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

int mod = 1000000007;

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

const int N = 207;
int C[N][N];

int dp[N][N][N];

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n >> mod;

  C[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    C[i][0] = 1, C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i-1][j];
      add(C[i][j], C[i-1][j-1]);
    }
  }

  int ans = 1;

  for (int min_element = 1; min_element <= n + 1; ++min_element) {
    
    for (int i = min_element; i <= n + 1; ++i) {
      int can_take = min_element / (i - min_element + 1);
      for (int take = max(0, n - can_take); take <= n; ++take) {
        for (int excess = 0; excess <= min_element; ++excess) {
          dp[i][take][excess] = 0;
        }
      }
    }

    for (int take = 1; take <= n; ++take) {
      add(dp[min_element][take][0], C[n][take]);
    }

    for (int i = min_element + 1; i <= n + 1; ++i) {
      int can_take = min_element / (i - min_element);
      for (int take = max(1, n - can_take); take < n; ++take) {
        for (int excess = 0; excess <= min_element; ++excess) {
          if (!dp[i - 1][take][excess]) continue;
          if (min_element * (i - 1) < min_element * take + excess) continue;
          for (int want = 0; want <= can_take && excess + (i - min_element) * want <= min_element; ++want) {
            //if (min_element == 2 && i == 3 && take == 1 && excess == 0) per("???", want);
            int new_excess = excess + (i - min_element) * want;
            if (min_element * i < min_element * (take + want) + new_excess) break;

            add(dp[i][take + want][new_excess], mult(dp[i - 1][take][excess], C[n - take][want]));
          }
        }
      }
    }
/*
    if (min_element == 2) {
      per(dp[2][1][0]);
      per(dp[3][2][1]);
    }
*/
    for (int excess = 0; excess <= min_element; ++excess) {
      add(ans, dp[n + 1][n][excess]);
    } 
  }

  cout << ans;

}