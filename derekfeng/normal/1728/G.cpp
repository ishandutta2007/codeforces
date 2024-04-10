#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)
		if(t&1)a=(ll)a*x%M;
	return a;
}
int d,n,m,q;
int a[200004],b[20],P;
int s[20][200004],dp[65540];
int ord[20];
bool cmp(int x,int y){
	return abs(b[x]-P)<abs(b[y]-P);
}
int main(){
	scanf("%d%d%d",&d,&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);sort(a,a+n);
	for(int i=0;i<m;i++)scanf("%d",&b[i]);sort(b,b+m);
	for(int i=0;i<m;i++)for(int j=0;j<n;j++)
			s[i][j]=(ll)(j?s[i][j-1]:1)*abs(a[j]-b[i])%M;
	for(int i=1;i<(1<<m);i++){
		int A=__builtin_ctz(i);
		if(__builtin_popcount(i)==1)dp[i]=s[A][n-1];
		else{
			int B=__builtin_ctz(i^(1<<A));
			int p=(b[A]+b[B])/2,tmp=dp[i^(1<<A)];
			int pos=upper_bound(a,a+n,p)-a-1;
			if(~pos){
				tmp=(ll)tmp*myp(s[B][pos],M-2)%M;
				tmp=(ll)tmp*s[A][pos]%M;
			}
			dp[i]=tmp;
		}
	}
	for(int i=0;i<(1<<m);i++)if(__builtin_parity(i))dp[i]=M-dp[i];
	for(int i=0;i<m;i++)for(int j=0;j<(1<<m);j++)if((j>>i)&1)
		(dp[j]+=dp[j^(1<<i)])%=M;
	for(int i=0;i<m;i++)ord[i]=i;
	scanf("%d",&q);while(q--){
		scanf("%d",&P);sort(ord,ord+m,cmp);
		int ans=myp(d+1,n+1),msk=(1<<m)-1;
		for(int i=0;i<m;i++){
			int x=ord[i];
			(ans+=(ll)(dp[msk]+M-dp[msk^(1<<x)])*abs(b[x]-P)%M)%=M;
			msk^=(1<<x);
		}
		printf("%d\n",ans);
	}
}