#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int n,m,s;
int cnt,cnt1,L[200004],R[200004],minx[200004],maxx[200004];
vector<pii>g[300004];
ll d[300004];
bool vis[300004];
void addedge(int u,int v,int x){g[u].push_back(mkp(v,x));}
int built(int l,int r){
	int id=++cnt;
	if(l==r){
		minx[id]=maxx[id]=l;
		return id;
	}
	L[id]=built(l,(l+r)/2),R[id]=built((l+r)/2+1,r);
	minx[id]=++cnt1,addedge(minx[L[id]],cnt1,0),addedge(minx[R[id]],cnt1,0);
	maxx[id]=++cnt1,addedge(cnt1,maxx[L[id]],0),addedge(cnt1,maxx[R[id]],0);
	return id;
}
void addrange(int l,int r,int id,int a,int b,int v,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		addedge(minx[id],v,x);
		return;
	}
	addrange(l,(l+r)/2,L[id],a,b,v,x),addrange((l+r)/2+1,r,R[id],a,b,v,x);
}
void addnode(int l,int r,int id,int a,int b,int v,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		addedge(v,maxx[id],x);
		return;
	}
	addnode(l,(l+r)/2,L[id],a,b,v,x),addnode((l+r)/2+1,r,R[id],a,b,v,x);
}
priority_queue<pli,vector<pli>,greater<pli> >pq;
int main(){
	scanf("%d%d%d",&n,&m,&s);
	cnt1=n;
	built(1,n);
	for(int i=1;i<=3*n;i++)d[i]=1e18;
	for(int i=1;i<=m;i++){
		int opt,l,r,v,w;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d%d",&l,&r,&w);
			addedge(l,r,w);
		}else{
			scanf("%d%d%d%d",&v,&l,&r,&w);
			if(opt==2)addnode(1,n,1,l,r,v,w);
			if(opt==3)addrange(1,n,1,l,r,v,w);
		}
	}
	d[s]=0,pq.push(mkp(0,s));
	while(!pq.empty()){
		pli u=pq.top();pq.pop();
		ll w=u.fi;int fr=u.se;
		if(vis[fr])continue;vis[fr]=1;
		for(int i=0;i<g[fr].size();i++){
			int to=g[fr][i].fi;
			if(w+g[fr][i].se>=d[to])continue;
			d[to]=w+g[fr][i].se,pq.push(mkp(d[to],to)); 
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1e18)printf("-1 ");
		else printf("%I64d ",d[i]);
	}
}