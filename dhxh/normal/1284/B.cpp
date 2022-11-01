#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t;

int maxx[maxn];
int minx[maxn];
bool flag[maxn];
int cnt[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	long long ans = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		scanf("%d", &m);
		scanf("%d", &maxx[i]);
		minx[i] = maxx[i];
		for(j=2;j<=m;j++){
			scanf("%d", &x);
			if(x > minx[i]){
				flag[i] = true;
			}
			maxx[i] = max(maxx[i], x);
			minx[i] = min(minx[i], x);
		}
		if(!flag[i]){
			cnt[maxx[i]]++;
		}else{
			ans++;
		}
	}
	
	ans = 2ll * ans * n - 1ll * ans * ans;
	
	for(i=1e6+1;i>=0;i--){
		cnt[i] += cnt[i + 1];
	}
	
	for(i=1;i<=n;i++){
		if(!flag[i]){
			ans += cnt[minx[i] + 1];
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}