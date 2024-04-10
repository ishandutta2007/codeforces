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

const int N = 1 << 18;
int n, m, k;
vector<int> g[N];
vector<PII> gr[N];
vector<PII> D[N];
const int M = 45;
bool cant[M][M];

inline int get(int deg, int id){
	return deg * (deg - 1) / 2 + id;
}

vector<vector<int>> gen;
vector<int> curr;

void rec(int id){
	if (id > k){
		gen.PB(curr);
		return;
	}
	
	FOR(i, 0, id){
		curr.PB(get(id, i));
		rec(id + 1);
		curr.pop_back();
	}
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	vector<pair<int, PII>> e(m);
	FOR(i, 0, m){
		cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X;
	}

	sort(ALL(e));
	for(auto E: e){
		int u = E.Y.X, v = E.Y.Y;
		--u; --v;
		gr[v].PB({u, SZ(g[u])});
		g[u].PB(v);
	}

	FOR(i, 0, n){
		for(auto j: gr[i]){
			D[i].PB({SZ(g[j.X]), j.Y});
		}
		
		const int sz = SZ(D[i]);
		vector<int> ja(sz);
		FOR(j, 0, sz) ja[j] = get(D[i][j].X, D[i][j].Y);
		sort(ALL(ja));
		FOR(j, 1, sz) if (ja[j] == ja[j - 1]){
			cant[ja[j]][ja[j]] = 1;
		}

		ja.resize(unique(ALL(ja)) - ja.begin());
		FOR(j1, 0, SZ(ja)) FOR(j2, 0, j1){
			int J1 = ja[j1];
			int J2 = ja[j2];
			cant[J1][J2] = cant[J2][J1] = 1;
		}	
	}

	rec(1);
	int ans = 0;
	for(auto v: gen){
		bool ok = 1;
		for(auto i: v) for(auto j: v) ok &= !cant[i][j];
		ans += ok;
	}
	
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}