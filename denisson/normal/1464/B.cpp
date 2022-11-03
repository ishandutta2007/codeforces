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

ll a[2][100007];
ll b[2][100007];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  string s;
  ll x, y;

  cin >> s >> x >> y;
  ll n = s.size();

  ll w0 = 0, w1 = 0;
  ll t0 = 0, t1 = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '?') {

      a[0][i] = w1 * y;
      a[1][i] = t0 * x;

      w0++;
      t1++;

    } else {
      if (s[i] == '0') {
        a[0][i] = w1 * y;
        a[1][i] = t1 * y;

        w0++;
        t0++;
      } else {
        a[0][i] = w0 * x;
        a[1][i] = t0 * x;

        w1++;
        t1++;
      }
    }

    if (i) {
      a[0][i] += a[0][i - 1];
      a[1][i] += a[1][i - 1];
    }
  }

  w0 = t0 = w1 = t1 = 0;

  for (int i = (int)s.size() - 1; i >= 0; --i) {
    if (s[i] == '?') {

      b[0][i] = w1 * x;
      b[1][i] = t0 * y;

      w0++;
      t1++;

    } else {
      if (s[i] == '0') {
        b[0][i] = w1 * x;
        b[1][i] = t1 * x;

        w0++;
        t0++;
      } else {
        b[0][i] = w0 * y;
        b[1][i] = t0 * y;

        w1++;
        t1++;
      }
    }

    if (i) {
      b[0][i] += b[0][i + 1];
      b[1][i] += b[1][i + 1];
    }
  }

  ll res = min(a[0][n - 1], a[1][n - 1]);

  ll c0 = 0, c1 = 0, cc = 0;
  for (char c : s) if (c == '0') ++c0; else if (c == '1') ++c1; else ++cc;

  ll le0 = 0, le1 = 0, lec = 0;
  
 // per(c0, c1, cc);

  for (int i = 0; i + 1 < s.size(); ++i) {

    if (s[i] == '0') ++le0; else if (s[i] == '1') ++le1; else ++lec;

    ll now1 = a[0][i] + b[1][i + 1] + x * (le0 + lec) * (c1 - le1 + cc - lec) + y * (le1) * (c0 - le0);
    ll now2 = a[1][i] + b[0][i + 1] + x * (le0) * (c1 - le1) + y * (le1 + lec) * (c0 - le0 + cc - lec);

//    pper(now1);
//    pper(now2);

  //  per(now1, a[0][i], b[1][i + 1]);

    uin(res, now1);
    uin(res, now2);
  } 



  cout << res;
}