#include<cstdio>
#include<algorithm>
#include<bits/extc++.h>
using namespace std;
const int o=3.3e6,O=1e5+10;
int n,m,p1,p2,a[O][6],w[O],p[O],cnt[o],z=1,ans;__gnu_pbds::cc_hash_table<long long,int> ch;
inline bool cmp(int A,int B){return w[A]<w[B];}
inline long long f(int A,int B){return B*1ll*o+A;}
int calc(int*b,int u,int p){
	if(p>m) return cnt[u];
	int res=calc(b,u,p+1);
	if(ch.find(f(u,b[p]))!=ch.end()) res-=calc(b,ch[f(u,b[p])],p+1);
	return res;
}
void ins(int*b,int u,int p,int coef){
	if(p>m){cnt[u]+=coef;return;}
	ins(b,u,p+1,coef);
	if(ch.find(f(u,b[p]))==ch.end()) ch[f(u,b[p])]=++z;
	ins(b,ch[f(u,b[p])],p+1,coef);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;p[i]=i,scanf("%d",&w[i++])) for(int j=1;j<=m;++j) scanf("%d",&a[i][j]);
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;++i) sort(a[i]+1,a[i]+m+1);
	for(p1=1;p1<=n&&!calc(a[p[p1]],1,1);++p1) ins(a[p[p1]],1,1,1);
	if(p1>n){printf("-1");return 0;}
	for(p2=p1;calc(a[p[p1]],1,1);ins(a[p[--p2]],1,1,-1));
	ans=w[p[p1]]+w[p[p2]];
	for(++p1;p1<=n&&p2>1;ans=min(ans,w[p[p1++]]+w[p[p2]]))
		for(;calc(a[p[p1]],1,1);ins(a[p[--p2]],1,1,-1));
	printf("%d",ans);
	return 0;
}