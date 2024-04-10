#include<bits/stdc++.h>
using namespace std;
inline int lbit(int x){return __builtin_ffs(x);}
inline int lowbit(int x){return x&-x;}
const int inf=0x3f3f3f3f;
const int N=20,M=20,LET=26;
int n,m;
char s[N+1][M+5];
int a[N+1][M+1];
int msk[M+1][LET],cst[M+1][LET];
int dp[1<<N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",a[i]+j);
	for(int i=1;i<=m;i++)for(int j=0;j<26;j++){
		int sum=0,mx=0;
		for(int k=1;k<=n;k++)if(s[k][i]=='a'+j)
			msk[i][j]|=1<<k-1,sum+=a[k][i],mx=max(mx,a[k][i]);
		cst[i][j]=sum-mx;
	}
	for(int i=1;i<1<<n;i++){
		dp[i]=inf;
		int f1=lbit(i);
		for(int j=1;j<=m;j++)dp[i]=min(dp[i],dp[i^lowbit(i)]+a[f1][j]);
		for(int j=1;j<=m;j++){
			dp[i]=min(dp[i],dp[i^(i&msk[j][s[f1][j]-'a'])]+cst[j][s[f1][j]-'a']);
		}
	}
//	for(int i=0;i<1<<n;i++){
//		printf("dp[");for(int j=1;j<=n;j++)cout<<!!(i&1<<j-1);printf("]=%d\n",dp[i]);
//	}
	printf("%d",dp[(1<<n)-1]);
	return 0;
}
/*1
4 5
abcde
abcde
abcde
abcde
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
*/
/*2
4 3
abc
aba
adc
ada
10 10 10
10 1 10
10 10 10
10 1 10
*/
/*3
3 3
abc
ada
ssa
1 1 1
1 1 1
1 1 1
*/
/*4
5 2
aa
aa
ab
bb
bb
1 100
100 100
1 1
100 100
100 1
*/