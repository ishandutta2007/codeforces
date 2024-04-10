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

void solve(vector<int>& a, vector<PII>& A, int shift){
	if (SZ(a) == 1){
		return;
	}

	const int sz = SZ(a);
	vector<int> b(sz >> 1), c(sz >> 1);
	FOR(i, 0, sz >> 1){
		b[i] = a[i];
		c[i] = a[i + (sz >> 1)];
	}

	solve(b, A, shift);
	solve(c, A, shift + sz / 2);
	FOR(i, 0, sz / 2){
		A.PB({i + shift, i + sz / 2 + shift});
	}
}

void go(int n, vector<vector<int>>& all, vector<PII>& ans){
	const int sz = SZ(all);
	if (sz <= 2){
		return;
	}

	if (SZ(all[sz - 2]) == SZ(all[sz - 1])){
		FOR(i, 0, SZ(all[sz - 1])){
			ans.PB({all[sz - 2][i], all[sz - 1][i]});
		}

		for(auto x: all[sz - 1]) all[sz - 2].PB(x);
		all.pop_back();
		go(n, all, ans);
	}else{
		auto& big = all[0];
		const int Size = SZ(all[sz - 1]);
		assert(SZ(big) >= Size);
		FOR(i, 0, Size){
			ans.PB({SZ(big), all[sz - 1][i]});
			int x = big.back();
			big.pop_back();
			all[sz - 1].PB(x);
		}

		go(n, all, ans);
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	if (n <= 2){
		cout << 0 << endl;
		return 0;
	}

	vector<PII> a;
	vector<vector<int>> all;

	vector<int> bity;
	FOR(i, 0, 15) if (n & (1 << i)){
		bity.PB(i);
	}

	reverse(ALL(bity));

	int start = 1;
	for(auto i: bity){
		vector<int> A(1 << i);
		iota(ALL(A), start);
		solve(A, a, start);
		start += 1 << i;
		all.PB(A);
	}


	go(n, all, a);

	assert(SZ(a) <= 500000);
	cout << SZ(a) << '\n';
	for(auto i: a){
		cout << i.X << ' ' << i.Y << '\n';
	}

	/*cout << endl;
	vector<LL> A(n + 1);
	iota(ALL(A), 0);
	for(auto i: a){
		LL x = i.X, y = i.Y;
		x = A[x], y = A[y];
		LL t = x * (LL) y + x + y;
		
		A[i.X] = A[i.Y] = t;
	}

	set<LL> S(A.begin() + 1, A.end());
	assert(SZ(S) <= 2);
	*/
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}