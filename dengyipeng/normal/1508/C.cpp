#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 200005
#define maxm 10000005
#define ll long long
using namespace std;

int n,m,i,j,k,a[maxn][3],fa[maxn],P[maxn],bz[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn];
map<int,int> E[maxn];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}
int cmp(int i,int j){return a[i][2]<a[j][2];}

int du[maxn];
void insert(int x,int y){
	E[x][y]=E[y][x]=1,du[x]++,du[y]++;
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int tot,t[maxm],tl[maxm],tr[maxm],rt[maxn];
void add(int &x,int l,int r,int p){
	if (!x) x=++tot; t[x]++;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (p<=mid) add(tl[x],l,mid,p);
	else add(tr[x],mid+1,r,p);
}
void merge(int x,int y,int l,int r){
	t[x]+=t[y];
	if (l==r) return;
	int mid=(l+r)>>1;
	if (tl[x]&&tl[y]) merge(tl[x],tl[y],l,mid);
	else if (!tl[x]) tl[x]=tl[y];
	if (tr[x]&&tr[y]) merge(tr[x],tr[y],mid+1,r);
	else if (!tr[x]) tr[x]=tr[y];
}

int find(int x,int l,int r,int L,int R){
	if (t[x]==r-l+1||l>R||r<L) return 0;
	if (l==r) return l;
	int mid=(l+r)>>1;
	int k=find(tl[x],l,mid,L,R);
	if (k) return k; else return find(tr[x],mid+1,r,L,R);
}

void link(int x,int y){
	x=father(x),y=father(y);
	fa[y]=x,merge(rt[x],rt[y],1,n);
}

int main(){
	scanf("%d%d",&n,&m); int s=0;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		insert(a[i][0],a[i][1]),s^=a[i][2];
	}
	for(i=1;i<=m;i++) bz[i]=0,P[i]=i;
	for(i=1;i<=n;i++) fa[i]=i;
	sort(P+1,P+1+m,cmp);
	for(i=1;i<=m;i++){
		int x=a[P[i]][0],y=a[P[i]][1];
		if (father(x)!=father(y)) 
			bz[P[i]]=1,fa[fa[x]]=fa[y];
	} 
	for(i=1;i<=n;i++) fa[i]=i,add(rt[i],1,n,i);
	for(i=1;i<=n;i++) {
		int k=find(rt[father(i)],1,n,1,n);
		while (k){
			if (E[i].find(k)==E[i].end())
				link(i,k),du[i]++,du[k]++;
			k=find(rt[father(i)],1,n,k+1,n);
		}
	}
	int tp=0;
	for(i=1;i<=n;i++) if (du[i]<n-1) tp=1;
	ll sum=0;
	for(i=1;i<=m;i++) P[i]=i;
	sort(P+1,P+1+m,cmp);
	for(i=1;i<=m;i++){
		k=P[i]; int x=a[k][0],y=a[k][1];
		if (father(x)!=father(y))
			fa[father(x)]=father(y),sum+=a[k][2];
		else if (bz[k]) s=min(s,a[k][2]);
	}
	if (!tp) sum+=s;
	printf("%lld\n",sum);
}