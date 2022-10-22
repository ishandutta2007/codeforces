#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+5;
int n,m;
int eu[N];
vector<int> g[N];
int tot;
int fa[N][20],pre[N],pst[N],h[N];
void dfs(int u){
	pre[u]=++tot;eu[tot]=u;
	h[u]=h[fa[u][0]]+1;
	for(int i=1;i<20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:g[u])if(v!=fa[u][0]){
		fa[v][0]=u;
		dfs(v);
	}
	pst[u]=++tot;eu[tot]=u;
}
inline int lca(int x,int y){
	if(h[x]<h[y]) swap(x,y);
	for(int i=19;i>=0;i--){
		if(h[fa[x][i]]>=h[y])
			x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int a[N],ans[N];
int c[N],cc[N],cnt[N],cb[N];
int lft[N],rgt[N],pos[N],B;
struct ques{
	int l,r,x,y,t,id;
	inline bool operator <(const ques &b)const{
		if(l/B==b.l/B)
			return ((l/B&1)?(r>b.r):(r<b.r));
		return l<b.l;
	}
}q[N];
int f=0;
inline void chg(int u,int x){
	c[u]+=x;
	f++;
	if(c[u]&1){
		cc[a[u]]++;
		if(cc[a[u]]&1){
			cnt[a[u]]=1;
			cb[pos[a[u]]]++;
		}
		else{
			cnt[a[u]]=0;
			cb[pos[a[u]]]--;
		}
	}
	else{
		cc[a[u]]--;
		if(cc[a[u]]&1){
			cnt[a[u]]=1;
			cb[pos[a[u]]]++;
		}
		else{
			cnt[a[u]]=0;
			cb[pos[a[u]]]--;
		}
	}
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	for(i=1;i<=m;i++){
		scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].x,&q[i].y);
		q[i].id=i;
		q[i].t=lca(q[i].l,q[i].r);
		if(q[i].t==q[i].l||q[i].t==q[i].r) q[i].t=0;
		if(pre[q[i].l]>pre[q[i].r]) swap(q[i].l,q[i].r);
		if(q[i].t){
			q[i].l=pst[q[i].l];
			q[i].r=pre[q[i].r];
		}
		else{
			q[i].l=pre[q[i].l];
			q[i].r=pre[q[i].r];
		}
	}
	B=max(tot/sqrt(m),1.0);
	sort(q+1,q+m+1);
	for(i=0;i*B<=n;i++){
		lft[i]=max(i*B,1);
		rgt[i]=min(i*B+B-1,n);
		for(j=lft[i];j<=rgt[i];j++) pos[j]=i;
	}
	int l=1,r=0;
	for(i=1;i<=m;i++){
		while(r<q[i].r) chg(eu[++r],1);
		while(l>q[i].l) chg(eu[--l],1);
		while(r>q[i].r) chg(eu[r--],-1);
		while(l<q[i].l) chg(eu[l++],-1);
		if(q[i].t) chg(q[i].t,1);
		int answ=-1;
		if(pos[q[i].x]==pos[q[i].y]){
			for(j=q[i].x;j<=q[i].y;j++)
				if(cnt[j]){answ=j;break;}
		}
		else{
			for(j=q[i].x;j<=rgt[pos[q[i].x]];j++)
				if(cnt[j]){answ=j;break;}
			if(answ==-1){
				for(j=q[i].y;j>=lft[pos[q[i].y]];j--)
					if(cnt[j]){answ=j;break;}
				if(answ==-1){
					for(j=pos[q[i].x]+1;j<pos[q[i].y];j++){
						if(cb[j]){
							for(k=lft[j];k<=rgt[j];k++)
								if(cnt[k]){answ=k;break;}
							break;
						}
					}						
				}
			}
		}
		ans[q[i].id]=answ;
		if(q[i].t) chg(q[i].t,-1);
	}
	cerr<<f;
	for(i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}