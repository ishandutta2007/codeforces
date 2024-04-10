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
int a[1111][1111];
int b[1111][1111];

uint16_t f[10][10][1001][1001];
int lg[1111];

uint16_t get(int x1, int x2, int y1, int y2) {
  int l1 = lg[x2 - x1 + 1];
  int l2 = lg[y2 - y1 + 1];
  return max(max(f[l1][l2][x1][y1], f[l1][l2][x2 - (1 << l1) + 1][y1]),
             max(f[l1][l2][x1][y2 - (1 << l2) + 1],
                 f[l1][l2][x2 - (1 << l1) + 1][y2 - (1 << l2) + 1]));
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (a[i][j]) {
        b[i][j] = min(b[i + 1][j], min(b[i][j + 1], b[i + 1][j + 1])) + 1;
      } else b[i][j] = 0;
    }
  }

  for (int i = 2; i < 1111; ++i) lg[i] = lg[i / 2] + 1;

  for (int l1 = 0; l1 < 10; ++l1)
  for (int l2 = 0; l2 < 10; ++l2)
  for (int vl1 = 0; ; ++vl1){
    int len1 = 1 << l1;
    int vr1 = vl1 + len1 - 1;
    if (vr1 >= n) break;
    
    for (int vl2 = 0; ; ++vl2) {
      int len2 = 1 << l2;
      int vr2 = vl2 + len2 - 1;
      if (vr2 >= m) break;

      if (l1 == 0 && l2 == 0) {
        f[0][0][vl1][vl2] = b[vl1][vl2];
      } else if (l1 > 0) {
        f[l1][l2][vl1][vl2] = max(f[l1 - 1][l2][vl1][vl2], f[l1 - 1][l2][vl1 + len1 / 2][vl2]);
      } else {
        f[l1][l2][vl1][vl2] = max(f[l1][l2 - 1][vl1][vl2], f[l1][l2 - 1][vl1][vl2 + len2 / 2]);
      }

    }
  }

  int m; cin >> m;
  while (m--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1; --x2; --y1; --y2;

    int vl = 0, vr = min(x2 - x1 + 1, y2 - y1 + 1) + 1;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (get(x1, x2 - vm + 1, y1, y2 - vm + 1) >= vm) vl = vm; else vr = vm;
    }

    cout << vl << "\n";

  }

}