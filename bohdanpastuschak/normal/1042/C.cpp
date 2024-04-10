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

void print(vector<VI>& ans){
	for(auto i: ans){
		for(auto j: i) cout << j + 1 << ' ';
		cout << '\n';
	}
	exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	FOR(i, 0, n) cin >> a[i];
	vector<int> vid, nul, dod;
	FOR(i, 0, n){
		if (a[i] < 0) vid.PB(i);
		if (a[i] > 0) dod.PB(i);
		if (a[i] == 0) nul.PB(i);
	}

	sort(ALL(vid), [&](int x, int y){
		return a[x] < a[y];
	});

	vector<VI> ans;
	VI ban(n, 0);
	if (SZ(nul) == n || (SZ(nul) == n - 1 && SZ(vid) == 1)){
		FOR(i, 1, n) ans.PB({0, i, 0});
		print(ans);
	}	
	
	if (SZ(nul) > 0){
		FOR(i, 1, SZ(nul)) ans.PB({0, nul[i], nul[0]});
		if (SZ(vid) & 1){
			ans.PB({0, vid.back(), nul[0]});
			ban[vid.back()] = 1;
			vid.pop_back();
		}

		ans.PB({1, nul[0]});
		int id = -1;
		if (SZ(vid) > 0) id = vid.back();
		else id = dod.back();

		FOR(i, 0, n) if (a[i] != 0 && !ban[i] && i != id){
			ans.PB({0, i, id});
		}
		print(ans);
	}else{
		if (SZ(vid) & 1){
			ans.PB({1, vid.back()});
			ban[vid.back()] = 1;
			vid.pop_back();			
		}

		int id = -1;
		FOR(i, 0, n) if (!ban[i]) id = i;
		FOR(i, 0, n) if (!ban[i] && i != id){
			ans.PB({0, i, id});
		}
	}	
		
	print(ans);
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}