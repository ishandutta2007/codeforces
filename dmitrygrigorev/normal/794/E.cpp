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

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;
  vector <int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }

  vector <int> res(n, 0);
  for (int i = 0; i < n; ++i) {
    int x = d[i];
    res[n - 1] = max(res[n - 1], x);

    int a = i, b = n - i - 1;
    int cnt;
    if (b > a) {
      cnt = b - a - 1;
    } else if (a > b) {
      cnt = a - b - 1;
    } else {
      cnt = n % 2;
    }
    res[cnt] = max(res[cnt], x);
  
    if (!i || i == n - 1) continue;

    int val = min(d[i], max(d[i - 1], d[i + 1]));

    if (b > a) {
      cnt = b - a;
    } else {
      cnt = a - b;
    }
    res[cnt] = max(res[cnt], val);
  }

  for (int i = 0; i < n; ++i) {
    if (i >= 2) {
      res[i] = max(res[i], res[i - 2]);
    }
    cout << res[i] << " ";
  }

}