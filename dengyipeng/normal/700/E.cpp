#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 400005
#define maxm 10000005
using namespace std;

int n,i,j,k;
struct node{
	int to[26],len,end,fa;
} T[maxn];
int tot,las,Rt;
void add(int c,int end){
	int np=++tot,p=las; las=np;
	T[np].len=T[p].len+1,T[np].end=end;
	for(;p&&!T[p].to[c];p=T[p].fa) T[p].to[c]=np;
	if (!p) T[np].fa=Rt; else {
		int q=T[p].to[c];
		if (T[q].len==T[p].len+1) T[np].fa=q; else {
			int nq=++tot; T[nq]=T[q],T[nq].end=0;
			T[nq].len=T[p].len+1,T[q].fa=T[np].fa=nq;
			for(;p&&T[p].to[c]==q;p=T[p].fa) T[p].to[c]=nq;
		}
	}
}

int em,e[maxn],nx[maxn],ls[maxn];
void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
}

int t[maxm],tl[maxm],tr[maxm],cnt,rt[maxn];
void change(int &x,int l,int r,int p){
	if (!x) x=++cnt; t[x]++;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (p<=mid) change(tl[x],l,mid,p);
	else change(tr[x],mid+1,r,p);
}

int find(int x,int l,int r,int L,int R){
	if (!x||l>R||r<L) return 0;
	if (L<=l&&r<=R) return t[x];
	int mid=(l+r)>>1;
	return find(tl[x],l,mid,L,R)+find(tr[x],mid+1,r,L,R);
}

void merge(int &x,int y,int l,int r){
	t[++cnt]=t[x]+t[y],tl[cnt]=tl[x],tr[cnt]=tr[x],x=cnt;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (tl[x]&&tl[y]) merge(tl[x],tl[y],l,mid);
	else if (tl[y]) tl[x]=tl[y];
	if (tr[x]&&tr[y]) merge(tr[x],tr[y],mid+1,r);
	else if (tr[y]) tr[x]=tr[y];
}

void cover(int x){
	if (tl[x]) cover(tl[x]);
	if (tr[x]) cover(tr[x]);
}

void dfs(int x){
	rt[x]=++cnt;
	if (T[x].end) change(rt[x],1,n,T[x].end);
	for(int i=ls[x];i;i=nx[i]) {
		dfs(e[i]);
		merge(rt[x],rt[e[i]],1,n);
		T[x].end=T[e[i]].end;
	}
}

int d[maxn],f[maxn],ans;
int check(int y,int x){
	return find(rt[y],1,n,T[x].end-T[x].len+T[y].len,T[x].end-1)>0;
}

void dp(int x,int y){
	while (y<d[0]&&check(d[y+1],x)) y++;
	f[x]=f[d[y]]+1;
	ans=max(ans,f[x]);
	d[++d[0]]=x;
	for(int i=ls[x];i;i=nx[i]) dp(e[i],y);
	d[0]--;
}

int main(){
	scanf("%d",&n);
	char ch=getchar(); while (ch<'a'||ch>'z') ch=getchar();
	tot=Rt=las=1;
	for(i=1;i<=n;i++) add(ch-'a',i),ch=getchar();
	for(i=1;i<=tot;i++) if (T[i].fa) 
		insert(T[i].fa,i);
	dfs(Rt);
	for(i=ls[Rt];i;i=nx[i]) {
		dp(e[i],0);
	}
	printf("%d",ans);
}