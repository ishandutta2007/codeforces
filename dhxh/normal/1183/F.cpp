#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

int a[maxn];
int f[maxn];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k;
	int ans = 0;
	
	t = read();
	
	while(t--){
		ans = 0;
		n = read();
		for(i=1;i<=n;i++){
			a[i] = read();
		}
		
		sort(a + 1, a + n + 1);
		
		m = n;
		n = 0;
		for(i=1;i<=m;i++){
			if(a[i] != a[n]){
				a[++n] = a[i];
			}
		}
		
		for(i=1;i<=n;i++){
			ans = max(ans, a[i]);
			for(j=i-1;j>0;j--){
				if(a[i] % a[j] == 0)continue;
				ans = max(ans, a[i] + a[j]);
				for(k=j-1;k>0;k--){
					if(a[i] % a[k] == 0 or a[j] % a[k] == 0)continue;
					ans = max(ans, a[i] + a[j] + a[k]);
					break;
				}
				break;
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}