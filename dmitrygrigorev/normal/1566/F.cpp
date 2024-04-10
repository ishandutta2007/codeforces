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

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.y != b.y) return (a.y < b.y);
  return (a.x > b.x);
}

vector<pair<int, int> > remove_excess(vector<pair<int, int> > v) {

  vector<pair<int, int> > ans;
  sort(all(v), cmp);

  int cur = -1.1e9;
  for (auto x : v) {
    if (x.x <= cur) continue;
    ans.pb(x);
    cur = x.x;
  }

  return ans;

}

int bs(vector<int> &v, int x) {
  int L = 0, R = v.size() + 1;
  while (R-L>1) {
    int M = (L+R)/2;
    if (v[M - 1] < x) L = M;
    else R = M;
  } 
  return L;
}

vector<pair<int, int> > remove_covered(vector<pair<int, int> > v, vector<int> pts) {

  sort(all(pts));
  vector<pair<int, int> > ans;

  for (auto x : v) {
    if (bs(pts, x.x) == bs(pts, x.y + 1)) ans.pb(x);
  }

  return ans;

}

int bs2(vector<pair<int, int> > &v, int x) {
  int L = 0, R = v.size() + 1;
  while (R-L>1) {
    int M = (L+R)/2;
    if (v[M - 1].x < x) L = M;
    else R = M;
  } 
  return L;
}

pair<int, int> get_borders(vector<pair<int, int> > &segs, int L, int R) {
  int a = bs2(segs, L);
  int b = bs2(segs, R + 1);
  return mp(a, b);
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> pts(n);
  vector<pair<int, int> > segs(m);

  for (auto &x : pts) cin >> x;
  for (auto &x : segs) cin >> x.x >> x.y;

  segs = remove_excess(segs);
  segs = remove_covered(segs, pts);


  vector<ll> ans(segs.size() + 1, 1e18);
  ans[0] = 0;

  sort(all(pts));

  //per(segs);
  //per(pts);

  for (int i = 0; i < pts.size(); ++i) {
    int L = -2e9, R = 2e9;
    if (i - 1 >= 0) L = pts[i - 1] + 1;
    if (i + 1 < pts.size()) R = pts[i + 1] - 1;

    pair<int, int> os = get_borders(segs, L, R);
    if (os.x > os.y) continue;
    int we = bs2(segs, pts[i]);

    ll opt = 1e18;

    for (int tml = 0; tml <= 2; ++tml) {
      for (int tmr = 0; tmr <= 2; ++tmr) {
        if (tml == 1 && tmr == 1) continue;
        ll best = 1e18;

        for (int a = we; a >= os.x; --a) {
          if (a != we && tml == 0) break;
          ll spend = 0;
          if (a != we) spend = (ll) (pts[i] - segs[a].y) * tml;
          best = min(best, ans[a] + spend);
        }

        for (int a = we; a <= os.y; ++a) {
          if (a != we && tmr == 0) break;
          ll spend = 0;
          if (a != we) spend = (ll) (segs[a - 1].x - pts[i]) * tmr;
          if (a == we) opt = min(opt, best + spend);
          else ans[a] = min(ans[a], best + spend);
        }

        //per(ans, tml, tmr, best);

      }
    }
    //per(ans);
    ans[we] = min(ans[we], opt);
  }

  cout << ans.back() << '\n';


}

int main(){
#ifdef LOCAL
  freopen("F_input.txt", "r", stdin);
  //freopen("F_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}