#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define mkp make_pair
#define fi first
#define se second
int n,q,cnt;
int f[200004],h[200004];
vector<pii>g[200004]; 
int L[200004],R[200004];
int built(int l,int r){
	int id=++cnt;
	if(l!=r)L[id]=built(l,(l+r)/2),R[id]=built((l+r)/2+1,r);
	return id;
}
void add(int l,int r,int id,int a,int b,pii x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		g[id].push_back(x);
		return;
	}
	add(l,(l+r)/2,L[id],a,b,x),add((l+r)/2+1,r,R[id],a,b,x);
}
stack<piii>st;
int F(int x){
	return f[x]==x?x:F(f[x]); 
}
void merge(int x,int y){
	if(h[x]>h[y])swap(x,y);
	st.push(mkp(x,mkp(y,h[y])));
	h[y]=max(h[y],h[x]+1);
	f[x]=y;
}
void dfs(int l,int r,int id){
	bool ok=0;
	for(int i=0;i<g[id].size();i++){
		int u=g[id][i].fi,v=g[id][i].se,U=u+n,V=v+n;
		u=F(u),v=F(v);
		if(u==v&&!ok)ok=1;
		U=F(U),V=F(V);
		merge(u,V),merge(U,v);
	}
	if(!ok){
		if(l==r)puts("YES");
		else dfs(l,(l+r)/2,L[id]),dfs((l+r)/2+1,r,R[id]);
	}else{
		for(int i=l;i<=r;i++)puts("NO");
	}
	for(int i=0;i<g[id].size();i++){
		piii x=st.top();st.pop();
		f[x.fi]=x.fi,h[x.se.fi]=x.se.se;
		x=st.top();st.pop();
		f[x.fi]=x.fi,h[x.se.fi]=x.se.se;
	}
}
int u[100004],v[100004];
map<pii,int>mp;
int main(){
	scanf("%d%d",&n,&q);
	built(1,q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&u[i],&v[i]);
		if(mp[mkp(u[i],v[i])]){
			int t=mp[mkp(u[i],v[i])];
			add(1,q,1,t,i-1,mkp(u[i],v[i]));
			mp[mkp(u[i],v[i])]=0;
		}else mp[mkp(u[i],v[i])]=i;
	}
	for(auto it=mp.begin();it!=mp.end();it++)if((it->se)>0)add(1,q,1,(it->se),q,(it->fi));
	for(int i=1;i<=2*n;i++)f[i]=i;
	dfs(1,q,1);
}