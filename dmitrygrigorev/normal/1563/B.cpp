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

int mod = 1000000007;

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

const int N = 4000007;
int ans[N];
int suff_sum[N + 1];

int get(int l, int r) {
  int res = suff_sum[l];
  dec(res, suff_sum[r + 1]);
  return res;
}

void solve(int n) {

  ans[n] = 1;
  suff_sum[n] = 1;

  for (int i = n - 1; i >= 1; --i) {
    int t = 0;
    add(t, suff_sum[i + 1]);
    for (int m = 2; ; ++m) {
      int L = i * m, R = (i + 1) * m - 1;
      if (L > n) break;
      R = min(R, n);
      add(t, get(L, R));
    } 
    suff_sum[i] = suff_sum[i + 1];
    ans[i] = t;
    add(suff_sum[i], t);
  }

  cout << ans[1];


}


int main(){
#ifdef LOCAL
  freopen("B_input.txt", "r", stdin);
  //freopen("B_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n >> mod;

  solve(n);

}