#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}

int n, b[1000010], tot, f[1000010], c[100], num, g[1000010];

int check(int x){
	while(x){
		if(x % 10 > 1) return 0;
		x /= 10;
	}
	return 1;
}
void dfs(int n){
	c[++ num] = g[n];
	if(f[n] > 1) dfs(n - g[n]);
}
int main(){
	scanf("%d", &n);
	memset(f, 63, sizeof(f));
	for(int i = 0;i <= n;i ++) if(check(i)) b[++ tot] = i, f[i] = 1, g[i] = i;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= tot;j ++)
			if(i >= b[j]){
				if(f[i - b[j]] + 1 < f[i]){
					f[i] = f[i - b[j]] + 1;
					g[i] = b[j];
				}
			}
	printf("%d\n", f[n]);
	dfs(n);
	for(int i = 1;i <= num;i ++) printf("%d ", c[i]);
		
	return 0;
}