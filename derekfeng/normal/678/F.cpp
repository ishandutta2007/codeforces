#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=(1ll<<62);
const int INF=(1<<30);
int q;
ll ans[300005];
vector<int>v[1100000];
int op[300005],a[300005],b[300005],c[300005];
void add(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){v[i].push_back(x);return;}
	int md=(l+r)>>1;
	add(i<<1,l,md,a,b,x),add(i<<1|1,md+1,r,a,b,x);
}
ll F(ll k,ll b,ll x){
	return k*x+b;
}
int rt,tot,dat[10000005],sn[2][10000005];
int upd(int id,int l,int r,int x){
	if(!x)return id;
	int i=++tot;
	dat[i]=dat[id];
	sn[0][i]=sn[0][id],sn[1][i]=sn[1][id];
	int md=(l+r)>>1,y=dat[i];
	ll resx=F(a[x],b[x],md);
	ll resy=y?F(a[y],b[y],md):-inf;
	if(resx>resy)dat[i]=x;
	if(l==r)return i;
	if(a[x]<a[y]){
		if(resx>resy)sn[1][i]=upd(sn[1][i],md+1,r,y);
		else sn[0][i]=upd(sn[0][i],l,md,x);
	}else{
		if(resx>resy)sn[0][i]=upd(sn[0][i],l,md,y);
		else sn[1][i]=upd(sn[1][i],md+1,r,x);
	}
	return i;
}
ll qry(int i,int l,int r,int p){
	if(!i)return -inf;
	ll ret=F(a[dat[i]],b[dat[i]],p);
	if(l!=r){
		int md=(l+r)>>1;
		if(p<=md)ret=max(ret,qry(sn[0][i],l,md,p));
		else ret=max(ret,qry(sn[1][i],md+1,r,p));
	}
	return ret;
}
void solve(int i,int l,int r){
	int TOT=tot,RT=rt;
	for(auto x:v[i])rt=upd(rt,-1e9,1e9,x);
	if(l==r){
		if(op[l]==3)ans[l]=qry(rt,-1e9,1e9,a[l]);
	}else{
		int md=(l+r)>>1;
		solve(i<<1,l,md),solve(i<<1|1,md+1,r);
	}
	tot=TOT,rt=RT;
}
int main(){
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&op[i],&a[i]);
		if(op[i]==1)scanf("%d",&b[i]);
		if(op[i]==2)c[a[i]]=i;
	}
	for(int i=1;i<=q;i++)if(op[i]==1){
		if(!c[i])c[i]=q;
		add(1,1,q,i,c[i],i);
	}
	solve(1,1,q);
	for(int i=1;i<=q;i++)if(op[i]==3){
		if(ans[i]>-inf)printf("%lld\n",ans[i]);
		else puts("EMPTY SET");
	}
}