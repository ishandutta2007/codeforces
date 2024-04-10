#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

char str[maxn];
int f[(1 << 21)];
int n;

int main(){
	int i, j;
	
	scanf("%s", &str[1]);
	str[0] = '0';
	n = strlen(str) - 1;
	
	for(i=1;i<=n;i++){
		int mask = 0;
		for(j=i;j>0;j--){
			int x = str[j] - 'a';
			if((mask >> x) & 1)break;
			mask |= (1 << x);
			f[mask] = i - j + 1;
		}
	}
	
	for(i=0;i<(1<<20);i++){
		for(j=0;j<20;j++){
			if((i >> j) & 1){
				f[i] = max(f[i], f[i ^ (1 << j)]);
			}
		}
	}
	
	int ans = 0;
	
	for(i=0;i<(1<<20);i++){
		ans = max(ans, f[i] + f[(~i) & ((1 << 20) - 1)]);
	}
	
	printf("%d\n", ans);
	
	return 0;
}