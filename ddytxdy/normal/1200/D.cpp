#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N = 2010;
int n, k, mx1[N], mn1[N], mx2[N], mn2[N],num[N],ans,anss,yy; char c[N][N]; bool flag[N];
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)scanf("%s", c[i] + 1);
	for (int i = 1; i <= n; i++) for(int j=1;j<=n;j++)if(c[i][j]=='B'){
		if (!mn1[i])mn1[i] = j;
		mx1[i] = j; 
	}
	for (int j = 1; j <= n; j++)for (int i = 1; i <= n; i++)if (c[i][j] == 'B') {
		if (!mn2[j])mn2[j] = i;
		mx2[j] = i; 
	}
	for (int i = 1; i <= n; i++)if (!mx1[i])yy++;
	for (int i = 1; i <= n; i++)if (!mx2[i])yy++;
	for (int i = 1; i <= n; i++)if (mx1[i] && mx1[i] <= k) {
		flag[i] = 1;
		for (int j = max(1, i - k + 1); j <= i; j++)num[j]++;
	}
	for (int i = 1; i <= k; i++) 
		for (int j = max(1,mx2[i] - k + 1); j <= mn2[i]; j++)num[j]++;
	for (int i = 1; i <= n; i++)ans = max(ans, num[i]);
	for (int i = 2; i <= n - k + 1; i++) {
		for (int j = 1; j <= n; j++)if (mn1[j] && i > mn1[j] && flag[j]) {
			flag[j] = 0;
			for (int l = max(1, j - k + 1); l <= j; l++)num[l]--;
		}
		for (int j = 1; j <= n; j++)if (mx1[j] <= i + k - 1 && mn1[j] >= i && !flag[j]) {
			flag[j] = 1;
			for (int l = max(1, j - k + 1); l <= j; l++)num[l]++;
		}
		for (int j = max(1,mx2[i-1] - k + 1); j <= mn2[i-1]; j++)num[j]--;
		if(i+k-1<=n)for (int j = max(1,mx2[i+k-1] - k + 1); j <= mn2[i+k-1]; j++)num[j]++;
		for (int j = 1; j <= n; j++)ans = max(ans, num[j]);
	}
	printf("%d\n", ans + yy);
	return 0;
}