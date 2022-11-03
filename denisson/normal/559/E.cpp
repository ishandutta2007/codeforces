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
pair<int, int> a[111];

int dp[107][107][107];

int cross(int x1, int x2, int y1, int y2) {
  return max(0, min(x2, y2) - max(x1, y1));
}

int getBestRi(int v1, int v2) {
  if (a[v1].x + a[v1].y < a[v2].x + a[v2].y) return v2;
  return v1;
}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a + 1, a + 1 + n);
  sort(a + 1, a + 1 + n);

  a[0] = mp(-1e9, 0);
  ++n;

  a[n++] = mp(1e9, 0);


  fill((int*)dp, (int*)dp + 107 * 107 * 107, -1);

  dp[0][0][0] = 0;

  for (int pos = 0; pos < n; ++pos) {
    for (int ri = 0; ri <= pos; ++ri) {
      for (int le = pos; le < n; ++le) if (dp[pos][ri][le] != -1) {

        if (le == pos) {

          for (int new_le = pos + 1; new_le < n; ++new_le) {
            uax(dp[pos][ri][new_le], dp[pos][ri][le]);
          }

        } else {

          int add = 0;
          int x_le = a[pos].x, x_ri = a[pos + 1].x;

          add += cross(x_le, x_ri, a[le].x - a[le].y, a[le].x);
          add += cross(x_le, x_ri, a[ri].x, a[ri].x + a[ri].y);

          int lee = max(  a[ri].x, max( a[le].x - a[le].y, x_le ) );
          int rii = min(  a[ri].x + a[ri].y, min( a[le].x, x_ri ) );

          add -= max(0, rii - lee);

          if (le == pos + 1) {

            uax(dp[pos + 1][ri][le], dp[pos][ri][le] + add);

          } else {

            uax(dp[pos + 1][getBestRi(ri, pos + 1)][le], dp[pos][ri][le] + add);

          }

        }

      }
    }
  }

  int res = 0;

  for (int ri = 0; ri < n; ++ri) uax(res, dp[n - 1][ri][n - 1]);


  cout << res;

}