#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
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

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(58);

inline bool solve(vector<int>& A, vector<int>& B, int n){
	if (n == 0) return true;
	vector<pair<int, int>> in_A, in_B;
	in_A.reserve(n / 2);
	in_B.reserve(n / 2);
	
	FOR(i, 0, n){
		int u, v;
		
		u = A[i];
		v = A[SZ(A) - 1 - i];
		
		if (u > v) swap(u, v);
		in_A.PB({u, v});
		
		u = B[i];
		v = B[SZ(B) - 1 - i];
		
		if (u > v) swap(u, v);
		in_B.PB({u, v});
	}
	
	sort(ALL(in_A));
	sort(ALL(in_B));
	return in_A == in_B;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		FOR(i, 0, n) cin >> a[i];
		FOR(i, 0, n) cin >> b[i];
		bool ok = true;
		int hto = -1;
		if (n & 1){
			ok &= a[n >> 1] == b[n >> 1];
			hto = n >> 1;
		}
		
		vector<int> A, B;
		A.reserve(n);
		B.reserve(n);
		FOR(i, 0, n) if  (i != hto) A.PB(a[i]), B.PB(b[i]);
		ok &= solve(A, B, SZ(A) / 2);
		cout << (ok ? "Yes\n" : "No\n");
	}
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}