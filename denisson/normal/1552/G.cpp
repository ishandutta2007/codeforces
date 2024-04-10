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
vector<int> a[17];
 
int t[11][44];
 
void go(int v) {
  if (v == k) {
/*
    for (int i = 0; i < n; ++i) {
      cout << t[v][i] << ' ';
    }
    cout << endl; */
 
    for (int i = 0; i < n; ++i) {
      if (t[v][i] == -1) {
        cout << "REJECTED"; exit(0);
      }
      if (i + 1 < n && t[v][i] > t[v][i + 1]) {
        cout << "REJECTED"; exit(0);
      }
    }
  } else {
    int now = 0;
 
    int w0 = 0, w1 = 0;
 
    for (int x : a[v]) now += t[v][x] == -1, w0 += t[v][x] == 0, w1 += t[v][x] == 1;
 
 
    for (int c0 = 0; c0 <= now; ++c0) {
      copy(t[v], t[v] + n, t[v + 1]);
 
      for (int i = 0; i < a[v].size(); ++i) {
        if (i < c0 + w0) {
          t[v + 1][a[v][i]] = 0;
        } else {
          t[v + 1][a[v][i]] = 1;
        }
      }
 
      go(v + 1);
 
    }
 
  }
}
 
int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int sz;
    cin >> sz;
    a[i].resize(sz);
    for (int j = 0; j < sz; ++j) cin >> a[i][j], --a[i][j];
  }
 
  if (n == 1) {
    cout << "ACCEPTED"; exit(0);
  }
 
  for (int i = 0; i < n; ++i) t[0][i] = -1;
 
  go(0);
 
  cout << "ACCEPTED";
}