#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
const int MX=100111;
typedef long long LL;

struct Edge{int to,nxt;}e[MX<<1];int ec;
int hed[MX];
int n;
map<int,int>*c[MX];
LL ans[MX];int mx[MX],sz[MX];
int a[MX];

#define FEF(k,i) for(int i=hed[k];i;i=e[i].nxt)if(e[i].to!=f)
inline void ade(int f,int t){++ec,e[ec].nxt=hed[f],hed[f]=ec,e[ec].to=t;}

void dfs(int k,int f){
	sz[k]=1;
	FEF(k,i)dfs(e[i].to,k),sz[k]+=sz[e[i].to];
}
inline void INS(int k,int col,int C){
	int t=((*(c[k]))[col]+=C);
	if(t>mx[k])mx[k]=t,ans[k]=col;
	else if(t==mx[k])ans[k]+=col;
}
void dfswk(int k,int f){
	int mxssz=0,mxs=0;
	
	FEF(k,i)if(sz[e[i].to]>mxssz)mxssz=sz[e[i].to],mxs=e[i].to;
	
	if(mxs){
		dfswk(mxs,k);
		c[k]=c[mxs];mx[k]=mx[mxs],ans[k]=ans[mxs];
		INS(k,a[k],1);
		FEF(k,i)if(e[i].to!=mxs){
			dfswk(e[i].to,k);
			for(map<int,int>::iterator it=c[e[i].to]->begin();it!=c[e[i].to]->end();it++)
				INS(k,it->first,it->second);
		}
	}else{
		c[k]=new map<int,int>;
		c[k]->clear();
		INS(k,a[k],1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		ade(u,v),ade(v,u);
	}
	dfs(1,-1);
	dfswk(1,-1);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);puts("");
	return 0;
}