#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll f[1003],g[1003];
int a[1003][1003],sp,pt;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]),f[i]+=a[i][j],g[i]+=(ll)a[i][j]*a[i][j];
	for(int i=1;i<m-1;i++)if(f[i]+f[i]==f[i-1]+f[i+1]){sp=f[i]-f[i-1],pt=i;break;}
	int mom;
	for(int i=0;i<m;i++)if(f[i]!=f[pt]+sp*(i-pt)){mom=i;break;}
	printf("%d ",mom);
	ll add=f[pt]+sp*(mom-pt)-f[mom],sig;
	if(mom<3)sig=g[mom+1]+g[mom+3]-2*g[mom+2];
	else sig=g[mom-3]+g[mom-1]-2*g[mom-2];
	for(int i=0;i<n;i++){
		ll now=a[mom][i],res=now+add;
		ll dif=res*res-(ll)a[mom][i]*a[mom][i],sig1;
		if(mom<2)sig1=g[mom+2]+(g[mom]+dif)-2*g[mom+1];
		else sig1=g[mom-2]+(g[mom]+dif)-2*g[mom-1];
		if(sig1==sig){
			printf("%lld",res);
			fflush(stdout);
			return 0;
		}
	}
}