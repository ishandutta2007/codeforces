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

bool isSq(ll x) {
  ll now = sqrtl(x);
  while ((now + 1) * (now + 1) <= x) ++now;
  return now * now == x;
}


int main() {
  int n, m;
  cin >> n >> m;

  int t1 = -1, t2 = -1, p1 = -1, p2 = -1;



  for (ll w1 = 1; w1 <= 1000; ++w1) if (t1 == -1) {
    for (ll w2 = 1; w2 <= 1000; ++w2) if (t1 == -1) {
      if (isSq(w1 * w1 * (n - 1) + w2 * w2)) {
        t1 = w1;
        t2 = w2;
      }
    }
  }


  for (ll w1 = 1; w1 <= 1000; ++w1) if (p1 == -1) {
    for (ll w2 = 1; w2 <= 1000; ++w2) if (p1 == -1) {
      if (isSq(w1 * w1 * (m - 1) + w2 * w2)) {
        p1 = w1;
        p2 = w2;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int res = 1;
      if (i == 0) res *= t2; else res *= t1;
      if (j == 0) res *= p2; else res *= p1;
      cout << res << ' ';
    }
    cout << "\n";
  }
  

}