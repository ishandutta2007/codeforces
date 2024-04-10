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

vector<pair<int, int> > ans;

void app(vector<int> &v, int x, int y) {
  if (v[x] > v[y]) swap(x, y);
  ans.pb(mp(x + 1, y + 1));
  v[y] -= v[x];
  v[x] *= 2;
 // per(v);
}

void dlt(vector<int> &v, int x, int y, int z) {

  while (v[x] && v[y] && v[z]) {
    if (v[x] > v[y]) swap(x, y);
    if (v[y] > v[z]) swap(y, z);
    if (v[x] > v[y]) swap(x, y);

    if (v[x] == v[y]) app(v, x, y);
    else if (v[y] == v[z]) app(v, y, z);
    else {
      int R = v[y] / v[x];
      int deg = -1;
      for (int i = 0; i < 25; ++i) if ((1<<i)&R) deg = i;
      for (int i = 0; i <= deg; ++i) {
        if ((1<<i)&R) {
          app(v, x, y);
        }
        else app(v, x, z);
      }
    }


  }

}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> v(n);
  for (auto &x : v) cin >> x;

  int t = 0;
  for (auto x : v) if (x > 0) t++;
  if (t <= 1) {
    cout << -1;
    exit(0);
  }

  while (true) {
    vector<int> free;
    for (int i = 0; i < v.size(); ++i) if (v[i]) free.pb(i);
    if (free.size() == 2) break;
    dlt(v, free[0], free[1], free[2]);
  }

  cout << ans.size() << '\n';
  for (auto x : ans) cout << x.x << " " << x.y << endl;

}