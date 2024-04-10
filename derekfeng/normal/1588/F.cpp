#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=512;
int n,q,p[200004],N,T,S,hd[1500];
ll a[200004],b[400],c[1500];bool del[1500];
int d[1500][400],w[200004],P[1500];
int vis[200004],TG,sta[200004],SZ;
void dfs_p(int x){
	++TG;for(;;){
		if(vis[x]==TG)return;
		vis[x]=TG,sta[SZ++]=x,x=p[x];
	}
}
void calc(int t){
	memset(d[t],0,sizeof(d[t]));
	++TG;for(int x=hd[t];;x=p[x]){
		if(vis[x]==TG||w[x]!=t)break;
		vis[x]=TG,d[t][x>>9]++;
	}for(int j=1;j<=S;j++)d[t][j]+=d[t][j-1];
}
void clr(int t){
	del[t]=1;
	++TG;for(int x=hd[t];w[x]==t;x=p[x]){
		if(vis[x]==TG)break;
		vis[x]=TG,w[x]=-1,a[x]+=c[t],b[x>>9]+=c[t];
	}
}
void built(){
	for(int i=0;i<n;++i)if(~w[i])a[i]+=c[w[i]],b[i>>9]+=c[w[i]],w[i]=-1;N=0;
	int nTG=TG;for(int i=0;i<n;++i)if(vis[i]<=nTG){
		SZ=0,dfs_p(i);if(SZ<B+B)continue;int NN=N;
		for(int l=0,r=B;r<=SZ;l+=B,r+=B){
			if(r+B>SZ)r=SZ;c[++N]=0,del[N]=0;
			memset(d[N],0,sizeof(d[N])),hd[N]=sta[l];
			for(int j=l;j<r;++j)w[sta[j]]=N;calc(N);
		}for(int i=NN+1;i<N;++i)P[i]=i+1;P[N]=NN+1;
	}
}
ll qry(int p){
	if(p<0)return 0;
	ll ans=0;
	if(p>=B){
		int t=p>>9;
		for(int i=0;i<t;i++)ans+=b[i];
		for(int i=1;i<=N;i++)if(!del[i])ans+=c[i]*d[i][t-1];
	}for(int i=p-(p&511);i<=p;i++)ans+=a[i]+(~w[i]?c[w[i]]:0);
	return ans;
}
void ask(){
	int l,r;scanf("%d%d",&l,&r),l--,r--;
	printf("%lld\n",qry(r)-qry(l-1));
}
void dfs_upd(int x,int v){
	++TG;for(;;){
		if(vis[x]==TG)return;
		vis[x]=TG,a[x]+=v,b[x>>9]+=v,x=p[x];
	}
}
void dfs_uPd(int x,int v){
	++TG;for(;;){
		if(vis[x]==TG)return;
		vis[x]=TG,c[x]+=v,x=P[x];
	}
}
void upd0(){
	int x,v;scanf("%d%d",&x,&v);x--;
	if(!~w[x])dfs_upd(x,v);else dfs_uPd(w[x],v);
}
bool samep(int x,int y){
	++TG;for(;;){
		if(x==y)return 1;
		if(vis[x]==TG)return 0;
		vis[x]=TG,x=p[x];
	}
}
bool sameP(int x,int y){
	++TG;for(;;){
		if(x==y)return 1;
		if(vis[x]==TG)return 0;
		vis[x]=TG,x=P[x];
	}
}
bool same(int x,int y){
	if(~w[x]&&~w[y])return sameP(w[x],w[y]);
	if(!~w[x]&&!~w[y])return samep(x,y);
	return 0;
}
void split(int x,int y){
	++N,hd[N]=y,del[N]=0;
	for(;w[y]==w[x];y=p[y])w[y]=N;
	P[N]=P[w[x]],P[w[x]]=N,c[N]=c[w[x]];
	calc(w[x]),calc(N);
}
void upd_split(int x,int y){
	if(~w[x]&&~w[y]){
		if(w[p[x]]==w[x])split(x,p[x]);
		if(w[p[y]]==w[y])split(y,p[y]);
		P[w[y]]=w[p[x]],P[w[x]]=w[p[y]];
		if(P[w[x]]==w[x])clr(w[x]);
		if(P[w[y]]==w[y])clr(w[y]);
	}
}
void upd_merge(int x,int y){
	int ra,rb,sa,sb;
	if(!~w[x]){
		SZ=0,dfs_p(p[x]),++N,hd[N]=p[x];
		c[N]=del[N]=0;
		for(int i=0;i<SZ;i++)w[sta[i]]=N;
		calc(N),ra=N,rb=N;
	}else{
		if(w[x]==w[p[x]])split(x,p[x]),ra=w[x],rb=N;
		else ra=w[x],rb=w[p[x]];
	}
	if(!~w[y]){
		SZ=0,dfs_p(p[y]),++N,hd[N]=p[y];
		c[N]=del[N]=0;
		for(int i=0;i<SZ;i++)w[sta[i]]=N;
		calc(N),sa=N,sb=N;
	}else{
		if(w[y]==w[p[y]])split(y,p[y]),sa=w[y],sb=N;
		else sa=w[y],sb=w[p[y]];
	}
	P[ra]=sb,P[sa]=rb;
}
void upd1(){
	int x,y;scanf("%d%d",&x,&y);
	x--,y--;if(x==y)return;
	if(same(x,y))upd_split(x,y);else upd_merge(x,y);
	swap(p[x],p[y]);++T;if(T>B)built(),T=0;
}
int main(){
	scanf("%d",&n),S=(n-1)>>9;
	for(int i=0;i<n;++i)scanf("%lld",&a[i]),b[i>>9]+=a[i];;
	for(int i=0;i<n;++i)scanf("%d",&p[i]),p[i]--;
	memset(w,-1,sizeof(w)),built();
	scanf("%d",&q);while(q--){
		int op;scanf("%d",&op);
		switch(op){
			case 1:ask();break;
			case 2:upd0();break;
			case 3:upd1();
		}
	}
}