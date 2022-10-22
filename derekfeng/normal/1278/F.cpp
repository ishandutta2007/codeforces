#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
	return a;
}
int calc(int x,int n){
	int ans=1;
	for(int i=x,j=0;j<n;i--,j++)ans=(ll)ans*i%M;
	return ans;
}
int S[5003][5003];
int n,m,K,ans;
int main(){
	scanf("%d%d%d",&n,&m,&K),m=myp(m,M-2);
	S[0][0]=1;
	for(int i=1;i<=K;i++)for(int j=1;j<=i;j++)S[i][j]=((ll)S[i-1][j]*j+S[i-1][j-1])%M;
	for(int i=0;i<=K;i++)(ans+=(ll)S[K][i]*myp(m,i)%M*calc(n,i)%M)%=M;
	printf("%d",ans);
}