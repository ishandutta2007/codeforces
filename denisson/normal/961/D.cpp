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

template<class T>
struct Pt {
    T x, y;

    Pt(): x(0), y(0) {}
    Pt(T x, T y): x(x), y(y) {}
    
    T operator%(const Pt<T>& nxt) const { return x * nxt.y - y * nxt.x; }
    T operator*(const Pt<T>& nxt) const { return x * nxt.x + y * nxt.y; }

    Pt<T> operator+(const Pt<T>& nxt) const { return Pt<T>(x + nxt.x, y + nxt.y); }
    Pt<T> operator-(const Pt<T>& nxt) const { return Pt<T>(x - nxt.x, y - nxt.y); }
    Pt<T>& operator+=(const Pt<T>& nxt){ x += nxt.x; y += nxt.y; return *this; }
    Pt<T>& operator-=(const Pt<T>& nxt){ x -= nxt.x; y -= nxt.y; return *this; }

    T GetLen2() const { return x * x + y * y; }
    db GetLen() const { return sqrtl(GetLen2()); }
    db GetAngle() const { return atan2(y, x); }

    Pt<T> operator*(T val) const { return Pt<T>( x * val, y * val); }

    Pt<db> Rotate(db ang) const { return Pt<db>( x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang) ); }
    Pt<db> Norm(db val) const { return Pt<db>( x * val / GetLen(), y * val / GetLen() ); }
};

template<class T>
istream& operator>>(istream& inp, Pt<T>& p) { return inp >> p.x >> p.y; }
template<class T>
ostream& operator<<(ostream& out, const Pt<T>& p) { return out << "(" << p.x << ", " << p.y << ")"; }

#define pt Pt<ll>


int n;
pt a[100007];

bool can(int w1, int w2) {
  vector<pt> t;

  for (int i = 0; i < n; ++i) if (i != w1 && i != w2 && ((a[i] - a[w1]) % (a[w2] - a[w1]) != 0)) t.pb(a[i]);
  if (t.size() <= 2) return 1;
  for (int i = 2; i < t.size(); ++i) if ((t[i] - t[0]) % (t[1] - t[0]) != 0) return 0;
  return 1;
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


  cin >> n;
  readArr(a, a + n);

  if (n <= 4) {
    cout << "YES"; exit(0);
  }

  if (can(0, 1) || can(0, 2) || can(1, 2)) cout << "YES"; else cout << "NO";
}