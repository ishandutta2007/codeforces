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

const int LOG = 30;
const int N = 1 << 22;

struct node{
	int nxt[2];
	node(){
		FILL(nxt, -1);
	}
};

node a[N];
int sz = 1;

void add(int x){
	int v = 0;
	RFOR(i, LOG, 0){
		bool tut = (x & (1 << i)) > 0;
		if (a[v].nxt[tut] != -1){
			v = a[v].nxt[tut];
		}else{
			a[v].nxt[tut] = sz++;
			v = a[v].nxt[tut];
		}
	}
}

int dp[N];
int solve(int v, int lg = LOG){
	if (dp[v] != -1) return dp[v];	
	int& ans = dp[v];
	ans = 0;
	RFOR(i, lg, 0){
		if (a[v].nxt[0] != -1 && a[v].nxt[1] != -1){
		
			ans += min(solve(a[v].nxt[0], i), solve(a[v].nxt[1], i));			
			ans += 1 << i;
			break;
		}else{
			if (a[v].nxt[0] != -1) v = a[v].nxt[0];
			else if (a[v].nxt[1] != -1) v = a[v].nxt[1];
			else break;
		}
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	FOR(i, 0, n){
		int x; cin >> x;
		add(x);
	}

	FILL(dp, -1);
	cout << solve(0) << endl;
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}