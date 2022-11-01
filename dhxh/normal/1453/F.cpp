#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000 + 5;

int t;
int n;

int f[maxn][maxn];
int suf[maxn][maxn];
int a[maxn];
int p[maxn];

void solve(){
	int i, j;
	
	f[n][n + 1] = 0;
	suf[n][n + 1] = 0;
	
	for(i=n-1;i>0;i--){
		int cnt = 0;
		for(j=i+1;j<=i+a[i];j++) p[j] = 0;
		for(j=i+1;j<=i+a[i];j++){
			cnt += p[j];
			
			f[i][j] = min(f[i][j], suf[j][i + a[i] + 1] + cnt);
			
			p[j + a[j] + 1] -= 1;
			cnt++;
		}
		
		for(j=i+a[i];j>i;j--){
			suf[i][j] = min(f[i][j], suf[i][j + 1]);
		}
	}
	
	int ans = 0x3f3f3f3f;
	for(i=2;i<=n;i++){
		ans = min(ans, f[1][i]);
	}
	printf("%d\n", ans);
}

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d", &n);
		
		for(i=1;i<=n;i++) scanf("%d", &a[i]);
		
		for(i=0;i<=n+2;i++){
			for(j=0;j<=n+2;j++){
				f[i][j] = suf[i][j] = 0x3f3f3f3f;
			}
		}
		
		solve();
	}
	
	return 0;
}