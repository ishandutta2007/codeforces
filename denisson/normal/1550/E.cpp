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

int n, k;
string s;

int dp[1 << 17];

int nxt[200007][17];

int cnt[17];

bool can(int val) {


  fill(cnt, cnt + 17, 0);

  for (int i = 0; i <= s.size(); ++i) for (int j = 0; j < k; ++j)
    nxt[i][j] = 1e9;

  for (int i = (int)s.size() - 1; i >= 0; --i) {
    if (s[i] != '?') cnt[s[i] - 'a']++;
    if (i + val < s.size() && s[i + val] != '?')
      cnt[s[i + val] - 'a']--;

    int v = -1;
    for (int j = 0; j < k; ++j) if (cnt[j] != 0) {
      if (v == -1) v = j;
      else v = -2;
    }

    for (int j = 0; j < 17; ++j) {
      nxt[i][j] = nxt[i + 1][j];
      if (v == -1) nxt[i][j] = i;
      else if (v != -2) nxt[i][v] = i;
    }

    //for (int j = 0; j < k; ++j) {
    //  cout << i << ' ' << j << ' ' << nxt[i][j] << endl;
    //}

  }


  fill(dp, dp + (1 << 17), 1e9);
  dp[0] = 0;

  for (int mask = 0; mask < (1 << k); ++mask) if (dp[mask] < s.size()) {
    for (int v = 0; v < k; ++v) if (!((mask >> v) & 1)) {
      int pos = nxt[dp[mask]][v];
      if (pos >= s.size()) continue;
      uin(dp[mask ^ (1 << v)], pos + val);
    }
  }

  //pper(dp[(1 << 2) + 1 + 2])

  if (dp[(1 << k) - 1] <= s.size()) return 1;
  return 0;

}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> s >> k >> s;

  int vl = 0, vr = (int)s.size() / k + 1;

  while (vl + 1 < vr) {
    int vm = (vl + vr) >> 1;
    if (can(vm)) vl = vm; else vr=  vm;
  }


  cout << vl;

}