#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 500005
using namespace std;

int T,n,i,j,k,a[maxn],f[maxn],g[maxn],t[maxn*4],d[maxn],id[maxn];
int cmp(int i,int j){return g[i]<g[j];}

void maketree(int x,int l,int r){
	t[x]=0; if (l==r) return;
	int mid=(l+r)>>1;
	maketree(x<<1,l,mid),maketree(x<<1^1,mid+1,r);
}
int find(int x,int l,int r,int L,int R){
	if (l>R||r<L) return 0;
	if (L<=l&&r<=R) return t[x];
	int mid=(l+r)>>1;
	return max(find(x<<1,l,mid,L,R),find(x<<1^1,mid+1,r,L,R));
}
void change(int x,int l,int r,int p,int v){
	if (l==r) {t[x]=max(t[x],v);return;}
	int mid=(l+r)>>1;
	if (p<=mid) change(x<<1,l,mid,p,v);
	else change(x<<1^1,mid+1,r,p,v);
	t[x]=max(t[x<<1],t[x<<1^1]);
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		maketree(1,0,n);
		int w=0; 
		for(i=n;i>=1;i--){
			while (w&&a[i]>a[d[w]]) w--;
			if (!w) g[i]=n+1; else g[i]=d[w];
			d[++w]=i;
		}
		g[0]=1;
		for(i=0;i<=n;i++) id[i]=i;
		sort(id,id+1+n,cmp),j=0;
		for(i=0;i<=n;i++){
			f[i]=find(1,0,n,0,a[i])+1;
			while (j<=n&&g[id[j]]==i){
				f[id[j]]++;
				change(1,0,n,a[id[j]],f[id[j]]);
				j++;
			}
			change(1,0,n,a[i],f[i]);
		}
		printf("%d\n",t[1]-1);
	}
}