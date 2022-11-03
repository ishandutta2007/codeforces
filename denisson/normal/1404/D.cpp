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

vector<int> kek[1000007];

vector<int> g[1000007];

int was[1000007];

int used[1000007];

vector<int> st;
void dfs(int v) {
  was[v] = 1;
  st.pb(v);
  for (int to : g[v]) if (!was[to]) dfs(to);
}

int main(){

  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "First" << endl;
    for (int i = 1; i <= 2 * n; ++i) {
      cout << (i - 1) % n + 1 << ' ';
    }
    cout << endl;
  } else {

    cout << "Second" << endl;

    vector<int> a(2 * n);
    readArr(all(a));

    for (int i = 0; i < 2 * n; ++i) kek[a[i]].pb(i + 1);

    for (int i = 1; i <= n; ++i) {
      g[kek[i][0]].pb(kek[i][1]);
      g[kek[i][1]].pb(kek[i][0]);
      g[i].pb(i + n);
      g[n + i].pb(i);
    }

    ll ss = 0;

    for (int i = 1; i <= 2 * n; ++i) if (!was[i]) {
      dfs(i);

      for (int j = 0; j < st.size(); j += 2) {
        ss += st[j];
        used[st[j]] = 1;
      }
      st.clear();
    }

    vector<int> res;

    if (ss % (2 * n) != 0) {
      for (int i = 1; i <= 2 * n; ++i) if (used[i] == 0) res.pb(i);
    } else {
      for (int i = 1; i <= 2 * n; ++i) if (used[i] == 1) res.pb(i);
    }

    for (int x : res) cout << x << ' ';

  }

}