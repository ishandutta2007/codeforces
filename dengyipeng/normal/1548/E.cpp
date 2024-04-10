#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define maxn 200005
#define ll long long
using namespace std;

int n,m,L,i,j,k,a[maxn],b[maxn],id[maxn],p[maxn];
int cmp(int i,int j){return b[i]<b[j]||b[i]==b[j]&&i<j;}

int f[maxn],d[maxn],d0[maxn];
vector<int> D[maxn];

void prepare(){
	int w=1; d[1]=0,d0[1]=0;
	for(i=1;i<=m;i++) f[i]=m+1;
	for(i=1;i<=m;i++){
		while (id[i]<id[d[w]])
			d0[w-1]=max(d0[w-1],d0[w]),w--;
		if (w>1) f[i]=min(f[i],d0[w]);
		w++,d[w]=i,d0[w]=id[i];
	}
	w=1,d[1]=m+1,d0[1]=0;
	for(i=m;i>=1;i--){
		while (id[i]<id[d[w]])
			d0[w-1]=max(d0[w-1],d0[w]),w--;
		if (w>1) f[i]=min(f[i],d0[w]);
		w++,d[w]=i,d0[w]=id[i];
	}
	for(i=1;i<=m;i++) D[f[i]].push_back(i);
}

struct arr{int l,r,v;} A[maxn*2]; int tot;
void add(int l,int r,int v){A[++tot]=(arr){l,r,v};}
int cmp2(arr a,arr b){return a.v<b.v;}

void doit(){
	int w=1,now=0; d[1]=0,d0[1]=0;
	for(i=1;i<=n+1;i++){
		int l=1,r=m,mid,v=0;
		if (i<=n) 
			while (l<=r){
				mid=(l+r)>>1;
				if (a[i]+b[p[mid]]<=L) v=mid,l=mid+1;
				else r=mid-1;
			}
		if (v==now) continue;
		if (v>now){
			int st=now+1;
			while (w&&d0[w]<=v) st=d[w],w--;
			w++,d[w]=st,d0[w]=v,now=v;
		} else {
			while (d[w]>v) 
				add(d[w],now,d0[w]),now=d[w]-1,w--;
			if (v+1<=now) 
				add(v+1,now,d0[w]);
			now=v;
		}
	}	
}
struct Treearray{
	int s[maxn];
	void add(int x,int d){for(;x<=m;x+=x&-x) s[x]+=d;}
	int sum(int x,int S=0){for(;x;x-=x&-x) S+=s[x];return S;}
	int query(int l,int r){return sum(r)-sum(l-1);}
} t;
void cal(){
	sort(A+1,A+1+tot,cmp2); ll ans=0;
	for(i=0,j=1;i<=m;i++){
		for(k=0;k<D[i].size();k++) 
			t.add(id[D[i][k]],1);	
		while (j<=tot&&A[j].v==i)
			ans+=A[j].r-A[j].l+1-t.query(A[j].l,A[j].r),j++;
	}
	printf("%lld\n",ans);
}

int main(){
	scanf("%d%d%d",&n,&m,&L);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]),p[i]=i;
	sort(p+1,p+1+m,cmp);
	for(i=1;i<=m;i++) id[p[i]]=i;
	prepare();
	doit();
	cal();
}