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

ll vl, vr;
int kek = 0;
int ans = 0;

int a[10];
int b[10];

ll step[19];

bool check(int v = 17, int le = 1, int ri = 1) {


  if (v == 17 && kek) {
    if (a[1] == 1 && a[0] == 17) return 1;
  }

  if (le == 0 && ri == 0) return 1;
  if (v == -1) return 1;

  int c1 = (vl / step[v]) % 10;
  int c2 = (vr / step[v]) % 10;

//  per(v, le, ri, c1, c2);

  for (int c = 0; c <= 9; ++c) if (a[c] > 0) {

    if (le == 1 && c < c1) continue;
    if (ri == 1 && c > c2) continue;

    a[c]--;
    if (check(v - 1, le && (c == c1), ri && (c == c2))) return 1; 
    a[c]++;
  }

  return 0;
}

void solve(int v = 0, int ost = 18) {

  if (v == 10) {

    if (ost != 0) return;

    copy(a, a + 10, b);
    ans += check();
    copy(b, b + 10, a);

  } else {

    for (int now = 0; now <= ost; ++now) {
      a[v] = now;
      solve(v + 1, ost - now);
    }

  }
}


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  step[0] = 1;
  for (int i = 1; i < 19; ++i) step[i] = step[i - 1] * 10;

  cin >> vl >> vr;

  if (vr == (ll)1e18) {

    if (vl == vr) cout << 1, exit(0);

    vr--; kek = 1;
  }
  
  solve();

  cout << ans;
}