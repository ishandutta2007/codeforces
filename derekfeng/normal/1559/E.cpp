#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,l[53],r[53],f[100004],L[53],R[53];
int dp[53][100004],s[100004];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	for(int i=m;i;i--){
		int N=m/i;
		bool tmp=1;
		for(int j=1;j<=n;j++){
			L[j]=(l[j]-1)/i+1,R[j]=r[j]/i;
			if(L[j]>R[j]){
				tmp=0;
				break;
			}
		}
		if(!tmp){
			f[i]=0;
			continue;
		}
		for(int j=0;j<=n;j++)memset(dp,0,(N+1)<<2);
		dp[0][0]=1;
		for(int j=1;j<=n;j++){
			s[0]=dp[j-1][0];
			for(int k=1;k<=N;k++)s[k]=(s[k-1]+dp[j-1][k])%M;
			for(int k=0;k<=N;k++){
				int st=k-R[j],ed=k-L[j];
				st=max(st,0);
				if(st>ed)dp[j][k]=0;
				else if(st==0)dp[j][k]=s[ed];
				else dp[j][k]=(s[ed]+M-s[st-1])%M;
			}
		}
		for(int j=0;j<=N;j++)(f[i]+=dp[n][j])%=M;
		for(int j=i+i;j<=m;j+=i)f[i]=(f[i]+M-f[j])%M;
	}
	printf("%d",f[1]);
}