#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 200005
#define maxm 19
#define ll long long 
#define inf (ll)1e18+5
using namespace std;

int n,q,i,j,k,id[maxn],L;
struct arr{ll w,v,c; int i;} a[maxn];
int cmp(arr a,arr b){return a.v>b.v||a.v==b.v&&a.w<b.w;}

ll res,sum; int now;

struct val{ll w,v;};
val operator+(val a,val b){return (val){a.w+b.w,a.v+b.v};}
val operator*(val a,ll c){return (val){a.w*c,a.v*c};}
int operator<(val a,val b){return a.w<b.w||a.w==b.w&&a.v>b.v;}
struct SegmentTree{
	int lim,I[maxn*4];
	val ts[maxn*4],tm[maxn*4];
	void newnode(int x,int l){
		if (a[l].w<=lim) {
			ts[x]=(val){a[l].w,a[l].v}*a[l].c;
			tm[x]=(val){inf,0},I[x]=0;
		} else {
			ts[x]=(val){0,0};
			if ((a[l].w<=lim<<1)&&a[l].c) tm[x]=(val){a[l].w,a[l].v},I[x]=l;
			else tm[x]=(val){inf,0},I[x]=0;
		}
	}
	void upd(int x){
		ts[x]=ts[x<<1]+ts[x<<1^1];
		if (tm[x<<1]<ts[x<<1]+tm[x<<1^1])
			tm[x]=tm[x<<1],I[x]=I[x<<1];
		else tm[x]=ts[x<<1]+tm[x<<1^1],I[x]=I[x<<1^1];
	}
	void maketree(int x,int l,int r){
		if (l==r){
			newnode(x,l);return;
		}
		int mid=(l+r)>>1;
		maketree(x<<1,l,mid),maketree(x<<1^1,mid+1,r);
		upd(x);
	}
	void change(int x,int l,int r,int p){
		if (l==r){newnode(x,l);return;}
		int mid=(l+r)>>1;
		if (p<=mid) change(x<<1,l,mid,p);
		else change(x<<1^1,mid+1,r,p);
		upd(x);
	}
	void merge(int x,int l,int r,int L,int R){
		if (l>R||r<L||res<lim) return;
		if (L<=l&&r<=R){
			if (res>=tm[x].w&&I[x]){
				if (l==r) res-=tm[x].w,sum+=tm[x].v,now=l;
				else merge(x<<1,l,(l+r)>>1,L,R),merge(x<<1^1,((l+r)>>1)+1,r,L,R);
				return;
			}
			if (res>=ts[x].w) {res-=ts[x].w,sum+=ts[x].v,now=r;return;}
			else if (l==r) {ll d=res/a[l].w; res-=d*a[l].w,sum+=d*a[l].v,now=l;return;}
		}
		int mid=(l+r)>>1;
		merge(x<<1,l,mid,L,R),merge(x<<1^1,mid+1,r,L,R);
	}
} t[maxm];

int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i].c,&a[i].w,&a[i].v),a[i].i=i;
	for(i=1;i<=n;i++) k=max(k,(int)a[i].w);
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++) id[a[i].i]=i;
	L=0; while (1<<L<k) L++;
	for(i=0;i<=L;i++) 
		t[i].lim=1<<i,t[i].maketree(1,1,n);
	while (q--){
		int tp; scanf("%d",&tp);
		if (tp==1||tp==2){
			scanf("%d%d",&j,&k),a[id[k]].c+=(tp==1)?j:-j;
			for(i=0;i<=L;i++) t[i].change(1,1,n,id[k]);
		} else {
			sum=0,now=0; scanf("%lld",&res);
			for(i=L;i>=0&&now<n;i--) 
				t[i].merge(1,1,n,now+1,n);
			printf("%lld\n",sum);
		}
	}
}