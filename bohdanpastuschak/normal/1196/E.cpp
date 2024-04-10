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

	int q; cin >> q;
	while(q--){
		int b, w;
		cin >> b >> w;
		bool was = 0;
		if (w > b) was = 1, swap(w, b);
		if (b > 3 * w + 1){
			cout << "NO\n";
			continue;
		}

		cout << "YES" << endl;
		vector<PII> ans;

		int x = 100;
		int y = 100;
		
		for(int i = y, it = 0; it < w; it++, i += 2){
			ans.PB({x, i});
		}

		int lst = ans.back().Y;

		for(int i = y - 1; i < lst; i += 2){
			ans.PB({x, i});
			b--;
		}

		if (b) ans.PB({x, lst + 1}), b--;

		FOR(i, 0, w){
			if (!b) break;
			ans.PB({x - 1, ans[i].Y});
			b--;
		}

		FOR(i, 0, w){
			if (!b) break;
			ans.PB({x + 1, ans[i].Y});
			b--;
		}
		
		if (was){
			for(auto& i: ans) i.X++;
		}
		
		for(auto i: ans) cout << i.X << ' ' << i.Y << '\n';		
	}
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}