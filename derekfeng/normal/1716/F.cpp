#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int n,m,K,S[2005][2005],iv[2005];
int myp(int x,int t){
	int a=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
	return a;
}
void sol(){
	scanf("%d%d%d",&n,&m,&K);int FC=n,ans=0,pw=(m+1)/2;
	int inm=myp(m,M-2),PW=myp(m,n-1);
	for(int i=1,cur=n;i<=K;i++,cur--,FC=(ll)FC*cur%M){
		int cb=(ll)FC*iv[i]%M;if(!cb)break;
		(ans+=(ll)S[K][i]*pw%M*PW%M*cb%M)%=M;
		pw=(ll)pw*((m+1)/2)%M;
		PW=(ll)PW*inm%M;
	}
	printf("%d\n",ans);
}
int main(){
	S[0][0]=1;
	for(int i=1;i<=2000;i++)for(int j=1;j<=i;j++)
		S[i][j]=((ll)S[i-1][j]*j+S[i-1][j-1])%M;
	for(int i=1,fc=1;i<=2000;i++,fc=(ll)fc*i%M)
		for(int j=i;j<=2000;j++)S[j][i]=(ll)S[j][i]*fc%M;
	iv[0]=1;for(int i=1;i<=2000;i++)iv[i]=(ll)iv[i-1]*myp(i,M-2)%M;
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}