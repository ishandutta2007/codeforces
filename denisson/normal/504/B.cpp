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



const size_t MAX_SIZE = 1 << 20;

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
    if (vl > vr) return 0;
    ll res = get(vr);
    if (vl > 0) {
      res -= get(vl - 1);
    }
    return res;
  }

  int getKth(int k) {
    int i = 0;
    for (int bit = 19; bit >= 0; bit--) {
      int x = i + (1 << bit) - 1;
      if (x >= MAX_SIZE) {
        continue;
      }
      if (t[x] <= k) {
        i += (1 << bit);
        k -= t[x];
      }
    }
    return i;
  }

  // Update t[v] += val;
  void up(int v, int val) {
    for (; v < MAX_SIZE; v = v | (v + 1)) {
      t[v] += val;
    }
  }
} f[3];

int uk = 0;

int n;
int a[222222];
int b[222222];

vector<int> get(int* a) {
  for (int i = 0; i < n; ++i) f[uk].up(i, 1);

  vector<int> res;

  for (int i = 0; i < n; ++i) {
    res.pb(f[uk].get(0, a[i] - 1));
    f[uk].up(a[i], -1);
  }

  ++uk;

  return res;
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);
  readArr(b, b + n);

  auto now1 = get(a);
  auto now2 = get(b);

 // per(now1);
 // per(now2);

  vector<int> now;
  int ost = 0;
  for (int i = n - 1, j = 1; i >= 0; --i, ++j) {
    ost += now1[i] + now2[i];
    now.pb(ost % j);
    ost /= j;
  }

  reverse(all(now));

  // pper(now);


  for (int i = 0; i < n; ++i) f[2].up(i, 1);

  vector<int> res;

  for (int i = 0; i < n; ++i) {
    res.pb(f[2].getKth(now[i]));
    f[2].up(res.back(), -1);
  }

  for (int x : res) cout << x << ' ';

}