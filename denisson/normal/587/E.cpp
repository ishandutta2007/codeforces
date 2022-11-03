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
int a[200007];
 
struct Tree {
 
  int t[4 * 200007];
 
  void build(int v, int vl, int vr) {
    if (vl == vr) {
      t[v] = a[vl];
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
      t[v] = 0;
    }
  }
 
  void up(int v, int vl, int vr, int l, int r, int val) {
    if (r < vl || l > vr) return;
    if (vl >= l && vr <= r) {
      t[v] ^= val;
    } else {
      int vm = (vl + vr) >> 1;
      up(v * 2 + 1, vl, vm, l, r, val);
      up(v * 2 + 2, vm + 1, vr, l, r, val);
    }
  }
 
  int get(int v, int vl, int vr, int pos) {
    if (vl == vr) return t[v];
    int vm = (vl + vr) >> 1;
    if (pos <= vm) return get(v * 2 + 1, vl, vm, pos) ^ t[v];
    return get(v * 2 + 2, vm + 1, vr, pos) ^ t[v];
  }
 
} tr;
 
int b[200007];
 
vector<int> merg(vector<int> a, const vector<int>& b) {
  for (int x : b) {
    int uk = 0;
    while (x) {
      while (uk < a.size() && (a[uk] & -a[uk]) != (x & -x)) ++uk;
      if (uk == a.size()) break;
      x ^= a[uk]; ++uk;
    }
    if (x == 0) continue;
 
    int v = a.size();
    for (int i = 0; i < a.size(); ++i) {
      if ((a[i] & -a[i]) > (x & -x)) {
        v = i; break;
      }
    }
 
    a.pb(0);
    for (int i = (int)a.size() - 1; i > v; --i) a[i] = a[i - 1];
    a[v] = x;
 
  }
 
  return a;
}
 
struct Tree2 {
 
  vector<int> t[4 * 200007];
 
  void build(int v, int vl, int vr) {
    if (vl == vr) {
      if (b[vl] != 0) t[v].pb(b[vl]);
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
      t[v] = merg(t[v * 2 + 1], t[v * 2 + 2]);
    }
  }
 
  void up(int v, int vl, int vr, int pos, int val) {
    if (pos > vr) return;
    if (vl == vr) {
      b[vl] ^= val;
      t[v].clear();
      if (b[vl] != 0) t[v].pb(b[vl]);
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) up(v * 2 + 1, vl, vm, pos, val);
      else up(v * 2 + 2, vm + 1, vr, pos, val);
      t[v] = merg(t[v * 2 + 1], t[v * 2 + 2]);
 
    //  per(vl, vr, t[v], t[v * 2 + 1], t[v * 2 + 2]);
 
    }
  }
 
  vector<int> get(int v, int vl, int vr, int l, int r) {
    if (r < vl || l > vr) return vector<int>{};
    if (vl >= l && vr <= r) return t[v];
    int vm = (vl + vr) >> 1;
    return merg(get(v * 2 + 1, vl, vm, l, r), get(v * 2 + 2, vm + 1, vr, l, r));
  }
 
} tral;
 
int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int q;
  cin >> n >> q;
  readArr(a, a + n);
  for (int i = 0; i + 1 < n; ++i) b[i] = a[i] ^ a[i + 1];
 
  tr.build(0, 0, n - 1);
  if (n - 2 >= 0) 
  tral.build(0, 0, n - 2);
 
  while (q--) {
    int ty;
    cin >> ty;
    if (ty == 1) {
 
      int vl, vr, x;
      cin >> vl >> vr >> x;
      --vl; --vr;
 
      tr.up(0, 0, n - 1, vl, vr, x);

      if (n - 2 >= 0) {
        tral.up(0, 0, n - 2, vr, x);
        if (vl)
        tral.up(0, 0, n - 2, vl - 1, x);
      }
 
    } else {
 
      int vl, vr;
      cin >> vl >> vr;
      --vl; --vr;
 
      int res = 0;
 
      int x = tr.get(0, 0, n - 1, vl);
      if (vl == vr) {
        res = x != 0;
      } else {
        auto now = tral.get(0, 0, n - 2, vl, vr - 1);
    
     //   pper(now);
     //   pper(x);
 
        auto now2 = merg(now, vector<int>{x});
        res = now2.size();
      }
 
      cout << (1 << res) << "\n";
 
    }
 
  }
 
}