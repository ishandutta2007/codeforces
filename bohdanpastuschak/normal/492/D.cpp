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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 21;
int res[N];

inline int solve(int a, int x, int y){
	if (x > y){
		swap(x, y);
	}
	
	if (a % (x + y) == 0){
		return 2;
	}
	
	a %= (x + y);
	return res[a];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, x, y;
	cin >> n >> x >> y;
	
	if (x == y){
		while(n--){
			int a;
			cin >> a;
			cout << "Both\n";
		}
		
		return 0;
	}
	
	bool flag = (x < y);
	if (x > y) swap(x, y);
	vector<pair<PII, int>> all;
	FOR(i, 1, x + 1){
		int g = __gcd(i, x);
		all.PB({{i / g, x / g}, 0});
	}
	
	FOR(i, 1, y + 1){
		int g = __gcd(i, y);
		all.PB({{i / g, y / g}, 1});
	}
	
	sort(ALL(all), [&](pair<PII, int> u, pair<PII, int> v){
		if (u.X == v.X) return u.Y < v.Y;
		return u.X.X * (LL) v.X.Y < u.X.Y * (LL) v.X.X;
	});
	
	res[1] = 1;
	all.PB({{-1, -1}, -1});
	FOR(i, 1, SZ(all) - 1){
		if (all[i].X == all[i + 1].X){			
			res[i + 1] = res[i + 2] = 2;
			i++;
			continue;
		}
		
		res[i + 1] = all[i].Y;
	}
	
	while(n--){
		int a;
		cin >> a;
		int r = solve(a, x, y);
		if (r == 2){
			cout << "Both\n";
			continue;
		}
		
		if ((r == 0) == flag){
			cout << "Vanya\n";
		}	else{
			cout << "Vova\n";
		}	
	}			
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}