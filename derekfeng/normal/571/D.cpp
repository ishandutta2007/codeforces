#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,T[500004];
bool qr[500004];ll ans[500004];
int t1[1000004][2],t2[1000004][2];
vector<int>ask[1000004];
struct Union{
	int fa[1000004],N,sz[1000004];
	int tr[1000004][2];
	vector<int>vec[1000004];
	void init(){N=n;for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;}
	int Fa(int x){return x==fa[x]?x:fa[x]=Fa(fa[x]);}
	void merge(int x,int y){
		x=Fa(x),y=Fa(y),++N,tr[N][0]=x,tr[N][1]=y;
		sz[N]=sz[x]+sz[y],fa[x]=fa[y]=fa[N]=N;
	}
}F[2];
int sta[1000004],SZ;ll sm[1000004];
void dfs0(int x){
	reverse(F[0].vec[x].begin(),F[0].vec[x].end());
	for(auto t:F[0].vec[x])sta[++SZ]=-t,sm[SZ]=sm[SZ-1]+F[0].sz[x];
	if(x<=n){
		for(auto t:ask[x]){
			int L=lower_bound(sta+1,sta+SZ+1,-t)-sta;
			int R=lower_bound(sta+1,sta+SZ+1,-T[t])-sta-1;
			if(L<=R)ans[t]=sm[R]-sm[L-1];
		}
	}else dfs0(F[0].tr[x][0]),dfs0(F[0].tr[x][1]);
	SZ-=F[0].vec[x].size();
}
void dfs1(int x){
	reverse(F[1].vec[x].begin(),F[1].vec[x].end());
	for(auto t:F[1].vec[x])sta[++SZ]=-t;
	if(x<=n){
		for(auto t:ask[x]){
			int pos=lower_bound(sta+1,sta+SZ+1,-t)-sta;
			if(pos<=SZ)T[t]=-sta[pos];
		}
	}else dfs1(F[1].tr[x][0]),dfs1(F[1].tr[x][1]);
	SZ-=F[1].vec[x].size();
}
int main(){
	scanf("%d%d",&n,&q);
	F[0].init(),F[1].init();
	for(int i=1;i<=q;i++){
		char buf[3];int op,x,y;
		scanf("%s%d",buf,&x);
		if(*buf=='U')op=1;
		if(*buf=='M')op=2;
		if(*buf=='A')op=3;
		if(*buf=='Z')op=4;
		if(*buf=='Q')op=5;
		if(op<3){
			scanf("%d",&y);
			F[op-1].merge(x,y);
			continue;
		}
		if(op<5){
			F[op-3].vec[F[op-3].Fa(x)].push_back(i);
			continue;
		}
		ask[x].push_back(i),qr[i]=1;
	}
	for(int i=1;i<=F[1].N;i++)if(F[1].Fa(i)==i)dfs1(i);
	for(int i=1;i<=F[0].N;i++)if(F[0].Fa(i)==i)dfs0(i);
	for(int i=1;i<=q;i++)if(qr[i])printf("%lld\n",ans[i]);
}