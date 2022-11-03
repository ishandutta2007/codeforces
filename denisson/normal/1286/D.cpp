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

const int mod = 998244353;

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
int x[100007];
int v[100007];
int p[100007];
int q[100007];

int le[100007];
int ri[100007];
int kek[100007];

struct Tree {
  int t[4 * 100007][2][2];

  void build(int v, int vl, int vr) {
    if (vl == vr) {
      t[v][0][0] = q[vl];
      t[v][0][1] = 0;
      t[v][1][0] = 0;
      t[v][1][1] = p[vl];
    } else {
      int vm = (vl + vr) >> 1;
      build(v * 2 + 1, vl, vm);
      build(v * 2 + 2, vm + 1, vr);

      fill((int*)t[v], (int*)t[v] + 4, 0);

      for (int i1 = 0; i1 < 2; ++i1)
      for (int i2 = 0; i2 < 2; ++i2)
      for (int i3 = 0; i3 < 2; ++i3)
      for (int i4 = 0; i4 < 2; ++i4)
        add(t[v][i1][i4], mult(t[v * 2 + 1][i1][i2], t[v * 2 + 2][i3][i4]));

    }
  }

  void up(int v, int vl, int vr, int pos) {
    if (vl == vr) {

      t[v][0][0] = q[vl];
      t[v][0][1] = 0;
      t[v][1][0] = 0;
      t[v][1][1] = p[vl];
      if (le[vl]) t[v][1][1] = 0;
      if (ri[vl]) t[v][0][0] = 0;

    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) up(v * 2 + 1, vl, vm, pos);
      else up(v * 2 + 2, vm + 1, vr, pos);

      fill((int*)t[v], (int*)t[v] + 4, 0);

      for (int i1 = 0; i1 < 2; ++i1)
      for (int i2 = 0; i2 < 2; ++i2)
      for (int i3 = 0; i3 < 2; ++i3)
      for (int i4 = 0; i4 < 2; ++i4) {
        if (kek[vm] && i2 == 1 && i3 == 0) continue;
        add(t[v][i1][i4], mult(t[v * 2 + 1][i1][i2], t[v * 2 + 2][i3][i4]));
      }

    }
  }

  int getProb() {
    int res = t[0][0][0];
    add(res, t[0][0][1]);
    add(res, t[0][1][0]);
    add(res, t[0][1][1]);
    return res;
  }
} tr;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> v[i] >> p[i];
    p[i] = mult(p[i], bp(100, mod - 2));
    q[i] = 1;
    dec(q[i], p[i]);
  }

  vector<pair<pair<ll, ll>, pair<int, int>>> t;

  for (int i = 0; i + 1 < n; ++i) {
    ll dist = x[i + 1] - x[i];
    t.pb(mp(mp(dist, v[i] + v[i + 1]), mp(i, 0)));
    if (v[i] > v[i + 1]) t.pb(mp(mp(dist, v[i] - v[i + 1]), mp(i, 1)));
    if (v[i] < v[i + 1]) t.pb(mp(mp(dist, v[i + 1] - v[i]), mp(i, 2)));
  }

  sort(all(t), [](const pair<pair<ll, ll>, pair<int, int>>& a,
                  const pair<pair<ll, ll>, pair<int, int>>& b) {
    return a.x.x * b.x.y < a.x.y * b.x.x;
  });

  int res = 0;

  tr.build(0, 0, n - 1);

  for (int i = 0; i < t.size(); ++i) {
    int v = t[i].y.x;

    int s1 = le[v];
    int s2 = ri[v + 1];
    int f1 = ri[v];
    int f2 = le[v + 1];
    if (t[i].y.y == 0) {
      ri[v] = le[v + 1] = 1;
    } else if (t[i].y.y == 1) {
      ri[v] = ri[v + 1] = 1;
    } else {
      le[v] = le[v + 1] = 1;
    }
    tr.up(0, 0, n - 1, v);
    tr.up(0, 0, n - 1, v + 1);

    int new_ti = mult(t[i].x.x, bp(t[i].x.y, mod - 2));
    add(res, mult(tr.getProb(), new_ti));

    le[v] = s1;
    ri[v + 1] = s2;
    ri[v] = f1;
    le[v + 1] = f2;
    tr.up(0, 0, n - 1, v);
    tr.up(0, 0, n - 1, v + 1);

    if (t[i].y.y == 0) {
      kek[v] = 1;
    } else if (t[i].y.y == 1) {
      kek[v] = 0;
      le[v] = 1;
    } else {
      kek[v] = 0;
      ri[v + 1] = 1;
    }
    tr.up(0, 0, n - 1, v);
    tr.up(0, 0, n - 1, v + 1);
  }

  cout << res;
}