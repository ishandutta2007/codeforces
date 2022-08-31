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

const int M = 70;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}

bool isp(ll x, int n) {
	ll z = x;
	for (ll t = 2; t*t <= x && t < n; ++t) if (x%t==0) return false;
	return true;
}

void solve() {

	int n;
	cin >> n;

	int index = -1;
	ll val = -1;

	bool tw = true;
	for (int a = 0; a < M; ++a) {
		int x = rand()%n, y  =rand()%n;
		while (x == y) {
			x = rand()%n, y  =rand()%n;
		}
		cout << "? " << x+1 << " " << y+1 << endl;
		ll z;
		cin >> z;
		if (z%2!=0) tw = false;
	}

	for (int a = 0; a < 3*M; ++a) {
		ll t = 0;
		int cur = rand()%n;
		for (int b = 0; b < M/3; ++b) {
			int z = rand()%n;
			while (z==cur) z = rand()%n;
			cout << "? " << z+1 << " " << cur+1 << endl;
			ll val;
			cin >> val;

			if (n == 3 && tw) val /= 2;

			t = gcd(t, val);

		}

		if (isp(t, n)) {
			if (t > val) {
				val = t;
				index = cur;
			}
 		}

	}


	vector<int> ans(n);
	ans[index] = val;

	for (int i = 0; i < n; ++i) {
		if (i == index) continue;
		cout << "? " << i+1 << " " << index+1 << endl;
		ll z;
		cin >> z;

		ans[i] = z / val;
	}

	cout << "! ";
	for (auto x : ans) cout << x << " ";
	cout << endl;

}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}