#include<cstdio>
typedef long long ll;
const int N=2e6+3,M=1e9+7,K=9;
inline int Mod(int a){return a<M?a:a-M;}
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int n,m,mu[N],np[N],p[N],d[N],k,ans,prime[K],alpha[K],sum[N],yc_pow[N];long long xorsum;
void Dfs(int t,int s,int x){
	if(t>k){
	  ans=Mod(ans-sum[s]+M);
	  sum[s]=Mod(mu[s]*yc_pow[x/s]+M);
	  ans=Mod(ans+sum[s]);
	  return;
	}
	int tmp=1;
	for(int i=0;i<=alpha[t];i++){
	  Dfs(t+1,s*tmp,x);
	  tmp*=prime[t];
	}
}
signed main(){
	mu[1]=1;
	for(int i=2;i<N;i++){
	  if(!np[i])mu[i]=-1,p[++k]=i,d[i]=i;
	  for(int j=1;j<=k&&i*p[j]<N;j++){
		np[i*p[j]]=1;
		if(i%p[j])mu[i*p[j]]=-mu[i],d[i*p[j]]=p[j];
		else{mu[i*p[j]]=0,d[i*p[j]]=d[i];break;}
	  }
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)yc_pow[i]=Pow(i,n);
	for(int i=1,j;i<=m;i++){
	  k=0;
	  for(j=i;j>1;j/=d[j])
		d[j]==prime[k]?alpha[k]++:(++k,prime[k]=d[j],alpha[k]=1);
	  Dfs(1,1,i);
	  xorsum+=ans^i;
	}printf("%lld",xorsum%M);
	return 0;
}