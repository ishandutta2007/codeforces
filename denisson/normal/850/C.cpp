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
int a[111];
map<int, set<int> > was;

// int need[100007];

map<int, int> dp;

int gr(int mask) {

 // pper(mask);

  if (dp.find(mask) != dp.end()) return dp[mask];

  if (mask <= 1) return 0;

  vector<int> t;

  for (int i = 1 ; ; ++i) {
    if ((1 << i) > mask) break;

    int now = ( mask & ((1 << i) - 1) ) | (mask >> i);
    t.pb(gr(now));
  }

  sort(all(t));
  t.resize(unique(all(t)) - t.begin());
  for (int i = 0; i < t.size(); ++i) if (t[i] != i) return dp[mask] = i;

  return dp[mask] = t.size();
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


  cin >> n;
  readArr(a, a + n);

/*
  vector<int> p;

  for (int i = 2; i < 100007; ++i) if (!need[i]) {
    p.pb(i);
    for (int j = i * 2; j < 100007; j += i) {
      need[j] = 1;
    }
  }
*/


  for (int i = 0; i < n; ++i) {

//    a[i] = 1 << i;

    int x = 2;

    while (x * x <= a[i]) {
      int uk = 0;
      while (a[i] % x == 0) {
        a[i] /= x;
        ++uk;
      }

      if (uk > 0) {
        was[x].insert(uk);
      }

      ++x;
    }

    if (a[i] > 1) was[a[i]].insert(1);
  }

  int res = 0;


//  pper(was);

  for (auto& [_, m] : was) {
    int mask = 0;
    for (int x : m) mask |= 1 << x;

  //  per(mask);

    res ^= gr(mask);
  }

  // pper(dp);


  if (res == 0) cout << "Arpa\n"; else cout << "Mojtaba\n";

}