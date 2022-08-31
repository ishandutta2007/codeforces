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

ll ans = 0;

vector<ll> maximum, minimum;
const int N = 1000007;
const int M = 60;
int cnt[N][M];

void recalc(vector<ll> &v, int l, int r) {

  ll tut = 0;
  int mid = (l+r)/2;

  minimum[mid + 1] = v[mid + 1];
  minimum[mid] = v[mid];
  for (int i = mid + 2; i <= r; ++i) minimum[i] = min(minimum[i - 1], v[i]);
  for (int i = mid - 1; i >= l; --i) minimum[i] = min(minimum[i + 1], v[i]);

  maximum[mid + 1] = v[mid + 1];
  maximum[mid] = v[mid];
  for (int i = mid + 2; i <= r; ++i) maximum[i] = max(maximum[i - 1], v[i]);
  for (int i = mid - 1; i >= l; --i) maximum[i] = max(maximum[i + 1], v[i]);

  //////////////////////// P1
  int ask = mid;
  int len = 0;
  for (int i = mid + 1; i <= r; ++i) {
    while (ask >= l && minimum[ask] >= minimum[i] && maximum[ask] <= maximum[i]) ask--, len++;
    if (__builtin_popcountll(minimum[i]) == __builtin_popcountll(maximum[i])) tut += len;
  }
  //////////////////////// P2
  ask = mid + 1;
  len = 0;
  for (int i = mid; i >= l; --i) {
    while (ask <= r && minimum[ask] > minimum[i] && maximum[ask] < maximum[i]) ask++, len++;
    if (__builtin_popcountll(minimum[i]) == __builtin_popcountll(maximum[i])) tut += len;
  }

  //////////////////////// P3

  for (int e = 0; e < 60; ++e) cnt[mid][e] = 0;

  for (int i = mid + 1; i <= r; ++i) {
    for (int e = 0; e < 60; ++e) cnt[i][e] = cnt[i-1][e];

    int W = __builtin_popcountll(maximum[i]);

    cnt[i][W]++;
  }

  ask = mid + 1;
  int task = mid + 1;

  for (int i = mid; i >= l; --i) {
    int W = __builtin_popcountll(minimum[i]);

    while (ask <= r && minimum[ask] > minimum[i]) ask++;
    while (task <= r && maximum[task] < maximum[i]) task++;
    
    int A = task;
    int B = ask - 1;
    
   // per("===", i, W, A, B);

    if (A <= B) tut += cnt[B][W] - cnt[A - 1][W];
   // per(tut);
  }

  //per(l, r, tut);


  //////////////////////// P4

  for (int e = 0; e < 60; ++e) cnt[mid][e] = 0;

  for (int i = mid + 1; i <= r; ++i) {
    for (int e = 0; e < 60; ++e) cnt[i][e] = cnt[i-1][e];

    int W = __builtin_popcountll(minimum[i]);
    cnt[i][W]++;
  }


  ask = mid + 1;
  task = mid + 1;

  for (int i = mid; i >= l; --i) {
    int W = __builtin_popcountll(maximum[i]);

    while (ask <= r && maximum[ask] < maximum[i]) ask++;
    while (task <= r && minimum[task] > minimum[i]) task++;
    
    int A = task;
    int B = ask - 1;
   // per("===", i, W, A, B);
    if (A <= B) tut += cnt[B][W] - cnt[A - 1][W];
  }

  ans += tut;

}

void solve(vector<ll> &v, int l, int r) {
  if (r == l) {
    ans++;
    return;
  }

  int mid = (l+r)/2;
  solve(v, l, mid);
  solve(v, mid + 1, r);

  recalc(v, l, r);

}

int main(){
#ifdef LOCAL
  freopen("F_input.txt", "r", stdin);
  //freopen("F_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ll> v(n);
  for (auto &x : v) cin >> x;
  maximum.resize(n);
  minimum.resize(n);

  solve(v, 0, n - 1);

  cout << ans;

}