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

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, A;
	cin >> n >> A;
	vector<int> c(n);
	FOR(i, 0, n) cin >> c[i];
	map<int, int> C;
	FOR(i, 0, n) C[c[i]]++;

	vector<int> cand;
	for(auto i: C) if (i.X != A && i.Y >= C[A]){
		cand.PB(i.X);
	}

	if (SZ(cand) == 0){
		cout << -1 << endl;
		return 0;
	}

	shuffle(ALL(cand), rng);
	vector<vector<int>> b(1 << 20);
	FOR(i, 0, n) b[c[i]].PB(i);
	
	for(auto i: cand){

		bool ok = 1;
		FOR(j, 0, C[A]){
			if (b[i][j] > b[A][j]){
				ok = 0;
				break;
			}
		}
		if (ok){
			cout << i << endl;
			return 0;
		}
		
	}
	
	cout << -1 << endl;
	
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}