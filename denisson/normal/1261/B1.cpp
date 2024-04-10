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

struct Tree {

  int t[200007 * 4];

  void up(int v, int vl, int vr, int pos) {
    if (vl == vr) {
      t[v]++;
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) up(v * 2 + 1, vl, vm, pos);
      else up(v * 2 + 2, vm + 1, vr, pos);
      t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
  }

  int get(int v, int vl, int vr, int need) {
    if (vl == vr) return vl;
    int vm = (vl + vr) >> 1;
    if (t[v * 2 + 1] >= need) return get(v * 2 + 1, vl, vm, need);
    return get(v * 2 + 2, vm + 1, vr, need - t[v * 2 + 1]);
  }

} tr;

int n;
int a[200007];

vector<pair<int, int>> z[200007];

int ans[200007];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);

  vector<int> t;

vector<pair<int, int>> d;

  for (int i = 0; i < n; ++i) t.pb(a[i]), d.pb(mp(a[i], -i));

  sort(all(t));
  t.resize(unique(all(t)) - t.begin());


  sort(all(d));
  reverse(all(d));

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int k, pos;
    cin >> k >> pos;
    z[k - 1].pb(mp(pos, i));
  }


  for (int i = 0; i < d.size(); ++i) {

    tr.up(0, 0, n, -d[i].y);

   // per("adas   d", d[i].x, d[i].y);


    for (auto [w1, w2] : z[i]) {
    //  pper(tr.get(0, 0, n, w1));

      ans[w2] = a[tr.get(0, 0, n, w1)];
    }
  }


  for (int i = 0; i < m; ++i) {
    cout << ans[i] << '\n';
  }
}