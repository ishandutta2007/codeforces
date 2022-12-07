#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int B = 100;
int n, x;
int f[B + 1], g[B + 1];

int main(){
	scanf("%d", &n);
	memset(f, 127, sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &x); x /= 100;
		memcpy(g, f, sizeof(g));
		memset(f, 127, sizeof(f));
		for(int j = 0; j <= B; ++j)
			if(g[j] < 1e9){
				int p = min(j + x / 10, B);
				f[p] = min(f[p], g[j] + x);
				int t = min(x, j);
				f[j - t] = min(f[j - t], g[j] + x - t);
			}
	}
	int ans = 1e9;
	for(int i = 0; i <= B; ++i)
		ans = min(ans, f[i]);
	printf("%d\n", ans * 100);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}