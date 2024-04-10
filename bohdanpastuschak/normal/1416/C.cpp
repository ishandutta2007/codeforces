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

LL solve(const vector<int>& b){
	const int n = SZ(b);
	LL ans = 0;
	vector<int> cnt(n + 1, 0);
	RFOR(i, n, 0) cnt[i] = cnt[i + 1] + (b[i] == 0);
	FOR(i, 0, n){
		if (b[i]){
			ans += cnt[i];
		}
	}
		
	return ans;
}

void solve(vector<vector<int>> a, LL& ans, int& x, int bit){
	if (bit < 0) return;
	const int sz = SZ(a);
	LL F = 0, S = 0;
	FOR(i, 0, sz){
		const auto& A = a[i];
		vector<int> b(SZ(A));
		FOR(j, 0, SZ(A)) b[j] = (A[j] & (1 << bit)) > 0;
		LL aa = solve(b);
		for(auto& j: b) j ^= 1;
		LL bb = solve(b);
		F += aa;
		S += bb;
	}

	if (F > S){
		x += 1 << bit;
		for(auto& i: a) for(auto& j: i) j ^= 1 << bit;
	}

	ans += min(F, S);
	//cout << bit << ' ' << F << ' ' << S << endl;
	vector<vector<int>> na;
	na.reserve(sz << 1);
	for(auto& i: a){
		vector<int> O, N;
		O.reserve(SZ(i));
		N.reserve(SZ(i));
		FOR(j, 0, SZ(i)) if (i[j] & (1 << bit)) O.PB(i[j]);
		else N.PB(i[j]);
		if (SZ(O)) na.PB(O);
		if (SZ(N)) na.PB(N);
	}
	
	solve(na, ans, x, bit - 1);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	FOR(i, 0, n) cin >> a[i];
	LL ans = 0;
	int x = 0;

	solve({a}, ans, x, 29);
	cout << ans << ' ' << x << endl;
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}