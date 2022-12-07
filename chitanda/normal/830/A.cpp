#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const ll oo = 1LL << 60;
int n, k, p;
ll f[2010][2010], g[2010][2010];
int a[2010], b[2010];

int main(){
	scanf("%d%d%d", &n, &k, &p);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= k; ++i) scanf("%d", b + i);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + k + 1);
	memset(f, 127, sizeof(f));
	memset(g, 127, sizeof(g));
	f[0][0] = 0;
	for(int i = 0; i <= n; ++i){
		for(int j = i; j <= k; ++j){
			g[i][j] = min(g[i][j - 1], f[i][j]);
			f[i + 1][j + 1] = max(g[i][j], (ll)abs(a[i + 1] - b[j + 1]) + abs(b[j + 1] - p));
		}
	}
	
	printf("%lld\n", g[n][k]);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}