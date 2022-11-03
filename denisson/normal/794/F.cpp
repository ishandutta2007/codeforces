#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
 
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
 
int n, q;
int a[100007];
 
ll tmp[10];
 
ll tot[10];
 
struct Tree {
 
  ll sum[4 * 4 * 100007][10];
  uint8_t to[4 * 4 * 100007][10];
  bool need[4 * 4 * 100007];
 
  void build(int v, int vl, int vr) {
    for (int i = 0; i < 10; ++i) to[v][i] = i;
    if (vl == vr) {
 
      ll step = 1;
      while (a[vl] > 0) {
 
        sum[v][a[vl] % 10] += step;
 
        step *= 10;
        a[vl] /= 10;
      }
 
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);
      for (int i = 0; i < 10; ++i) sum[v][i] = sum[v * 2 + 1][i] + sum[v * 2 + 2][i];
    }
  }
 
  void push(int v) {
    if (!need[v]) return;
    need[v] = 0;
 
    need[v * 2 + 1] = 1;
    need[v * 2 + 2] = 1;
 
 
    for (int i = 0; i < 10; ++i) {
      to[v * 2 + 1][i] = to[v][to[v * 2 + 1][i]];
      to[v * 2 + 2][i] = to[v][to[v * 2 + 2][i]];
    }
 
    fill(tmp, tmp + 10, 0);
 
    for (int i = 0; i < 10; ++i) {
      tmp[to[v][i]] += sum[v][i];
      to[v][i] = i;
    }
 
    copy(tmp, tmp + 10, sum[v]);
  }
 
  void get(int v, int vl, int vr, int l, int r) {
    push(v);
    if (r < vl || l > vr) return; // emp;
    if (vl >= l && vr <= r) {
      for (int i = 0; i < 10; ++i) tot[i] += sum[v][i];
      return;
     // return cnt[v];
    }
    int vm = (vl + vr) >> 1;
    get(v * 2 + 1, vl, vm, l, r);
    get(v * 2 + 2, vm + 1, vr, l, r);
  }
 
  void up(int v, int vl, int vr, int l, int r, int from, int tto) {
    push(v);
    if (r < vl || l > vr) return;
    if (vl >= l && vr <= r) {
      to[v][from] = tto;
      need[v] = 1;
      push(v);
    } else {
      int vm = (vl + vr) >> 1;
      up(v * 2 + 1, vl, vm, l, r, from, tto);
      up(v * 2 + 2, vm + 1, vr, l, r, from, tto);
      for (int i = 0; i < 10; ++i) sum[v][i] = sum[v * 2 + 1][i] + sum[v * 2 + 2][i];
    }
  }
 
} tr;
 
int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int q;
 
  cin >> n >> q;
  readArr(a, a + n);
 
  tr.build(0, 0, n - 1);
 
  while (q--) {
 
    int ty;
    cin >> ty;
    if (ty == 1) {
 
      int vl, vr, x, y;
      cin >> vl >> vr >> x >> y;
      --vl; --vr;
 
      if (x == y) continue;
 
      tr.up(0, 0, n - 1, vl, vr, x, y);
 
    } else {
 
      int vl, vr;
      cin >> vl >> vr;
      --vl; --vr;
      ll res = 0;
 
      fill(tot, tot + 10, 0);
      tr.get(0, 0, n - 1, vl, vr);
 
      for (int j = 0; j < 10; ++j) res += j * tot[j];
 
      cout << res << "\n";
    }
 
  }
 
}