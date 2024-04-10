#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 5005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[maxn],m;
int dp[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		int c;
		scanf("%d",&c);
		if(a[m] != c) a[++m] = c;
	}
	for(int i = 1;i <= m;i++) dp[i][i] = 1;
	for(int w = 2;w <= m;w++){
		for(int i = 1;i + w - 1 <= m;i++){
			int j = i + w - 1;
			dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]);
			if(a[i] == a[j]) dp[i][j] = max(dp[i][j],dp[i + 1][j - 1] + 2);
		}
	}
	printf("%d\n",m - (dp[1][m] + 1) / 2);
	return 0;
}