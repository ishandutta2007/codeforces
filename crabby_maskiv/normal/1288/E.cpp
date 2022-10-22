#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,m;
struct fhq{
	int ls,rs,fa,sz;
	int rnd,x;
}f[N];
int rt,P;
inline int build(int x){
	int p=++P;
	f[p].ls=f[p].rs=0;
	f[p].sz=1;
	f[p].x=x;
	f[p].rnd=rand();
	return p;
}
inline void upd(int p){
	f[f[p].ls].fa=f[f[p].rs].fa=p;
	f[p].sz=f[f[p].ls].sz+f[f[p].rs].sz+1;
}
int lft[N],rgt[N];
int findrk(int p){
	if(!f[p].fa)
		return f[f[p].ls].sz+1;
	if(f[f[p].fa].ls==p)
		return findrk(f[p].fa)-f[f[p].rs].sz-1;
	else return findrk(f[p].fa)+f[f[p].ls].sz+1;
}
void split(int p,int k,int &x,int &y){
	if(!p){
		x=y=0;
		return;
	}
	int sz=f[f[p].ls].sz+1;
	if(k>=sz){
		x=p;
		split(f[p].rs,k-sz,f[x].rs,y);
	}
	else{
		y=p;
		split(f[p].ls,k,x,f[y].ls);
	}
	upd(p);
}
int merge(int x,int y){
	if(!x||!y) return x|y;
	if(f[x].rnd<f[y].rnd){
		f[x].rs=merge(f[x].rs,y);
		upd(x);
		return x;
	}
	else{
		f[y].ls=merge(x,f[y].ls);
		upd(y);
		return y;
	}
}
int tot;
void dfs(int p){
	if(!p) return;
//	cerr<<"(";
	dfs(f[p].ls);
//	cerr<<f[p].x;
	rgt[f[p].x]=max(rgt[f[p].x],++tot);
	dfs(f[p].rs);
//	cerr<<")";
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) lft[i]=rgt[i]=i;
	for(i=1;i<=n;i++){
		int p=build(i);
		rt=merge(rt,p);
		f[rt].fa=0;
	}
	for(i=1;i<=m;i++){
		int x;cin>>x;
	//	tot=0;dfs(rt);cerr<<endl;
		int rk=findrk(x);
		int p1=0,p2=0,p3=0;
		split(rt,rk-1,p1,p2);
		split(p2,1,p2,p3);
		lft[f[p2].x]=1;
		rgt[f[p2].x]=max(rgt[f[p2].x],rk);
		rt=merge(merge(p2,p1),p3);
		f[rt].fa=0;
	}
	tot=0;dfs(rt);//cerr<<endl;
	for(i=1;i<=n;i++) cout<<lft[i]<<" "<<rgt[i]<<endl;
	return 0;
}