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

int n, m;
vector<int> a[100007];

vector<pair<int, int> > d[100007];

int cnt[41][41];
int sum[41];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int sz;
    cin >> sz;
    a[i].resize(sz);
    for (int j = 0; j < sz; ++j) cin >> a[i][j], d[a[i][j]].pb(mp(i, j));
  }

  for (int i = 1; i <= m; ++i) {

    fill(sum, sum + 41, 0);
    fill((int*)cnt, (int*)cnt + 41 * 41, 0);

    // cout << "===" << i << endl;
    // pper(d[i]);

    int res = 0;

    int w2 = 0;
    for (int w1 = 0; w1 < d[i].size(); ++w1) {
      while (w2 < w1) {
        int ok = 1;
        if (w1 && d[i][w1].x != d[i][w1 - 1].x + 1) ok = 0;

        for (int sz = 1; sz <= 40; ++sz) {
          int g = __gcd(sz, (int)a[d[i][w1].x].size());
          int ost = d[i][w1].y % g;
          int s = 0;
          for (int f = ost; f < sz; f += g) s += cnt[sz][f];
          if (s != sum[sz]) {
            ok = 0;
            break;
          }
        }

        if (!ok) {
          --cnt[a[d[i][w2].x].size()][d[i][w2].y];
          --sum[a[d[i][w2].x].size()];
          ++w2;
        } else break;
      }
      ++cnt[a[d[i][w1].x].size()][d[i][w1].y];
      ++sum[a[d[i][w1].x].size()];
      uax(res, w1 - w2 + 1);
    }

    cout << res << "\n";
  }
  

}