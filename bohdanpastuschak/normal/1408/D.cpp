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

const int M = 1 << 20;
int n, m;
PII a[M], b[M];
int cnt[M];
vector<PII> vec[M];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	FOR(i, 0, n) cin >> a[i].X >> a[i].Y;
	FOR(i, 0, m) cin >> b[i].X >> b[i].Y, b[i].X++, b[i].Y++;

	FOR(i, 0, n) FOR(j, 0, m){
		cnt[max(0, b[j].Y - a[i].Y)]++;
	}

	FOR(i, 0, n) FOR(j, 0, m){
		vec[max(0, b[j].X - a[i].X)].PB({i, j});
	}

	int y = 0;
	FOR(i, 0, M) if (cnt[i]) y = i;
	
	int ans = y;
	
	FOR(x, 0, M){
		for(auto [i, j] : vec[x]){
			cnt[max(0, b[j].Y - a[i].Y)]--;
		}

		while(y && cnt[y] == 0) y--;
		setmin(ans, x + y);
	}
	
	cout << ans << endl;	
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}