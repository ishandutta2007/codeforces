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

char a[55][55];
int was[55][55];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    int w1 = -1, w2 = -1;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] != '.') w1 = i, w2 = j;
      was[i][j] = 0;
    }
    if (w1 == -1) {
      a[0][0] = 'W'; w1 = w2 = 0;
    }

    vector<pair<int, int>> t;
    t.pb(mp(w1, w2));
    was[w1][w2] = 1;
    int uk = 0;
    int bad = 0;
    while (uk < t.size()) {
      auto [x, y] = t[uk++];
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (a[nx][ny] == '.') {
          if (a[x][y] == 'W') a[nx][ny] = 'R';
          if (a[x][y] == 'R') a[nx][ny] = 'W';
          t.pb(mp(nx, ny)); was[nx][ny] = 1;
        } else {
          if (a[x][y] == a[nx][ny]) bad = 1;
          if (!was[nx][ny]) {
            t.pb(mp(nx, ny)); was[nx][ny] = 1;
          }
        }
      }
    }

    if (bad) {
      cout << "NO\n";
      continue;
    } else cout << "YES\n";

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << a[i][j];
      }
      cout << "\n";
    }

  }

}