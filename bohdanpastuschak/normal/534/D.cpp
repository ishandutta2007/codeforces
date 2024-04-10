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

void bad(){
	cout << "Impossible" << endl;
	exit(0);
}		

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	FOR(i, 0, n){
		cin >> a[i];
	}

	vector<int> ans;

	vector<vector<int>> A(n);
	FOR(i, 0, n){
		A[a[i]].PB(i + 1);
	}

	if (SZ(A[0]) == 0) bad();

	int lst = 0;
	ans.PB(A[0].back());
	A[0].pop_back();

	vector<set<int>> S(3);
	FOR(i, 0, n) if (SZ(A[i]) > 0) S[i % 3].insert(i);

	int M = 0;
	while(SZ(S[0]) || SZ(S[1]) || SZ(S[2])){
		int id = (lst + 1) % 3;
		if (SZ(S[id]) == 0) bad();
		
		auto it = S[id].upper_bound(M + 1);
		if (it == S[id].begin()) bad();
		--it;
		int mn = *it;
		
		auto& v = A[mn];
		int V = v.back();
		ans.PB(V);
		v.pop_back();
		if (SZ(v) == 0){
			S[id].erase(mn);
		}

		lst = id;
		M = mn;
	}
	
	cout << "Possible" << endl;
	FOR(i, 0, n) cout << ans[i] << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}