#include<bits/stdc++.h>
#define int long long
const int N=5e5+3,D=1<<19,INF=1e18;
int n,a[N],dp[N],b[N],tmp[N],k;
struct segment_tree{
	int mx[D+D];
	segment_tree(){std::fill(mx,mx+D*2,-INF);}
	void Init(){
		for(int i=0;i<=n+1;i++){
			for(int k=i+D;k;k>>=1)mx[k]=-INF;
		}
	}
	inline void Update(int k,int a){
		//printf("Update %d %d\n",k,a);
		for(k+=D;k;k>>=1)mx[k]=std::max(mx[k],a);
	}
	inline int Max(int l,int r){
		int res=-INF;
		//printf("Max %d %d = ",l,r);
		for(l+=D-1,r+=D+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)res=std::max(res,mx[l^1]);
			if( r&1)res=std::max(res,mx[r^1]);
		}
		//printf("%lld\n",res);
		return res;
	}
}t;
inline int Sign(int a){
	if(a>0)return 1;
	if(a<0)return-1;
	return 0;
}
signed main(){
	int T;scanf("%lld",&T);for(;T--;){
	scanf("%lld",&n);
	a[0]=0;
	for(int i=1;i<=n;i++)scanf("%lld",a+i),a[i]+=a[i-1],tmp[i+1]=a[i];
	tmp[1]=0;
	std::sort(tmp+1,tmp+2+n);
	k=0;
	for(int i=1;i<=n+1;i++)if(i==1||tmp[i]!=tmp[i-1])tmp[++k]=tmp[i];
	for(int i=0;i<=n;i++)a[i]=std::lower_bound(tmp+1,tmp+1+k,a[i])-tmp;
	for(int i=0;i<=n+1;i++)b[i]=-INF;
	t.Init();
	dp[0]=0;
	b[a[0]]=0;
	t.Update(a[0],0);
	for(int i=1;i<=n;i++){
		dp[i]=std::max(dp[i-1]+Sign(a[i]-a[i-1]),std::max(t.Max(1,a[i]-1)+i,b[a[i]]));
	b[a[i]]=std::max(b[a[i]],dp[i]);
		t.Update(a[i],dp[i]-i);
		//printf("%d\n",dp[i]);
	}
	printf("%lld\n",dp[n]);
	}return 0;
}