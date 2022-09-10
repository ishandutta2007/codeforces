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

LL solve(){
	int n, m;
	cin >> n >> m;
	vector<PII> a(n + n);
	FOR(i, 0, n){
		cin >> a[i].X;
		a[i].Y = 1;
	}
	FOR(i, n, n + n){
		cin >> a[i].X;
		a[i].Y = 0;
	}
	
	sort(ALL(a));
	reverse(ALL(a));
	LL ans = 0;
	int vje = 0;
	for(auto i: a){
		if (vje == n){
			break;
		}
		
		if (i.Y == 1){
			vje++;
			ans += i.X;
		}else{
			if (m > 0){
				m--;
				vje++;
				ans += i.X;
				
			}
		}
	}
	
	return ans;	
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t = 1;
	cin >> t;
	while(t--){
		cout << solve() << '\n';
	}
	
    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}