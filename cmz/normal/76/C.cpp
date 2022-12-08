#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
int n,k,T,pre[25],t[25],m[25][25],dp[(1<<22)+5];
char s[200005];
int main() {
	scanf("%d%d%d%s",&n,&k,&T,s+1);
	for(int i=0; i<k; i++)scanf("%d",&dp[1<<i]);
	for(int i=0; i<k; i++)
		for(int j=0; j<k; j++)
			scanf("%d",&m[i][j]);
	memset(pre,-1,sizeof(pre));
	int S=0;
	for(int i=1; i<=n; i++) {
		int y=s[i]-'A';
		S|=(1<<y);
		for(int x=0; x<k; x++)
			if(pre[x]>=0) {
				if(!((pre[x]>>x)&1)&&!((pre[x]>>y)&1)) {
					dp[pre[x]]+=m[x][y];
					dp[pre[x]|(1<<x)]-=m[x][y];
					dp[pre[x]|(1<<y)]-=m[x][y];
					dp[pre[x]|(1<<x)|(1<<y)]+=m[x][y];
				}
				pre[x]|=(1<<y);
			}
		pre[y]=0;
	}
	int K=1<<k;
	for(int i=0; i<k; i++)
		for(int j=0; j<K; j++)
			if((j>>i)&1)dp[j]+=dp[j^(1<<i)];
	int ans=0;
	for(int i=0; i<K; i++)
		if((i&S)==i&&dp[i]<=T&&i!=S)
			ans++;
	printf("%d\n",ans);
	return 0;
}