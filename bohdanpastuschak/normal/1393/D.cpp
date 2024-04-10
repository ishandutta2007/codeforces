#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

const int N = 1 << 11;
int n, m;
string s[N];
bool a[N][N];
int A[N][N], B[N][N], C[N][N], D[N][N];

void print(int X[N][N]){
	FOR(i, 1, n + 1){
		FOR(j, 1, m + 1) cout << X[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}
 
LL solve(){
	FOR(i, 1, n + 1) FOR(j, 1, m + 1){
		if (a[i][j] == 0) A[i][j] = 0;
		else{
			A[i][j] = min(A[i - 1][j], A[i][j - 1]);
			A[i][j]++;
		}
	}

	FOR(i, 1, n + 1) RFOR(j, m + 1, 1){
		if (a[i][j] == 0) B[i][j] = 0;
		else{
			B[i][j] = min(B[i - 1][j], B[i][j + 1]);
			B[i][j]++;
		}
	}

	RFOR(i, n + 1, 1) FOR(j, 1, m + 1){
		if (a[i][j] == 0) C[i][j] = 0;
		else{
			C[i][j] = min(C[i + 1][j], C[i][j - 1]);
			C[i][j]++;
		}
	}

	RFOR(i, n + 1, 1) RFOR(j, m + 1, 1){
		if (a[i][j] == 0) D[i][j] = 0;
		else{
			D[i][j] = min(D[i + 1][j], D[i][j + 1]);
			D[i][j]++;
		}
	}

	
	LL ans = 0;
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) if (a[i][j]) ans += min({A[i][j], B[i][j], C[i][j], D[i][j]});
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	FOR(i, 0, n) cin >> s[i];
	LL ans = 0;
	for(char x = 'a'; x <= 'z'; ++x){
		FOR(i, 1, n + 1) FOR(j, 1, m + 1) a[i][j] = s[i - 1][j - 1] == x;
		ans += solve();
	}
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}