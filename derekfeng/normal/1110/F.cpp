#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define mkp make_pair
#define fi first
#define se second 
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0'); 
}
int n,q,cnt,n_=1,ld[500003],rd[500003];
vector<pii>g[500003];
vector<piii>t[500003];
ll dat[1050000],num[1050000],ans[500004];
void upd(int l,int r,int id,int a,int b,int add_){
	if (b<l || r<a) return;
	if (a<=l && r<=b){
		num[id]+=add_,dat[id]+=add_;
		return;
	}
	upd(l,(l+r)/2,id*2+1,a,b,add_),upd((l+r)/2+1,r,id*2+2,a,b,add_),dat[id]=min(dat[id*2+1],dat[id*2+2])+num[id];
}
ll query(int l,int r,int id,int a,int b){
	if (b<l || r<a) return 1e17;
	if (a<=l && r<=b) return dat[id];
	return min(query(l,(l+r)/2,id*2+1,a,b),query((l+r)/2+1,r,id*2+2,a,b))+num[id];
}
void init(int l,int r,int id){
	if (l==r) return;
	init(l,(l+r)/2,id*2+1),init((l+r)/2+1,r,id*2+2);
	dat[id]=min(dat[id*2+1],dat[id*2+2]);
}
void dfs(int x,ll d){
	ld[x]=cnt++;
	for (int i=0;i<g[x].size();i++) dfs(g[x][i].fi,d+g[x][i].se);
	rd[x]=cnt-1;
	if (g[x].size()==0) dat[ld[x]+n_-1]=d;
	else dat[ld[x]+n_-1]=1e17;
}
void dfs1(int x){
	for (int i=0;i<t[x].size();i++) ans[t[x][i].se]=query(0,n_-1,0,t[x][i].fi.fi,t[x][i].fi.se);
	for (int i=0;i<g[x].size();i++){
		upd(0,n_-1,0,ld[g[x][i].fi],rd[g[x][i].fi],-2*g[x][i].se);
		upd(0,n_-1,0,0,n_-1,g[x][i].se);
		dfs1(g[x][i].fi);
		upd(0,n_-1,0,ld[g[x][i].fi],rd[g[x][i].fi],2*g[x][i].se);
		upd(0,n_-1,0,0,n_-1,-g[x][i].se);
	}
}
int main(){
	read(n),read(q);while (n_<n) n_<<=1;
	for (int i=2;i<=n;i++){
		int x,w;read(x),read(w);
		g[x].push_back(mkp(i,w));
	}
	for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	dfs(1,0);
	init(0,n_-1,0);
	for (int i=1;i<=q;i++){
		int x,l,r;read(x),read(l),read(r);
		t[x].push_back(mkp(mkp(l-1,r-1),i)); 
	}
	dfs1(1);
	for (int i=1;i<=q;i++) write(ans[i]),puts("");
}