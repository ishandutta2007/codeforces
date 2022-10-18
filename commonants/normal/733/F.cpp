#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;
const int MX=200111;
struct Edge{
	int f,t,w,c,id,ismst;
	inline bool operator <(const Edge &x)const{return w<x.w;}
}e[MX];
int fa[MX],nxt[MX],nxtw[MX],hed[MX],tai[MX];
int F[MX],mxw[19][MX],lg2[MX];
int n,m,S;
vector<int>G[MX];

int ffa(int k){
	return k==fa[k]?k:(fa[k]=ffa(fa[k]));
}
void build_ST(){
	lg2[1]=0;
	for(int i=2;i<n;i++)lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=18;i++)
		for(int j=1;j+(1<<i)<=n;j++)
			mxw[i][j]=max(mxw[i-1][j],mxw[i-1][j+(1<<(i-1))]);
}
inline int que(int u,int v){
	u=F[u],v=F[v];
	if(u>v)swap(u,v);
	int d=lg2[v-u];
	return max(mxw[d][u],mxw[d][v-(1<<d)]);
}
int dfs(int k,int f,int t,int w){
	if(k==t)return 1;
	for(vector<int>::iterator it=G[k].begin();it!=G[k].end();it++){
		int to=e[*it].f^e[*it].t^k;
		if(to!=f){
			int res=dfs(to,k,t,w);
			if(res){
				if(e[*it].w==w){
					e[*it].ismst=0;
					return 0;
				}
				else return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)e[i].id=i;
	for(int i=1;i<=m;i++)scanf("%d",&e[i].w);
	for(int i=1;i<=m;i++)scanf("%d",&e[i].c);
	for(int i=1;i<=m;i++)scanf("%d%d",&e[i].f,&e[i].t);
	scanf("%d",&S);
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++)hed[i]=tai[i]=fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=ffa(e[i].f),fy=ffa(e[i].t);
		if(fx==fy)continue;
		fa[fx]=fy;nxt[tai[fx]]=hed[fy];nxtw[tai[fx]]=e[i].w;
		hed[fy]=hed[fx];
		e[i].ismst=1;G[e[i].f].push_back(i),G[e[i].t].push_back(i);
	}
	int tfc=0,st=hed[ffa(1)],ed=tai[ffa(1)];
	for(int i=st;i!=ed;i=nxt[i]){
		F[i]=++tfc;mxw[0][tfc]=nxtw[i];
	}
	F[ed]=++tfc;
	build_ST();
	int mxdec=-1,cn=0;
	for(int i=1;i<=m;i++){
		if(e[i].ismst){
			if(S/e[i].c>mxdec)mxdec=S/e[i].c,cn=i;
		}else{
			int k=que(e[i].f,e[i].t);
			if(k-e[i].w+S/e[i].c>mxdec)mxdec=k-e[i].w+S/e[i].c,cn=i;
		}
	}
	if(e[cn].ismst){
		e[cn].w-=mxdec;
	}else{
		e[cn].w-=S/e[cn].c;
		int k=que(e[cn].f,e[cn].t);
		dfs(e[cn].f,0,e[cn].t,k);
		e[cn].ismst=1;
	}
	long long ans=0;
	for(int i=1;i<=m;i++)if(e[i].ismst)ans+=e[i].w;
	printf("%lld\n",ans);
	for(int i=1;i<=m;i++)if(e[i].ismst)printf("%d %d\n",e[i].id,e[i].w);
	return 0;
}