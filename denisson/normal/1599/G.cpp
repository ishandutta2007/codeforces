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

db dist(pair<int, int> a, pair<int, int> b) {

  ll x = a.x - b.x;
  ll y = a.y - b.y;

  return sqrt((db) x * x + y * y);

}

int main(){
#ifdef LOCAL
  freopen("G_input.txt", "r", stdin);
  //freopen("G_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<pair<int, int> > pts(n);
  for (auto &x : pts) cin >> x.x >> x.y;

  pair<int, int> p = pts[k - 1];

  pts.resize(unique(all(pts)) - pts.begin());
  n = pts.size();

  vector<pair<int, int> > line;
  pair<int, int> special;

  for (int i = 0; i < n; ++i) {
    map<pair<int, int>, vector<pair<int, int> > > mm;
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      int X = pts[j].x - pts[i].x, Y = pts[j].y - pts[i].y;
      int G = gcd(abs(X), abs(Y));

      X /= G, Y /= G;
      if (X < 0) {
        X *= -1, Y *= -1;
      }
      else if (X == 0 && Y < 0) {
        Y *= -1;
      }

      //per(mp(X, Y));

      mm[mp(X, Y)].pb(pts[j]);
      if (mm.size() > 2) break;
    }

    if (mm.size() <= 2) {
      vector<pair<int, int> > a, b;
      for (auto t : mm) {
        if (a.size() == 0) a = t.y;
        else b = t.y;
      }
      if (a.size() > b.size()) swap(a, b);
      b.pb(pts[i]);
      special = a[0];
      line = b;
      break;
    }
  }

  db ans = 1e18;

  sort(all(line));
  swap(special, p);

  //per(line, special, p);

  if (special == p) {
    ans = min(ans, dist(p, line[0]) + dist(line[0], line.back()));
    ans = min(ans, dist(p, line.back()) + dist(line[0], line.back()));
  }

  else {
    int index = lower_bound(all(line), special) - line.begin();

    for (int i = 0; i < line.size(); ++i) {
      ans = min(ans, dist(special, line[i]) + dist(line[i], p) + dist(p, line[0]) + dist(line[0], line.back()));
      ans = min(ans, dist(special, line[i]) + dist(line[i], p) + dist(p, line.back()) + dist(line[0], line.back()));

      int vis = max(index, i);

      if (vis + 1 < line.size()) {
        ans = min(ans, dist(special, line[0]) + dist(line[0], line[i]) + dist(line[i], p) + dist(p, line[vis + 1]) + dist(line[vis + 1], line.back()));
        ans = min(ans, dist(special, line[0]) + dist(line[0], line[i]) + dist(line[i], p) + dist(p, line.back()) + dist(line[vis + 1], line.back()));
      }
      else {
        ans = min(ans, dist(special, line[0]) + dist(line[0], line[i]) + dist(line[i], p));
      }

      vis = min(index, i);

      if (vis - 1 >= 0) {
        ans = min(ans, dist(special, line.back()) + dist(line.back(), line[i]) + dist(line[i], p) + dist(p, line[vis - 1]) + dist(line[vis - 1], line[0]));
        ans = min(ans, dist(special, line.back()) + dist(line.back(), line[i]) + dist(line[i], p) + dist(p, line[0]) + dist(line[vis - 1], line[0]));
      }
      else {
        ans = min(ans, dist(special, line.back()) + dist(line.back(), line[i]) + dist(line[i], p));
      }
    }
  }

  cout.precision(9);
  cout << fixed << ans;

}