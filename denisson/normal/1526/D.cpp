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


char CC[] = {'A', 'N', 'T', 'O'};

// int gg[200007];
/*
ll dist(string a, string b){
  vector<int> p[4];
  vector<int> f[4];
  int i = 0;
  for (char c : a) {
    if (c == 'A') p[0].pb(i++);
    if (c == 'N') p[1].pb(i++);
    if (c == 'T') p[2].pb(i++);
    if (c == 'O') p[3].pb(i++);
  }

  i = 0;
  for (char c : b) {
    if (c == 'A') f[0].pb(i++);
    if (c == 'N') f[1].pb(i++);
    if (c == 'T') f[2].pb(i++);
    if (c == 'O') f[3].pb(i++);
  }

  ll res = 0;
  for (int i = 0; i < 4; ++i) for (int j = 0; j < p[i].size(); ++j)
    res += abs(p[i][j] - f[i][j]);
  return res;
}
*/
int cc[4];
int ff[4];

void solve() {
  string s;
  cin >> s;
  cc[0] = cc[1] = cc[2] = cc[3] = 0;
  for (char c : s) {
    if (c == 'A') ++cc[0];
    if (c == 'N') ++cc[1];
    if (c == 'T') ++cc[2];
    if (c == 'O') ++cc[3];
  }

  vector<int> t = {0, 1, 2, 3};

  string res;
  ll gg = -1e18;


  do {

    string d;
    for (int x : t) for (int i = 0; i < cc[x]; ++i) d += CC[x];

    ll dd = 0;
    copy(cc, cc + 4, ff);
    for (char c : s) {
      int ty;
      if (c == 'A') ty = 0;
      if (c == 'N') ty = 1;
      if (c == 'T') ty = 2;
      if (c == 'O') ty = 3;
      for (int i = 0; i < 4; ++i) if (t[i] == ty) {
        --ff[ty];
        break;
      } else dd += ff[t[i]];
    }

    if (dd > gg) {
      gg = dd;
      res = d;
    }

  } while (next_permutation(all(t)));

  cout << res << "\n";

  /*
  string res;

  for (char c : s) if (c == CC[0]) res += c;

  for (int i = 1; i < 4; ++i) {
    vector<int> t; int ba = 0;
    int ff = 0;
    for (char c : s) {
      if (c == CC[i]) {
        t.pb(ba);
        ++ff;
      } else {
        int need = 0;
        for (int j = 0; j < i; ++j) need |= c == CC[j];
        if (need) ++ba;
      }
    }

    for (int x : t) ++gg[x];


    int best_v = 0;
    ll best_dist = 1e18;

    ll ri = 0;
    ll le = 0;
    ll dist = 0;

    for (int i = res.size(); i >= 0; --i) {
      dist += ri;
      ri += gg[i];
    }

    best_dist = dist;


    cout << res << endl;
    pper(t);

    for (int i = 0; i < res.size(); ++i) {
      per(i, dist);

      ri -= gg[i];
      le += gg[i];
      dist += le;
      dist -= ri;

      if (dist > best_dist) {
        best_dist = dist;
        best_v = i + 1;
      }
    }

    pper(best_v);

    string cur_res;
    for (int j = 0; j < best_v; ++j) cur_res += res[j];
    while (ff--) cur_res += CC[i];
    for (int j = best_v; j < res.size(); ++j) cur_res += res[j];

    res = cur_res;

    for (int x : t) --gg[x];
  
  }

  cout << dist(res, s) << "\n";

  cout << res << "\n"; */
}


int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}