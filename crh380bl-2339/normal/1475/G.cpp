#include<bits/stdc++.h>
using namespace std;
namespace Numbertheory{
	const int N=200000+5;
	bool bo[N];
	int prime[N],cnt=0;
	int mu[N],phi[N];
	int factor[N][20],w[N];
	int i,j;
	void init(){
		mu[1]=1;
		phi[1]=1;
		int i,j,k;
		for(i=2;i<N;++i){
			if(!bo[i]){
				mu[i]=-1;
				phi[i]=i-1;
				prime[++cnt]=i;
			}
			for(j=1;j<=cnt&&i*prime[j]<N;++j){
				bo[i*prime[j]]=1;
				if(i%prime[j]==0){
					phi[i*prime[j]]=phi[i]*prime[j];
					mu[i*prime[j]]=0;
					break;
				}
				mu[i*prime[j]]=-mu[i];
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
		for(i=2;i<N;++i){
			j=i;
			for(k=1;k<=cnt&&prime[k]*prime[k]<=j;++k){
				if(j%prime[k]==0){
					factor[i][++w[i]]=prime[k];
					while(j%prime[k]==0)j/=prime[k];
				}
			}
			if(j>1)factor[i][++w[i]]=j;
		}
	}
	void test(int n){
		int j,i;
		for(i=1;i<=n;++i){
			printf("%d:",i);
			for(j=1;j<=w[i];++j)printf("%d ",factor[i][j]);
			puts("");
		}
	}
}
using namespace Numbertheory;
int s[200002],f[200002],a[200002];
int DFS(int x){
	if(f[x]!=-1)return f[x];
	if(x==1)return f[x]=s[1];
	int i,ad=0;
	for(i=1;i<=w[x];++i)ad=max(ad,DFS(x/factor[x][i]));
	return f[x]=ad+s[x];
}
int main(){
	init();
	//test(40);
	int T,n,x,i,ans;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(s,0,sizeof(s));
		memset(f,-1,sizeof(f));
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			++s[a[i]];
		}
		ans=0;
		for(i=1;i<=n;++i)ans=max(ans,DFS(a[i]));
		printf("%d\n",n-ans);
	}
	return 0;
}