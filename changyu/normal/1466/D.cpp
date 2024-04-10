#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3;
int n,a[N],d[N],t[N],k;ll ans;
bool Cmp(const int&a,const int&b){return a>b;}
signed main(){
	int u,v;
	int T;scanf("%d",&T);for(;T--;){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),ans+=a[i],d[i]=0;
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),++d[u],++d[v];
	k=0;
	for(int i=1;i<=n;i++)for(;--d[i];)t[++k]=a[i];
	std::sort(t+1,t+1+k,Cmp);
	printf("%lld",ans);for(int i=1;i<n-1;i++)printf(" %lld",ans+=t[i]);puts("");
	}return 0;
}