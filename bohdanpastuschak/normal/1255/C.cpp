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

	int n; cin >> n;
	vector<vector<int>> a(n - 2);
	FOR(i, 0, n - 2) {
		a[i].resize(3);
		FOR(j, 0, 3) cin >> a[i][j], a[i][j]--;
		sort(ALL(a[i]));
	}

	vector<int> cnt(n, 0);
	FOR(i, 0, n - 2) FOR(j, 0, 3) cnt[a[i][j]]++;

	vector<int> X, Y;
	FOR(i, 0, n) if (cnt[i] == 1) X.PB(i);
	else if (cnt[i] == 2) Y.PB(i);

	vector<int> ans(n, -1);
	vector<int> ban(n, 0);

	map<PII, vector<int>> mp;
	FOR(i, 0, n - 2){
		FOR(j, 0, 3) FOR(k, 0, j){
			mp[MP(a[i][j], a[i][k])].PB(a[i][3 - j - k]);
			mp[MP(a[i][k], a[i][j])].PB(a[i][3 - j - k]);
		}
	}
	
	auto check = [&](int x, int y){
		FOR(it, 0, n - 2){
			if (!mp.count({x, y})) return 0;
			auto V = mp[{x, y}];
			bool ok = 0;
			for(auto lol: V) if (ban[lol] == 0){
				swap(x, y);
				y = lol;				
				ok = 1;
				ban[lol] = 1;
				ans[it + 2] = lol;
				break;
			}
			if (!ok) return 0;
		}
		
		return 1;
	};

	for(auto x1: X) for(auto y1: Y){
		ans.assign(n, -1);
		ban.assign(n, 0);
		ans[0] = x1;
		ans[1] = y1;
		ban[x1] = ban[y1] = 1;
		if (check(x1, y1)){			
			FOR(i, 0, n) cout << ans[i] + 1 << ' ';
				cout << endl;
			return 0;
		}
	}
	
	assert(0);
    
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}