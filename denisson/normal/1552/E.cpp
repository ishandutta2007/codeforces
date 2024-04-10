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

int n, k;
int a[10007];

int was[10007];

int used[111];

pair<int, int> res[111];

vector<int> pos[111];

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k;
  readArr(a, a + n * k);

  for (int i = 0; i < n * k; ++i) pos[a[i] - 1].pb(i);

  int ma = (n + k - 1 - 1) / (k - 1);

  for (int it = 0; it < n; ++it) {
    int v = -1;
    int ri = 1e9, le;

    for (int i = 0; i < n; ++i) if (!used[i]) {

      for (int j = 1; j < pos[i].size(); ++j) {

        int can = 1;

        for (int s = pos[i][j - 1]; s <= pos[i][j]; ++s) if (was[s] >= ma) {
          can = 0;
          break;
        }

        if (can) {
          if (pos[i][j] < ri) {
            v = i;
            le = pos[i][j - 1];
            ri = pos[i][j];
            break;
          }
        }

      }

    }

    for (int i = le; i <= ri; ++i) was[i]++;

    res[v] = mp(le, ri);

    used[v] = 1;

  }

  for (int i = 0; i < n; ++i) cout << res[i].x + 1 << ' ' << res[i].y + 1 << "\n";
}