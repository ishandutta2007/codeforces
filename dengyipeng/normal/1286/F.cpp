#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define maxn 20
#define ll long long 
using namespace std;

int n,m,i,j,k,id[1<<maxn],cnt[1<<maxn],f[1<<maxn],g[1<<maxn],h[1<<maxn];
ll a[maxn],sum[1<<maxn];
struct arr{
	ll x;int a,b;
	arr(ll _x=0,int _a=0,int _b=0){x=_x,a=_a,b=_b;}
};
int operator<(arr a,arr b){return a.x<b.x;}
vector<arr> A[1<<maxn],B[1<<maxn];

void prepare(){
	for(int S=0;S<1<<m;S++) {
		for(int T=S;T>=0;T=(!T)?-1:((T-1)&S))
			A[S].push_back(arr(sum[S^T]-sum[T],T>0,S-T>0));
		sort(A[S].begin(),A[S].end());
	} 
	for(int S=0;S<1<<(n-m);S++) {
		for(int T=S;T>=0;T=(!T)?-1:((T-1)&S)) 
			B[S].push_back(arr(sum[(S^T)<<m]-sum[T<<m],T>0,S-T>0));
		sort(B[S].begin(),B[S].end());
	}
}

int check(int S){
	if ((sum[S]-cnt[S])%2==0) return 0;
	if (cnt[S]==1) return 0;
	int S1=S&((1<<m)-1),S2=(S^S1)>>m,i,j;
	for(i=0,j=B[S2].size()-1;i<A[S1].size();i++){
		while (j>0&&A[S1][i].x+B[S2][j-1].x>-cnt[S]) j--;
		for(k=j;k<B[S2].size()&&abs(A[S1][i].x+B[S2][k].x)<cnt[S];k++)
			if (A[S1][i].a+B[S2][k].a&&A[S1][i].b+B[S2][k].b)
				return 1;
	}
	return 0;
}

int main(){
	scanf("%d",&n),m=n/2;
	for(i=0;i<n;i++) scanf("%lld",&a[i]),id[1<<i]=i;
	for(i=1;i<1<<n;i++) sum[i]=sum[i^(i&-i)]+a[id[i&-i]];
	for(i=1;i<1<<n;i++) h[i]=h[i^(i&-i)]+(a[id[i&-i]]==0);
	for(i=1;i<1<<n;i++) cnt[i]=cnt[i^(i&-i)]+1;
	prepare();
	for(int S=1;S<1<<n;S++) if (!f[S]&&check(S)){
		int W=((1<<n)-1)^S; f[S]=1;
		for(int T=W;T;T=(T-1)&W)
			f[S|T]=max(f[S|T],f[T]+1);
	}
	int ans=n;
	for(int S=0;S<1<<n;S++) ans=min(ans,n-f[S]-h[((1<<n)-1)^S]);
	printf("%d",ans);
}