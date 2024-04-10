#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i;
long long a[100005];
struct node{
	long long sum,prea,sufa,preb,sufb,ans;
}t[400005];
node merge(node x,node y){
	node z;
	z.sum=x.sum+y.sum;
	z.prea=max(x.prea,x.sum+y.prea);
	z.preb=min(x.preb,x.sum+y.preb);
	z.sufa=max(y.sufa,y.sum+x.sufa);
	z.sufb=min(y.sufb,y.sum+x.sufb);
	z.ans=max(max(x.ans,y.ans),max(abs(x.sufa+y.prea),abs(x.sufb+y.preb)));
	return z;
}
void build(int x,int l,int r){
	if(l==r){
		t[x]=(node){a[l],max(0ll,a[l]),max(0ll,a[l]),min(0ll,a[l]),min(0ll,a[l]),abs(a[l])};
		return;
	}
	int mid=(l+r)/2;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
	t[x]=merge(t[x+x],t[x+x+1]);
}
node query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return t[x];
	int mid=(l+r)/2;
	if(qr<=mid)return query(x+x,l,mid,ql,qr);
	if(ql>mid)return query(x+x+1,mid+1,r,ql,qr);
	return merge(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n){
		int x;
		scanf("%d",&x);
		a[i]-=x;
	}
	rep(i,n){
		int x;
		scanf("%d",&x);
		a[i]+=x;
	}
	build(1,1,n);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		node t=query(1,1,n,l,r);
		if(t.sum!=0||t.preb<0){
			puts("-1");
			continue;
		}
		printf("%lld\n",t.ans);
	}
	return 0;
}