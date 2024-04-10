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

int n;
ll xx, yy;
ll a[500007];


const size_t MAX_SIZE = 1 << 21;

/*
 * Fenwick tree on range [0..MAX_SIZE-1]
 *
 *   Range sum    [vl..vr]    - get(vl, vr)
 *   Point update t[v] += val - up(v, val)
 */

struct FenwickTree1 {
  ll t[MAX_SIZE];

  // Sum [0..v]
  ll get(int v) {
    ll res = 0;
    for (; v >= 0; v = (v & (v + 1)) - 1) {
      res += t[v];
    }
    return res;
  }

  // Sum [vl..vr]
  ll get(int vl, int vr) {
    ll res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return res;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      t[v] += val;
    }
  }
} fcnt, fsum;

int need[1000007];


int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> xx >> yy;
  readArr(a, a + n);

  for (int x = 2; x <= 1000000; ++x) if (!need[x]) {
    for (int y = 2 * x; y <= 1000000; y += x) need[y] = 1;
  }

  for (int i = 0; i < n; ++i) {
    fcnt.up(a[i], 1);
    fsum.up(a[i], a[i]);
  }

  ll res = 1e18;

  ll len = xx / yy;
  
  for (int x = 2; x <= 1000000; ++x) if (!need[x]) {
    ll now = 0;
    for (int i = 0; ; ++i) {
      int vl = i * x + 1, vr = (i + 1) * x - 1;
      if (vl > 1000000) break;


     // per(vl, vr, len, xx, yy);

      if (vr - vl + 1 <= len) {
        now += ((vr + 1) * (ll)fcnt.get(vl, vr) - fsum.get(vl, vr)) * yy;
      } else {

/*
        if (((vr + 1) * (ll)fcnt.get(vr - len + 1, vr) - fsum.get(vr - len + 1, vr)) * yy + fcnt.get(vl, vr - len) * xx != 0) {
        
      per(vl, vr, len, xx, yy);

          pper(fcnt.get(vr - len + 1, vr))
          pper(fsum.get(vr - len + 1, vr))
          pper(fcnt.get(vl, vr - len))
          pper(vl)
          pper(vr - len)

          pper(((vr + 1) * (ll)fcnt.get(vr - len + 1, vr) - fsum.get(vr - len + 1, vr)) * yy + fcnt.get(vl, vr - len) * xx)
        } */

        now += ((vr + 1) * (ll)fcnt.get(vr - len + 1, vr) - fsum.get(vr - len + 1, vr)) * yy + fcnt.get(vl, vr - len) * xx;
      }
    }

    uin(res, now);
  }

  cout << res;
}