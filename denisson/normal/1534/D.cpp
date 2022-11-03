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

vector<int> re(int x) {
  cout << "? " << x + 1 << endl;
  vector<int> res(n);
  readArr(all(res));
  return res;
}

int was[2222];

int main() {

  cin >> n;

  if (n == 2) {
    cout << "!\n";
    cout << "1 2" << endl;
    exit(0);
  }

  auto now = re(0);

  int w1 = 0, w2 = 0;
  for (int x : now) if (x % 2 == 0) ++w1; else ++w2;

  int v = 0;

  // per(w1, w2);

  if (w1 > w2) {
    for (int i = 0; i < n; ++i) if (now[i] % 2 == 1) v = i;
    now = re(v);
  }

  vector<pair<int, int> > res;

  was[v] = 1;

  vector<int> st;
  for (int i = 0; i < n; ++i) {
    if (now[i] == 1) res.pb(mp(v, i));
    if (now[i] == 2) st.pb(i), was[i] = 1;
  }
  int uk = 0;

  while (uk < st.size()) {
    int v = st[uk++];
    now = re(v);
    for (int i = 0; i < n; ++i) {
      if (now[i] == 1) res.pb(mp(v, i));
      if (now[i] == 2 && !was[i]) st.pb(i), was[i] = 1;
    }
  }


  cout << "!\n";
  for (auto [w1, w2] : res) cout << w1 + 1 << ' ' << w2 + 1 << endl;
}