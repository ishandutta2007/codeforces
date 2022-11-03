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


int n;
vector<pair<int, int> > g[500007];
int w[500007];

void calcW(int v) {
  w[v] = 1;
  for (auto [to, c] : g[v]) {
    calcW(to);
    w[v] += w[to];
  }
}

const int INF = 1e9 + 7;
int add = 0;
int ma[1 << 22];

int ans[500007];

void do_clear(int v, int mask) {
  ma[mask] = -INF;
  for (auto [to, c] : g[v]) do_clear(to, mask ^ (1 << c));
}

void heh(int v, int mask, int root, int len = 1) {
  uax(ans[root], add + len + ma[mask]);
  for (int i = 0; i < 22; ++i) uax(ans[root], add + len + ma[mask ^ (1 << i)]);
  for (auto [to, c] : g[v]) heh(to, mask ^ (1 << c), root, len + 1);
}

void up(int v, int mask, int len = 1) {
  uax(ma[mask], -add + len);
  for (auto [to, c] : g[v]) up(to, mask ^ (1 << c), len + 1);
}

void go(int v, int mask = 0) {

  vector<pair<int, pair<int, int>> > d;
  for (auto [to, c] : g[v]) d.pb(mp(w[to], mp(to, c)));
  sort(all(d));
  
  for (int i = 0; i + 1 < d.size(); ++i) go(d[i].y.x, mask ^ (1 << d[i].y.y)), do_clear(d[i].y.x, mask ^ (1 << d[i].y.y)), add = 0;



  if (d.size() != 0) {

    go(d.back().y.x, mask ^ (1 << d.back().y.y));
    ++add;

//    per(v, add, mask, ma[1]);

    for (int i = 0; i + 1 < d.size(); ++i) heh(d[i].y.x, mask ^ (1 << d[i].y.y), v), up(d[i].y.x, mask ^ (1 << d[i].y.y));

  }

  uax(ans[v], add + ma[mask]);
  for (int i = 0; i < 22; ++i) uax(ans[v], add + ma[mask ^ (1 << i)]);
  uax(ma[mask], -add);


}


void dfs(int v) { 
  for (auto [to, c] : g[v]) {
    dfs(to);
    uax(ans[v], ans[to]);
  }
}

int main() {
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  fill(ma, ma + (1 << 22), -INF);

  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x; char c; cin >> x >> c;
    g[x - 1].pb(mp(i - 1, c - 'a'));
  }

  calcW(0);

  go(0);

  dfs(0);

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }

}