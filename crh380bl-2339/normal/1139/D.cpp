#include<cstdio>
#define N 1000000
#define mod 1000000007
int p[N],tot=0,mu[N];
bool bo[N];
int ksm(int x,int y){
	int t=1;
	while(y){
		if(y&1)t=1LL*t*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return t;
}
int main(){
	int n,i,j,ans=1,m;
	scanf("%d",&n);
	mu[1]=1;
	for(i=2;i<=n;++i){
		if(!bo[i]){
			mu[i]=-1;
			for(j=2;j*i<=n;++j){
				bo[i*j]=1;
				if(j%i==0)mu[i*j]=0;
				else mu[i*j]=-mu[j];
			}
		}
	}
	//for(i=1;i<=n;++i)printf("%d ",mu[i]);
	for(i=2;i<=n;++i){
		m=n/i;
		ans=(ans+1LL*(mod-mu[i])*m%mod*ksm(n-m,mod-2)%mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}