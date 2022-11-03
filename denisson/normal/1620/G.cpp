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

int n;
int a[23][26];
int dp[1 << 23];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char c : s) a[i][c - 'a']++;
  }
  
  for (int mask = 0; mask < (1 << n); ++mask) {
    int kek = 1;
    for (int c = 0; c < 26; ++c) {
      int now = 1e9;
      for (int i = 0; i < n; ++i) if ((mask >> i) & 1) uin(now, a[i][c]);
      kek = mult(kek, now + 1);
    }
    if (mask == 0) kek = 1; 
    if (__builtin_popcount(mask) % 2 == 0) {
      kek = (mod - kek) % mod;
    }
    dp[mask] = kek;

 //   per(mask, kek);
  }
  
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) if (!((mask >> i) & 1)) {
      add(dp[mask ^ (1 << i)], dp[mask]);
    }
  }

  ll ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
//    per(mask, dp[mask]);
    int now = dp[mask];

  /*  if (__builtin_popcount(mask) % 2 == 1) {
      now = (mod - now) % mod;
    } */

    int su = 0;
    for (int i = 0; i < n; ++i) if ((mask >> i) & 1) su += i + 1;
    su *= __builtin_popcount(mask);

    add(now, 1);

    ans ^= (ll)su * now;
  }

  cout << ans;
}