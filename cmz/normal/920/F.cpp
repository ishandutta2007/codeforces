#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,maxk=1e6+10;
typedef long long ll;
int Max[maxn*4],a[maxn],val[maxk];
ll sum[maxn*4];
int n,m;
inline void pushup(int now){
	sum[now]=sum[now*2]+sum[now*2+1]; 
	Max[now]=max(Max[now*2],Max[now*2+1]);
}
void build(int now,int l,int r){
	if (l==r){
		Max[now]=sum[now]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(now*2,l,mid); build(now*2+1,mid+1,r);
	pushup(now);
}
ll query(int now,int l,int r,int cl,int cr){
	if (r<cl||cr<l) return 0;
	if (l>=cl&&r<=cr) return sum[now];
	int mid=(l+r)/2; ll ans=0;
	if (cl<=mid) ans+=query(now*2,l,mid,cl,cr);
	if (cr>mid) ans+=query(now*2+1,mid+1,r,cl,cr);
	return ans;
}
void update(int now,int l,int r,int cl,int cr){
	if (l==r){
		a[l]=val[a[l]]; Max[now]=sum[now]=a[l];
		return;
	}
	int mid=(l+r)/2;
	if (Max[now*2]>2&&cl<=mid) update(now*2,l,mid,cl,cr); 
	if (Max[now*2+1]>2&&cr>mid) update(now*2+1,mid+1,r,cl,cr);
	pushup(now);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=1e6;++i){
		for (int j=1;j<=1e6/i;++j) val[i*j]++;
	}
	build(1,1,n);
	for (int i=1,opt,x,y;i<=m;++i){
		scanf("%d%d%d",&opt,&x,&y);
		if (opt==1) update(1,1,n,x,y); else  printf("%lld\n",query(1,1,n,x,y));
	}
	return 0;
}