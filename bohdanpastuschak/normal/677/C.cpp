#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long double db;

#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

template<typename T> void print(const T& a, ostream& out){	
	for(auto i: a) out << i << ' ';
	out << endl;
}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int get(char x){
	if ('0' <= x && x <= '9') return x - '0';
	if ('A' <= x && x <= 'Z') return 10 + x - 'A';
	if ('a' <= x && x <= 'z') return 36 + x - 'a';
	if (x == '-') return 62;
	return 63;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s; cin >> s;
	int n = SZ(s);
	vector<int> a(n);
	FOR(i, 0, n){
		a[i] = get(s[i]);
	}

	vector<int> A(64, 0);
	FOR(i, 0, 64) FOR(j, 0, 64) A[i & j]++;
	int ans = 1;
	const int mod = 1e9 + 7;
	FOR(i, 0, n) ans = (ans * (LL) A[a[i]]) % mod;
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}