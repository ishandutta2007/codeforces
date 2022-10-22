#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxm 1000005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[maxm],f[2][9][9];
int main(){
	scanf("%d%d",&n,&m);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		int b;
		scanf("%d",&b);
		a[b]++;
	}
	for(int i = 1;i <= m;i++){
		if(a[i] > 8){
			int num = (a[i] - 6 + 2) / 3;
			ans += num;
			a[i] -= num * 3;
		}
	}
	for(int i = 0;i <= a[1];i++){
		for(int j = 0;j <= a[2];j++){
			f[0][i][j] = i / 3 + j / 3;
		}
	}
	for(int i = 3;i <= m;i++){
		int cur = i & 1,pre = cur ^ 1;
		for(int j = 0;j <= a[i - 1];j++){
			for(int k = 0;k <= a[i];k++){
				f[cur][j][k] = f[pre][a[i - 2]][j];
				if(a[i - 2] >= 1 && k >= 1 && j >= 1)
					f[cur][j][k] = max(f[cur][j][k],f[pre][a[i - 2] - 1][j - 1] + 1);
				if(a[i - 2] >= 2 && k >= 2 && j >= 2)
					f[cur][j][k] = max(f[cur][j][k],f[pre][a[i - 2] - 2][j - 2] + 2);
				if(k >= 3) f[cur][j][k] = max(f[cur][j][k],f[cur][j][k - 3] + 1);
			}
		}
	}
	printf("%d\n",ans + f[m & 1][a[m - 1]][a[m]]);
	return 0;
}