#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define S 800005
set<int>P[S];
struct qs{int t,op,D,R,v;}Q[S];
bool cmp(qs x,qs y){return x.R<y.R;}
ll T[S],ans[S],o[S];int n,m,c,pre[S],suc[S],q,a[S];
void add(int p,int x){for(;p<=n;p+=p&-p)T[p]+=x;}
ll ask(int p,ll a=0){for(;p;p^=p&-p)a+=T[p];return a;}
void CDQ(int l,int r){
	if(l==r)return;
	int md=l+r>>1,p=l; CDQ(l,md); CDQ(md+1,r);
	for(int i=md+1;i<=r;++i)if(Q[i].op){
		while(p<=md&&Q[i].R>=Q[p].R){if(!Q[p].op)add(Q[p].D,Q[p].v);p++;}
		ans[Q[i].v]+=ask(n)-ask(Q[i].D-1);
	}
	for(int i=l;i<p;++i)if(!Q[i].op)add(Q[i].D,-Q[i].v);
	sort(Q+l,Q+r+1,cmp);
}
int Pre(int x,int c){return *(--P[c].lower_bound(x));}
int Suc(int x,int c){return *P[c].upper_bound(x);}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)P[i].insert(0),P[i].insert(n+1),scanf("%d",&a[i]),P[a[i]].insert(i);
	for(int i=1;i<=n;++i){pre[i]=Pre(i,a[i]),suc[i]=Suc(i,a[i]);if(pre[i])Q[++c]=(qs){0,0,pre[i],i,i-pre[i]};}
	for(int i=1;i<=m;++i){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op&1){
			if(pre[x])Q[++c]=(qs){i,0,pre[x],x,pre[x]-x};
			if(suc[x]<=n){Q[++c]=(qs){i,0,x,suc[x],x-suc[x]};if(pre[x])Q[++c]=(qs){i,0,pre[x],suc[x],suc[x]-pre[x]};}
			P[a[x]].erase(x); suc[pre[x]]=suc[x]; pre[suc[x]]=pre[x];
			a[x]=y; P[y].insert(x); pre[x]=Pre(x,y); suc[x]=Suc(x,y);
			if(pre[x])Q[++c]=(qs){i,0,pre[x],x,x-pre[x]};
			if(suc[x]<=n){if(pre[suc[x]])Q[++c]=(qs){i,0,pre[suc[x]],suc[x],pre[suc[x]]-suc[x]};Q[++c]=(qs){i,0,x,suc[x],suc[x]-x};}
			suc[pre[x]]=pre[suc[x]]=x;
		}else Q[++c]=(qs){0,1,x,y,++q};
	}CDQ(1,c);for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
}