#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 200005
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int num[3],n,l,r;
ll dp[maxn][3];
int main(){
	scanf("%d%d%d",&n,&l,&r);
	l--;
	num[0] = r / 3;
	num[1] = r / 3; if(r % 3 >= 1) num[1]++;
	num[2] = r / 3; if(r % 3 >= 2) num[2]++;
	num[0] -= l / 3;
	num[1] -= l / 3; if(l % 3 >= 1) num[1]--;
	num[2] -= l / 3; if(l % 3 >= 2) num[2]--;
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		dp[i][0] = (dp[i - 1][1] * num[2] + dp[i - 1][2] * num[1] + dp[i - 1][0] * num[0]) % mod;
		dp[i][1] = (dp[i - 1][1] * num[0] + dp[i - 1][2] * num[2] + dp[i - 1][0] * num[1]) % mod;
		dp[i][2] = (dp[i - 1][1] * num[1] + dp[i - 1][2] * num[0] + dp[i - 1][0] * num[2]) % mod;
	}
	printf("%I64d\n",dp[n][0]);
	return 0;
}