#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

const int nax = 2011;
const int inf = 1e9;

int n, h;
int a[nax];			
ld p;
	
pair<ld, ld> dp[nax][nax][2][2]; // - expected, propability	

int prawo[nax];
int lewo[nax];
int odl;

void add(pair<ld,ld> &a, pair<ld,ld> b, int odl, ld pro) {
	a.fi += b.fi * pro;
	a.fi += (ld) odl * pro * b.se;
	a.se += pro * b.se;
}
			
int main() {
	scanf("%d %d %lf", &n, &h, &p);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	a[0] = -inf;
	a[n + 1] = inf;
	dp[1][n][0][1] = mp(0.0, 1.0);
	
	prawo[n + 1] = n + 1;
	for(int i = n; 1 <= i; --i) {
		if(a[i] + h > a[i + 1])
			prawo[i] = prawo[i + 1];
		else
			prawo[i] = i;
	}
	lewo[0] = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] - h < a[i - 1])
			lewo[i] = lewo[i - 1];
		else
			lewo[i] = i;
	}
	ld Left = p / 2.0;
	ld Right = (1.0 - p) / 2.0;
	
	for(int len = n; 1 <= len; --len) 
		for(int le = 1; le + len - 1 <= n; ++le) {
			int ri = le + len - 1;
			for(int L = 0; L < 2; ++L)
				for(int R = 0; R < 2; ++R) {
					if((R == 0 && a[ri + 1] - h < a[ri]) || (L == 1 && a[le - 1] + h > a[le]))
						continue;
					// lewo
					if(L == 0)
						odl = min(h, a[le] - a[le - 1]);
					if(L == 1)
						odl = min(h, a[le] - (a[le - 1] + h));
					add(dp[le + 1][ri][0][R], dp[le][ri][L][R], odl, Left);
					
					int last = min(prawo[le], ri);
					odl = a[last] - a[le];
					if(last < ri)
						odl += h;
					else if(R == 1)
						odl += min(h, a[last + 1] - a[last]);
					else if(R == 0)
						odl += min(h, a[last + 1] - h - a[last]);
					add(dp[last + 1][ri][1][R], dp[le][ri][L][R], odl, Right);
					// prawo
					if(R == 1)
						odl = min(h, a[ri + 1] - a[ri]);
					if(R == 0)
						odl = min(h, a[ri + 1] - h - a[ri]);
					add(dp[le][ri - 1][L][1], dp[le][ri][L][R], odl, Right);
					
					
				
					last = max(lewo[ri], le);
					odl = a[ri] - a[last];
					if(le < last)
						odl += h;
					else if(L == 0)
						odl += min(h, a[last] - a[last - 1]);
					else if(L == 1)
						odl += min(h, a[last] - h - a[last - 1]);
					add(dp[le][last - 1][L][0], dp[le][ri][L][R], odl, Left);
				}
		}
					
	
	ld ans = 0.0;
	for(int i = 0; i <= n + 1; ++i)
		for(int j = 0; j < i; ++j)
			for(int L = 0; L < 2; ++L)
				for(int R = 0; R < 2; ++R)
					ans += dp[i][j][L][R].fi;
	
	printf("%.9lf", ans);
	return 0;
}
/*

1 10 0.5
5
*/