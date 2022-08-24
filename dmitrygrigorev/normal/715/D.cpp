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

__int128 bin(int n, int k) {

  __int128 ans = 1;
  int a = 1, b = 1, c = 1;
  while (a <= n || b <= k || c <= n - k) {
    if (a <= n) ans *= (a++);
    if (b <= k && ans % b == 0) ans /= (b++);
    if (c <= n - k && ans % c == 0) ans /= (c++);
  }

  return ans;

}

const int N = 67;

__int128 dp[N][N];
bool rec[N][N][2];

__int128 res(int sx, int sy, int n) {

  dp[sx+0][sy+0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 && j == 0) continue;
      dp[sx+i][sy+j] = 0;
      if (i > 0 && !rec[sx+i][sy+j][0]) dp[sx+i][sy+j] += dp[sx+i-1][sy+j];
      if (j > 0 && !rec[sx+i][sy+j][1]) dp[sx+i][sy+j] += dp[sx+i][sy+j-1];
    }
  }

  return dp[sx+n - 1][sy+n - 1];

}

const int ALLOW = 1000;

int main(){
#ifdef LOCAL
	freopen("K_input.txt", "r", stdin);
	//freopen("K_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  ll qqqqqq;
  cin >> qqqqqq;
  __int128 t = qqqqqq;

  int add = 0;

  if (t > 7100) {
    add = 7000;
    t -= 7000;
  }

  else if (t > 14) {
    add = 14;
    t -= 14;
  }


  int a = 1;
  while (bin(2*a - 2, a - 1) < t) {
    a++;
  }

  auto ways = bin(2 * a - 2, a - 1);

  for (int i = 0; i < a; ++i) {
    rec[i][a][1] = true;
    if (i + 1 != a) rec[a][i][0] = true;
  }

  for (int i = a; i < 49; ++i) {
    rec[i][a][1] = true;
  }


  while (ways > t) {


    int v = -1, b = -1, c = -1;
    __int128 best = ways;

    for (int i = 1; i < a; ++i) for (int j = 0; j < a; ++j) for (int e = 0; e < 2; ++e) {
      if (rec[i][j][e]) continue;
      rec[i][j][e] = true;
      auto R = res(0, 0, a);
      if (R >= t && R < best) {
        best = R;
        v = i, b = j, c = e;
      }
      rec[i][j][e] = false;
    }

    if (v == -1) break;

    ways = best;
    rec[v][b][c] = true;

  }

  if (add) t = add - (ways - t);
  else t = 0;

  if (t > 0) {

    int tadd = 0;
    if (t > 20) tadd = 20;
    t -= tadd;

    rec[0][a][1] = false;
    auto ddd = a;
    a = 1;
    while (bin(2*a - 2, a - 1) < t) {
      a++;
    }

    auto ways = bin(2 * a - 2, a - 1);

    for (int i = 0; i < a; ++i) {
      rec[i][a+ddd][1] = true;
      if (i + 1 < a) rec[a][i+ddd][0] = true;
    }

    for (int i = a; i < 49; ++i) {
      rec[i][a+ddd][1] = true;
    }


    while (ways > t) {

      int v = -1, b = -1, c = -1;
      __int128 best = ways;

      for (int i = 1; i < a; ++i) for (int j = 0; j < a; ++j) for (int e = 0; e < 2; ++e) {
        if (rec[i][j+ddd][e]) continue;
        rec[i][j+ddd][e] = true;
        auto R = res(0, ddd, a);
        if (R >= t && R < best) {
          best = R;
          v = i, b = j, c = e;
        }
        rec[i][j+ddd][e] = false;
      }

      if (v == -1) break;

      ways = best;
      rec[v][b+ddd][c] = true;

    }

    if (tadd) t = tadd - (ways - t);
    else t = 0;

    if (t > 0) {

      rec[0][a+ddd][1] = false;
      ddd += a;
      a = 1;
      while (bin(2*a - 2, a - 1) < t) {
        a++;
      }

      auto ways = bin(2 * a - 2, a - 1);

      for (int i = 0; i < a; ++i) {
        rec[i][a+ddd][1] = true;
        if (i + 1 < a) rec[a][i+ddd][0] = true;
      }

      for (int i = a; i < 49; ++i) {
        rec[i][a+ddd][1] = true;
      }


      while (ways > t) {

        int v = -1, b = -1, c = -1;
        __int128 best = ways;

        for (int i = 0; i < a; ++i) for (int j = 0; j < a; ++j) for (int e = 0; e < 2; ++e) {
          if (rec[i][j+ddd][e]) continue;
          rec[i][j+ddd][e] = true;
          auto R = res(0, ddd, a);
          if (R >= t && R < best) {
            best = R;
            v = i, b = j, c = e;
          }
          rec[i][j+ddd][e] = false;
        }

        if (v == -1) break;

        ways = best;
        rec[v][b+ddd][c] = true;

      }
    }
  }

  //per((ll) res(0, 0, 50));
  //exit(0);

  //if (qqqqqq != ((ll) res(0, 0, 50))) cout << "GG";

  cout << 50 << " " << 50 << endl;
  vector<pair<pair<int, int>, pair<int, int> > > ans;
  for (int i = 0; i < 50; ++i) for (int j = 0; j < 50; ++j) {
    if (i > 0 && rec[i][j][0]) ans.pb(mp(mp(i-1, j), mp(i, j)));
    if (j > 0 && rec[i][j][1]) ans.pb(mp(mp(i, j-1), mp(i, j)));
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x.x.x + 1 << " " << x.x.y+1 << " " << x.y.x + 1 << " " << x.y.y+1 << endl;

}