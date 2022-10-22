#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int mod = 998244353;

int pt(int a, int b) {int c = 1; while(b) {if(b & 1) c = (ll) c * a % mod; a = (ll) a * a % mod; b /= 2;} return c;};

int n, m;
int a[1001][1001];
int R, C;
vector <pair<int,int>> v[1000005];

int sum = 0;
int sumc = 0;
int sumr = 0;
int kwac = 0;
int kwar = 0;
int dp = 0;

int t[1001][1001];

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
}

int main() {
	vector <int> val;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			val.pb(a[i][j]);
		}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			int pos = lower_bound(val.begin(), val.end(), a[i][j]) - val.begin();
			v[pos].pb({i, j});
		}
	
	scanf("%d %d", &R, &C);
	
	for(int i = 0; i < ss(val); ++i) {
		int Sum = 0;
		int Sumc = 0;
		int Sumr = 0;
		int Kwac = 0;
		int Kwar = 0;
		int Dp = 0;
		int dziel = pt(sum, mod - 2);
		for(auto x : v[i]) {
			int r = x.fi;
			int c = x.se;
			if(sum > 0) {
				t[r][c] = (ll) r * r % mod;
				
				add(t[r][c], (ll) c * c % mod);
				add(t[r][c], (ll) kwar * dziel % mod);
				add(t[r][c], (ll) kwac * dziel % mod);
				add(t[r][c], (ll) -2 * r * sumr % mod * dziel % mod);
				add(t[r][c], (ll) -2 * c * sumc % mod * dziel % mod);
				add(t[r][c], (ll) dp * dziel % mod);
			}
			
			add(Sum, 1);
			add(Sumc, c);
			add(Sumr, r);
			add(Kwac, (ll) c * c % mod);
			add(Kwar, (ll) r * r % mod);
			add(Dp, t[r][c]);
		}
		
		add(sum, Sum);
		add(sumr, Sumr);
		add(sumc, Sumc);
		add(kwar, Kwar);
		add(kwac, Kwac);
		add(dp, Dp);
	}
	printf("%d", t[R][C]);
		
		
				
				
		
	
	
	return 0;
}