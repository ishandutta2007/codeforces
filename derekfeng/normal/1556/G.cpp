#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
int f[5000000];
int F(int x){
	return f[x]==x?x:f[x]=F(f[x]);
}
ll N;
int n,m;
bool ans[50004];
int op[50004],tot=1;
ll l[50004],r[50004];
int s[2][5000000],rec[5000000];
vector<pii>g[50004];
bool leaf(int x){
	return !s[0][x]&&!s[1][x];
}
void ins(ll l,ll r,int id,ll a,ll b,int t){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		rec[id]=t;
		return;
	}
	ll mid=(l+r)>>1;
	if(!s[0][id])s[0][id]=++tot,rec[s[0][id]]=m+1;
	ins(l,mid,s[0][id],a,b,t);
	if(!s[1][id])s[1][id]=++tot,rec[s[1][id]]=m+1;
	ins(mid+1,r,s[1][id],a,b,t);
}
void merge(int x,int y){
	if(leaf(x)&&leaf(y)){
		int p=min(rec[x],rec[y]);
		if(p==m+1)f[F(x)]=F(y);
		else g[p].push_back(mkp(x,y));
	}else if(leaf(x))merge(x,s[0][y]),merge(x,s[1][y]);
	else if(leaf(y))merge(s[0][x],y),merge(s[1][x],y);
	else merge(s[0][x],s[0][y]),merge(s[1][x],s[1][y]);
}
int findf(ll l,ll r,int id,ll p){
	if(leaf(id))return id;
	ll mid=(l+r)>>1;
	if(p<=mid)return findf(l,mid,s[0][id],p);
	return findf(mid+1,r,s[1][id],p);
}
int main(){
	scanf("%d%d",&n,&m),N=(1ll<<n);
	for(int i=1;i<=m;i++){
		char buf[10];
		scanf("%s%I64d%I64d",buf,&l[i],&r[i]);
		if(*buf=='a')op[i]=1;
		else ins(0,N-1,1,l[i],r[i],i);
	}
	for(int i=1;i<=tot;i++)f[i]=i;
	for(int i=1;i<=tot;i++)if(!leaf(i))merge(s[0][i],s[1][i]);
	for(int i=m;i;i--){
		for(auto x:g[i])f[F(x.fi)]=F(x.se);
		if(op[i]==1)ans[i]=F(findf(0,N-1,1,l[i]))==F(findf(0,N-1,1,r[i]));
	}
	for(int i=1;i<=m;i++)if(op[i]==1)putchar('0'+ans[i]),puts("");
}