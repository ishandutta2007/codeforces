#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
const int inf=1e9+5;
int n,m,i,j;
int a[2005],b[2005],c[2005],l,r,mid;
int dep[2005],fa[2005],inbase[2005];
vector<int> base;
vector<int> g[2005];
int rx,ry,rz;
int add(int x,int y){
	return min(inf,x+y);
}
bool dfs(int x,int pre,int cur){
	fa[x]=pre;
	if(!inbase[x]) cur=add(cur,c[x]);
	int i;
	rep(i,g[x].size()){
		int y=g[x][i-1];
		if(y==pre||(inbase[x]&&inbase[y])||a[y]>=cur)continue;
		if(fa[y]){
			rx=fa[y];ry=x;rz=y;
			return 1;
		}
		dep[y]=dep[x]+1;
		if(dfs(y,x,cur)) return 1;
	}
	return 0;
}
bool find_road(int cur){
	rx=ry=rz=-1;
	int i;
	rep(i,n) fa[i]=0;
	rep(i,base.size()){
		fa[base[i-1]]=n+1;
	}
	rep(i,base.size()){
		if(dfs(base[i-1],n+1,cur)){
			return 1;
		}
	}
	if(base.empty()){
		return dfs(1,n+1,cur);
	}
	return 0;
}
void push_base(int x){
	if(x==n+1||inbase[x])return;
	inbase[x]=1;
	base.push_back(x);
}
bool check(int cur){
	int i;
	rep(i,n) c[i]=b[i];
	c[n+1]=0;
	rep(i,n) inbase[i]=0;
	base.clear();
	bool fir=1;
	while(base.size()<n){
		if(!find_road(cur)){
			return 0;
		}
		push_base(rz);cur=add(cur,c[rz]);c[rz]=0;
		while(rx!=ry){
			if(dep[rx]<dep[ry])swap(rx,ry);
			push_base(rx);cur=add(cur,c[rx]);c[rx]=0;
			rx=fa[rx];
		}
		push_base(rx);cur=add(cur,c[rx]);c[rx]=0;
		if(!fir){
			while(rx!=n+1&&fa[rx]!=n+1&&fa[rx]&&!inbase[fa[rx]]){
				rx=fa[rx];
				push_base(rx);cur=add(cur,c[rx]);c[rx]=0;
			}
		}
		else{
			while(rx!=n+1&&fa[rx]!=n+1&&fa[rx]&&!inbase[fa[rx]]){
				rx=fa[rx];
				cur=add(cur,c[rx]);c[rx]=0;
			}
		}
		fir=0;
	}
	return 1;
}
void solve(){
	scanf("%d%d",&n,&m);dep[n+1]=-1;
	rep(i,n-1)scanf("%d",&a[i+1]);
	rep(i,n-1)scanf("%d",&b[i+1]);
	rep(i,n)g[i].clear();
	rep(i,m){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	l=0;r=inf;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)){
			r=mid-1;
		}
		else l=mid;
	}
	printf("%d\n",r+1);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}