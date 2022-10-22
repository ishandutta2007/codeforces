#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353,B=720720;
int f[B],nf[B];
int g[B],ng[B];
int n,a,x,y,k,MOD;
int s,ans;
int main(){
	scanf("%d%d%d%d%d%d",&n,&a,&x,&y,&k,&MOD);
	for(int i=0;i<(1<<k);i++){
		int mul=1,sum=0;
		for(int j=0;j<k;j++){
			if((i>>j)&1)sum++;
			else mul=(ll)mul*(n-1)%M;
		}
		(s+=(ll)mul*sum%M)%=M;
	}
	for(int i=0;i<n;i++){
		if(i>0)a=((ll)a*x+y)%MOD;
		(ans+=(ll)(a-a%B)*s%M)%=M;
		g[a%B]++;
	}
	for(int i=1;i<=k;i++){
		memset(nf,0,sizeof(nf));
		memset(ng,0,sizeof(ng));
		for(int j=0;j<B;j++)if(g[j]){
			(ng[j]+=(ll)g[j]*(n-1)%M)%=M;
			(nf[j]+=(ll)f[j]*(n-1)%M)%=M;
			int nj=j-j%i;
			(ng[nj]+=g[j])%=M;
			(nf[nj]+=((ll)g[j]*j+f[j])%M)%=M;
		}
		memcpy(f,nf,sizeof(nf));
		memcpy(g,ng,sizeof(ng));
	}
	for(int i=0;i<B;i++)(ans+=f[i])%=M;
	printf("%d",ans);
}