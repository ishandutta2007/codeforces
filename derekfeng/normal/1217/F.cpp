#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,q,lst;
int op[200004],u[200004],v[200004];
vector<int>dat[525000];
map<pii,int>exi;
bool del[200004];
struct Unino{
	int fa[200004],rk[200004];
	stack<pair<pii,pii> >sta;
	int F(int x){
		return x==fa[x]?x:F(fa[x]);
	}
	void init(){
		for(int i=1;i<=n;i++)fa[i]=i,rk[i]=0;
		while(!sta.empty())sta.pop();
	}
	void merge(int u,int v,int tg){
		u=F(u),v=F(v);
		if(u==v)return;
		if(rk[u]>rk[v])swap(u,v);
		sta.push({{tg,rk[v]},{u,v}});
		fa[u]=v,rk[v]=max(rk[v],rk[u]+1);
	}
	void pop(int tg){
		while(!sta.empty()){
			pair<pii,pii>t=sta.top();
			if(t.fi.fi!=tg)break;
			int u=t.se.fi,v=t.se.se;
			fa[u]=u,rk[v]=t.fi.se,sta.pop();
		}
	}
	bool qry(int u,int v){
		return F(u)==F(v);
	}
}uni;
void upd(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){dat[i].push_back(x);return;}
	int md=(l+r)>>1;
	upd(i<<1,l,md,a,b,x),upd(i<<1|1,md+1,r,a,b,x);
}
map<pii,bool>mp;
int tot;
void solve(int i,int l,int r,vector<int>vec){
	if(l==r){
		u[l]=(u[l]+lst-1)%n+1;
		v[l]=(v[l]+lst-1)%n+1;
		if(u[l]>v[l])swap(u[l],v[l]);
		if(op[l]==1){
			if(exi[{u[l],v[l]}]){
				int t=exi[{u[l],v[l]}];
				del[t]=1,exi[{u[l],v[l]}]=0;
			}else{
				exi[{u[l],v[l]}]=l;
				if(r<q)upd(1,1,q,r+1,q,l);
			}
			return;
		}
		int z=++tot;
		for(auto x:vec)if(!del[x])uni.merge(u[x],v[x],z);
		for(auto x:dat[i])if(!del[x])uni.merge(u[x],v[x],z);
		lst=uni.qry(u[l],v[l]);
		uni.pop(z);
		putchar('0'+lst);
		return;
	}
	mp.clear();
	for(int j=l;j<=r;j++){
		int U=u[j],V=v[j];
		if(U>V)swap(U,V);
		mp[{U,V}]=1;
		U=U%n+1,V=V%n+1;
		if(U>V)swap(U,V);
		mp[{U,V}]=1;
	}
	int z=++tot;
	vector<int>nvec;
	for(auto x:vec){
		if(del[x])continue;
		if(!mp[{u[x],v[x]}])uni.merge(u[x],v[x],z);
		else nvec.push_back(x);
	}
	for(auto x:dat[i]){
		if(del[x])continue;
		if(!mp[{u[x],v[x]}])uni.merge(u[x],v[x],z);
		else nvec.push_back(x);
	}
	int md=(l+r)>>1;
	solve(i<<1,l,md,nvec),solve(i<<1|1,md+1,r,nvec);
	uni.pop(z);
}
int main(){
	scanf("%d%d",&n,&q),uni.init();
	for(int i=1;i<=q;i++)scanf("%d%d%d",&op[i],&u[i],&v[i]);
	solve(1,1,q,{});
}