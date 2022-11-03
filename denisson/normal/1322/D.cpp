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
int a[2222];
int s[2222];
int c[4444];

int dp[5005][2002];
int best[5005];

int f(int mask, int base) {
  int res = 0;
  for (int i = 0; i < 20; ++i) {
    if ((mask >> i) & 1) {
      res += c[base + i];
    } else {
      res += c[base + i]; break;
    }
  }
  return res;
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  readArr(a, a + n);
  readArr(s, s + n);
  readArr(c + 1, c + 1 + n + m);

  reverse(a, a + n);
  reverse(s, s + n);

  int res = 0;

  const int INF = 1e9 + 7;
  for (int i = 0; i < 5005; ++i) {
    best[i] = 0;
    fill(dp[i], dp[i] + 2002, -INF);
    dp[i][0] = 0;
  }

  for (int i = 0; i < n; ++i) {

    int now = a[i];
    for (int prev = now; prev >= 1; --prev) {
      if (now - prev > 12) {
        uax(dp[now][1], best[prev] - s[i] + c[a[i]]);
        uax(best[now], dp[now][1]);
      } else {

        for (int cnt = i; cnt >= 0; --cnt) if (dp[prev][cnt] != -INF) {
          int mask = cnt >> (now - prev);
          uax(dp[now][mask + 1], dp[prev][cnt] - s[i] + f(mask, now));
          uax(best[now], dp[now][mask + 1]);
        }

      } 
    }



  }


  cout << max(res, *max_element((int*)dp, (int*)dp + 2002 * 5005));

}