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
	map<int, int> cnt;
	map<int, VI> a;
	FOR(i, 0, n){
		int x, y;
		cin >> x >> y;
		cnt[x]++;
		cnt[y]++;
		a[x].PB(y);
		a[y].PB(x);
	}

	int x = -1;
	for(auto i: cnt) if (i.Y == 1){
		x = i.X;
		break;
	}

	assert(x != -1);
	vector<int> ans;
	ans.PB(x);

	set<int> U;
	U.insert(x);
	FOR(it, 0, n){
		int y = -1;
		for(auto i: a[x]){
			if (!U.count(i)){
				y = i;
			}
		}

		x = y;
		U.insert(x);
		ans.PB(x);
	}
	
	for(auto i: ans) cout << i << ' ';
	cout << endl;	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}