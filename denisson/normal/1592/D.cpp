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
vector<int> g[1007];

vector<int> oo;

int pp[10011];

void dfs(int v, int p = -1) {
  oo.pb(v);
  pp[v] = p;
  for (int to : g[v]) if (to != p) dfs(to, v);
}

int ask(vector<int> d) {
  cout << "? " << d.size() << ' ';
  for (int x : d) cout << x + 1 << ' ';
    cout << endl;
  int x;
  cin >> x; return x;
}

int main(){


  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int w1, w2;
    cin >> w1 >> w2;
    --w1; --w2;
    g[w1].pb(w2);
    g[w2].pb(w1);
  }

  vector<int> r(n);
  for (int i = 0; i < n; ++i) r[i] = i;
  int ma = ask(r);
  
  dfs(0);

  //pper(oo);

  int vl = 1, vr = n;
  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    r.clear();
    for (int i = 0; i < vm; ++i) r.pb(oo[i]);
    if (ask(r) == ma) vr = vm; else vl = vm;
  }

  cout << "! " << oo[vr - 1] + 1 << ' ' << pp[oo[vr - 1]] + 1 << endl;
}