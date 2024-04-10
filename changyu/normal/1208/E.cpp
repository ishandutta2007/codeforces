#include<cstdio>
#define max(a,b)((a)>(b)?(a):(b))
#define int long long
const int N=1e6+3,INF=1e15;
int m,n,k,a[N],ans[N],q[N],l,r,mx;
inline void Add(int l,int r,int a,int f){
	if(f)a=max(a,0);
	ans[l]+=a,ans[r+1]+=-a;
}
signed main(){
	scanf("%lld%lld",&m,&n);
	for(;m--;){
	  scanf("%lld",&k);
	  for(int i=1;i<=k;i++)scanf("%lld",a+i);
	  if(k+k>=n){
		q[l=r=0]=1;
		for(int i=1,j1=1,j2=1;i<=n;i++){
		  for(;j2<=i&&j2<=k;j2++){
			for(;l<=r&&a[q[r]]<a[j2];r--);
			q[++r]=j2;
		  }
		  for(;i+(k-j1)>n;j1++);
		  for(;l<=r&&q[l]<j1;l++);
		  Add(i,i,a[q[l]],i>k||i<=n-k);
		}
	  }
	  else{
	  	mx=-INF;
		for(int i=1;i<=k;i++)
		  mx=max(mx,a[i]),Add(i,i,mx,1);
		mx=-INF;
		for(int i=1;i<=k;i++)
		  mx=max(mx,a[k-i+1]),Add(n-i+1,n-i+1,mx,1);
		Add(k+1,n-k,mx,1);
	  }
	}
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1],printf("%lld ",ans[i]);
	return 0;
}