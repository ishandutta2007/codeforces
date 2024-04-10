#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int MX=200011,B=500;
struct Edge{
	int u,v;
}e[MX];
int pool[MX],*G[MX];
int D[MX],vis[MX];
int n,m,q,bel[MX],dia[MX],mx[MX],smx[MX],mxf[MX],sz[MX],no[MX],tot;
double ans[MX];int ansvis[MX];
vector<int>F[MX],C[MX];vector<LL>S[MX];
void dfs(int k,int f,int B){
	bel[k]=B;vis[k]=1;
	for(int *i=G[k];i!=G[k+1];i++)if(*i!=f)dfs(*i,k,B);
}
void dp1(int k,int f){
	mx[k]=smx[k]=0;
	for(int *i=G[k];i!=G[k+1];i++){
		if(*i!=f){
			dp1(*i,k);
			smx[k]=max(smx[k],mx[*i]+1);
			if(smx[k]>mx[k])swap(mx[k],smx[k]);
		}
	}
}
void dp2(int k,int f){
	mxf[k]=0;
	if(f)mxf[k]=max((mx[f]==mx[k]+1)?smx[f]:mx[f],mxf[f])+1;
	for(int *i=G[k];i!=G[k+1];i++)if(*i!=f)dp2(*i,k);
}
void gt(int k,int f,int B){
	sz[B]++;
	dia[B]=max(dia[B],max(mxf[k]+mx[k],mx[k]+smx[k]));
	for(int *i=G[k];i!=G[k+1];i++)if(*i!=f)gt(*i,k,B);
}
void gt2(int k,int f,int B){
	F[B][max(mx[k],mxf[k])]++;
	for(int *i=G[k];i!=G[k+1];i++)if(*i!=f)gt2(*i,k,B);
}
void wk(int k){
	dfs(k,0,k);
	dp1(k,0);
	dp2(k,0);
	gt(k,0,k);
	F[k].resize(dia[k]+1);
	S[k].resize(dia[k]+1);
	C[k].resize(dia[k]+1);
	gt2(k,0,k);
	for(int i=1;i<=dia[k];i++)S[k][i]=S[k][i-1]+(LL)i*F[k][i];
	C[k][0]=F[k][0];
	for(int i=1;i<=dia[k];i++)C[k][i]=C[k][i-1]+F[k][i];
}
double calc(int u,int v){
	int lm=max(dia[u],dia[v]);
	double tot=0.0;
	//for(int i=1;i<=n;i++)printf("%d %d %d\n\n",i,mx[i],mxf[i]);
	for(int i=0;i<=dia[u];i++){
		//for(int j=0;j<=dia[u];j++)printf("%d %d\n",j,F[u][j]);
		//for(int j=0;j<=dia[v];j++)printf("%d %d\n",j,F[v][j]);
		//printf("%f %f %f",(double)F[u][i],(double)((lm-i-1<0)?0:C[v][min(lm-i-1,dia[v])])*(double)lm,(double)(i+1)*(dia[v]>lm-i-1?C[v][dia[v]]-((lm-i-1<0)?0:C[v][lm-i-1]):0)+(dia[v]>lm-i-1?S[v][dia[v]]-((lm-i-1<0)?0:S[v][lm-i-1]):0));
		tot+=(double)F[u][i]*((double)((lm-i-1<0)?0:C[v][min(lm-i-1,dia[v])])*(double)lm+(double)(i+1)*(dia[v]>lm-i-1?C[v][dia[v]]-((lm-i-1<0)?0:C[v][lm-i-1]):0)+(dia[v]>lm-i-1?S[v][dia[v]]-((lm-i-1<0)?0:S[v][lm-i-1]):0));
	}
	return tot/(double)((LL)sz[u]*sz[v]);
}
inline int rd(){
	char ch=getchar();LL x=0LL;
	while(ch<'0'&&ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int main(){
	n=rd(),m=rd(),q=rd();
	for(int i=1;i<=m;i++){
		e[i].u=rd(),e[i].v=rd(),++D[e[i].u],++D[e[i].v];
	}
	G[1]=pool;for(int i=1;i<=n;i++)G[i+1]=G[i]+D[i];
	for(int i=1;i<=m;i++)G[e[i].u][--D[e[i].u]]=e[i].v,G[e[i].v][--D[e[i].v]]=e[i].u;
	for(int i=1;i<=n;i++)if(!vis[i])wk(i);
	for(int i=1;i<=n;i++){
		if(bel[i]==i&&sz[i]>B){
			no[i]=tot++;
		}
	}
	for(int i=1;i<=q;i++){
		int u=rd(),v=rd();
		if(bel[u]==bel[v])puts("-1");
		else{
			if(sz[bel[v]]<sz[bel[u]]||(sz[bel[v]]==sz[bel[u]]&&u>v))swap(u,v);
			if(bel[u]>B){
				printf("%.10f\n",(ansvis[no[bel[u]]*tot+no[bel[v]]]?ans[no[bel[u]]*tot+no[bel[v]]]:(ans[no[bel[u]]*tot+no[bel[v]]]=calc(bel[u],bel[v]))));
			}else printf("%.10f\n",calc(bel[u],bel[v]));
		}
	}
	return 0;
}