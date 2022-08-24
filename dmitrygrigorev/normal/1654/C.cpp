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

void solve() {

  int n;
  cin >> n;

  map<ll, int> v;
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    s += x;
    v[x]++;
  }

  map<ll, int> have;
  have[s]++;
  int steps = 0;

  while (steps < (n - 1)) {

    if (!have.size()) {
      cout << "NO\n";
      return;
    }

    auto it = have.end();
    it--;
    ll z = (*it).x;

    have[z]--;
    if (have[z] == 0) have.erase(have.find(z));

    if (v.count(z)) {
      v[z]--;
      if (v[z] == 0) v.erase(v.find(z));
    }

    else {
      if (z == 1) {
        cout << "NO\n";
        return;
      }
      ++steps;
      ll a = z/2;
      ll b = z - z/2;
      have[a]++;
      have[b]++;
    }
  }

  while (have.size()) {
    auto it = have.end();
    it--;
    ll z = (*it).x;

    have[z]--;
    if (have[z] == 0) have.erase(have.find(z));

    if (v.count(z)) {
      v[z]--;
      if (v[z] == 0) v.erase(v.find(z));
    }

    else {
      cout << "NO\n";
      return;
    }
  }



  cout << "YES\n";
  return; 

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) solve();

}