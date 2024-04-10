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

int n, m;
vector<vector<int>> a;
vector<vector<int>> b;
vector<vector<char>> c, dd;

int get(int x1, int x2, int y1, int y2) {
  int res = a[x2][y2];

  if (x1) res -= a[x1 - 1][y2];
  if (y1) res -= a[x2][y1 - 1];
  if (x1 && y1) res += a[x1 - 1][y1 - 1];

  return res;
}

bool can(int d) {
  
  b = a;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) b[i][j] = 0, c[i][j] = '.';


  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x1 = i - d;
      int x2 = i + d;
      int y1 = j - d;
      int y2 = j + d;
      
      if (min(x1, y1) >= 0 && x2 < n && y2 < m) {

       // per(i, j, get(x1, x2, y1, y2));

        if (get(x1, x2, y1, y2) == (2 * d + 1) * (2 * d + 1)) {
          c[i][j] = 'X';
          
          b[x1][y1]++;

          if (x2 + 1 < n) b[x2 + 1][y1]--;
          if (y2 + 1 < m) b[x1][y2 + 1]--;
          if (x2 + 1 < n && y2 + 1 < m) b[x2 + 1][y2 + 1]++;

        }
      }

    }
  }


  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {

      if (i) b[i][j] += b[i - 1][j];
      if (j) b[i][j] += b[i][j - 1];
      if (i && j) b[i][j] -= b[i - 1][j - 1];
    

      if (b[i][j] == 0 && dd[i][j] == 'X') return 0;
      if (b[i][j] == 1 && dd[i][j] == '.') return 0;

    }
  }

  return 1;

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  a.resize(n);
  dd.resize(n);
  for (int i = 0; i < n; ++i) a[i].resize(m);
  for (int i = 0; i < n; ++i) dd[i].resize(m);
    c = dd;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    char c; cin >> c;
    a[i][j] = c == 'X';
    dd[i][j] = c;

    if (i) a[i][j] += a[i - 1][j];
    if (j) a[i][j] += a[i][j - 1];
    if (i && j) a[i][j] -= a[i - 1][j - 1];

  }

  int vl = 0, vr = min(n, m) + 7;
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    if (can(vm)) vl = vm; else vr = vm;
  }  

  can(vl);

  cout << vl << "\n";

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << c[i][j];
    }
    cout << "\n";
  }

}