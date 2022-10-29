#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 300005
#define ll long long 
using namespace std;

int n,i,j,k,h[maxn],v[maxn];
ll tf[maxn*4],tg[maxn*4]; int tag[maxn*4];

void downtag(int x,int l,int r){
	tf[x]=tg[x]=-1e18;
	if (l<r) tag[x<<1]|=tag[x],tag[x<<1^1]|=tag[x];
	tag[x]=0;
}
void upd(int x){
	tf[x]=max(tf[x<<1],tf[x<<1^1]);
	tg[x]=max(tg[x<<1],tg[x<<1^1]);
}
void change(int x,int l,int r,int p,ll f){
	if (tag[x]) downtag(x,l,r);
	tf[x]=max(tf[x],f),tg[x]=max(tg[x],f+v[p]);
	if (l==r) return;
	int mid=(l+r)>>1;
	if (p<=mid) change(x<<1,l,mid,p,f);
	else change(x<<1^1,mid+1,r,p,f);
}
void cover(int x,int l,int r,int L,int R){
	if (tag[x]) downtag(x,l,r);
	if (l>R||r<L) return;
	if (L<=l&&r<=R) {tag[x]=1,downtag(x,l,r);return;}
	int mid=(l+r)>>1;
	cover(x<<1,l,mid,L,R),cover(x<<1^1,mid+1,r,L,R);
	upd(x);
}
ll find(int x,int l,int r,int L,int R){
	if (tag[x]) downtag(x,l,r);
	if (l>R||r<L) return -1e18;
	if (L<=l&&r<=R) return tf[x];
	int mid=(l+r)>>1;
	return max(find(x<<1,l,mid,L,R),find(x<<1^1,mid+1,r,L,R));
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&h[i]);
	for(i=1;i<=n;i++) scanf("%d",&v[h[i]]);
	tag[1]=1,downtag(1,1,n);
	change(1,1,n,h[1],0);
	for(i=2;i<=n;i++){
		ll tmp=max(find(1,1,n,h[i],n),tg[1]);
		change(1,1,n,h[i],tmp);
		cover(1,1,n,h[i]+1,n);
	}
	printf("%lld\n",tg[1]);
}