#include <bits/stdc++.h>
#define gcd dklgfdg
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

const int N = 3000007;
int fact[N];
int rv[N];

int ans[N];

int C(int n, int k) {
  return mult(fact[n], mult(rv[k], rv[n - k]));
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, q;
  cin >> n >> q;

  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = mult(fact[i - 1], i);
  for (int i = 0; i < N; ++i) rv[i] = bp(fact[i], mod - 2);

  ans[0] = 0;
  for (int i = 0; i < 3*n; i += 3) add(ans[0], C(i, 0));
  int R = bp(3, mod - 2);

  for (int i = 1; i <= 3*n; ++i) {
    ans[i] = C(3*n, i + 1);
    if (i > 0) dec(ans[i], mult(3, ans[i - 1]));
    if (i > 1) dec(ans[i], ans[i - 2]);
    ans[i] = mult(ans[i], R);
  }

  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;

    int res = ans[x];
    add(res, C(3*n, x));
    cout << res << '\n';
  }


}