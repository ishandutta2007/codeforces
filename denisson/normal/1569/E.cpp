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

int n, a, h;
int step[11];
int GG[] = {1, 2, 3, 5, 9, 17};

unordered_map<int, vector<int>> p[2][33];

vector<int> st;

void gen(const vector<int>& a, int v, int uk, int ha = 0) {
  // per(a, v, uk, ha);
  if (a.size() == 1) {

    p[uk][a[0]][ha] = st;

  } else {
    int sz = a.size();
    for (int mask = 0; mask < (1 << (sz >> 1)); ++mask) {
      vector<int> d;

      int new_ha = ha;

      for (int i = 0; i < (sz >> 1); ++i) {
        if ((mask >> i) & 1) {

          d.pb(a[2 * i]);
          st[a[2 * i + 1]] = GG[v];
          add(new_ha, mult(step[v], a[2 * i + 1]));

        } else {

          d.pb(a[2 * i + 1]);
          st[a[2 * i]] = GG[v];
          add(new_ha, mult(step[v], a[2 * i]));

        }
      }

      gen(d, v - 1, uk, new_ha);

    }
  }
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> a >> h;
  for (int i = 0; i < 6; ++i) step[i] = bp(a, GG[i]);

  vector<int> w1, w2;

  for (int i = 0; i < (1 << n); ++i) if (i < (1 << (n - 1))) {
    w1.pb(i + 1);
  } else w2.pb(i + 1);

  st.resize((1 << n) + 1);
  gen(w1, n, 0);
  gen(w2, n, 1);

  for (int v1 : w1) for (int v2 : w2) {

    int need = h;
    dec(need, mult(v1, step[0]));
    dec(need, mult(v2, step[1]));

    for (const auto& [w, kek1] : p[0][v1]) {
      int now = need;
      dec(now, w);
      if (p[1][v2].find(now) != p[1][v2].end()) {

        vector<int> res = kek1;
        for (int i = (1 << (n - 1)) + 1; i <= (1 << n); ++i) {
          res[i] = p[1][v2][now][i];
        }
        res[v1] = 1;
        res[v2] = 2;
        
        for (int i = 1; i <= (1 << n); ++i) cout << res[i] << ' ';

        exit(0);

      } 
    }


    need = h;
    dec(need, mult(v1, step[1]));
    dec(need, mult(v2, step[0]));
    
    for (const auto& [w, kek1] : p[0][v1]) {
      int now = need;
      dec(now, w);
      if (p[1][v2].find(now) != p[1][v2].end()) {


        vector<int> res = kek1;
        for (int i = (1 << (n - 1)) + 1; i <= (1 << n); ++i) {
          res[i] = p[1][v2][now][i];
        }
        res[v1] = 2;
        res[v2] = 1;

        for (int i = 1; i <= (1 << n); ++i) cout << res[i] << ' ';

        exit(0);

      } 
    }

  }

  cout << -1;

}