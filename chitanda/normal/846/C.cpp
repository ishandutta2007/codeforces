#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int a[5010];
ll f[5010], g[5010], h[5010];

int main(){
	scanf("%d", &n);
	memset(f, 128, sizeof(f));
	memset(g, 128, sizeof(g));
	memset(h, 128, sizeof(h));
	f[0] = g[0] = h[0] = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		f[i] = f[i - 1] + a[i];
		for(int j = 0; j < i; ++j){
			g[i] = max(g[i], f[j] - (f[i] - f[j]));
			h[i] = max(h[i], g[j] + (f[i] - f[j]));
		}
		g[i] = max(g[i], f[i]);
		h[i] = max(h[i], g[i]);		
	}
	ll res = f[n] - 1;
	int d1, d2, d3;
	for(int i = 0; i <= n; ++i)
		if(h[i] - (f[n] - f[i]) > res){
			res = h[i] - (f[n] - f[i]);
			d3 = i;
		}
	for(int i = 0; i <= d3; ++i)
		if(g[i] + (f[d3] - f[i]) == h[d3])
			d2 = i;
	for(int i = 0; i <= d2; ++i)
		if(f[i] - (f[d2] - f[i]) == g[d2])
			d1 = i;
	printf("%d %d %d\n", d1, d2, d3);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}