#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int blk;
int n,q,i,j,f[300005],g[300005],ans[300005];
int a[300005],fa[300005][19],dep[300005];
int bg[300005],ed[300005],seq[600005],ti;
struct query{
	int l,r,z,l2,r2,id;
}b[300005];
vector<int> e[300005];
void dfs(int x,int fa){
	seq[bg[x]=++ti]=a[x];
	dzd(e[x],it)if(*it!=fa){
		dep[*it]=dep[x]+1;dfs(*it,::fa[*it][0]=x);
	}
	seq[ed[x]=++ti]=a[x];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y],i;
	for(i=18;i>=0;i--)if((t>>i)&1){
		x=fa[x][i];
	}
	if(x==y) return x;
	for(i=18;i>=0;i--)if(fa[x][i]!=fa[y][i]){
		x=fa[x][i];y=fa[y][i];
	}
	return fa[x][0];
}
bool cmp(query x,query y){
	if(x.l/blk==y.l/blk){
		return ((x.l/blk)&1)^(x.r<y.r);
	}
	return x.l<y.l;
}
void upd(int x){
	if(!f[x]){
		f[x]++;
		g[x/blk]++;
	}
	else{
		f[x]--;g[x/blk]--;
	}
}
int query(int l,int r){
	while(l<=r&&l/blk==(l-1)/blk){
		if(f[l]) return l;
		l++;
	}
	while(l<=r&&r/blk==(r+1)/blk){
		if(f[r]) return r;
		r--;
	}
	while(l<=r){
		if(g[l/blk]){
			break;
		}
		l+=blk;
	}
	while(l<=r){
		if(f[l]) return l;
		l++;
	}
	return -1;
}
int main(){
	scanf("%d%d",&n,&q);
	blk=sqrt(n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	rep(j,18)rep(i,n)fa[i][j]=fa[fa[i][j-1]][j-1];
	rep(i,q){
		int x,y,l,r;ans[i]=-1;b[i].id=i;
		scanf("%d%d%d%d",&x,&y,&b[i].l2,&b[i].r2);
		if(bg[x]>bg[y]) swap(x,y);
		int z=lca(x,y);
		if(z==x){
			b[i].l=bg[x];b[i].r=bg[y];
		}
		else{
			b[i].l=ed[x];b[i].r=bg[y];b[i].z=z;
		}
	}
	sort(b+1,b+q+1,cmp);
	int l=1,r=0;
	rep(i,q){
		while(r<b[i].r) upd(seq[++r]);
		while(l>b[i].l) upd(seq[--l]);
		while(r>b[i].r) upd(seq[r--]);
		while(l<b[i].l) upd(seq[l++]);
		if(b[i].z) upd(a[b[i].z]);
		ans[b[i].id]=query(b[i].l2,b[i].r2);
		if(b[i].z) upd(a[b[i].z]);
	}
	rep(i,q){
		printf("%d\n",ans[i]);
	}
	return 0;
}