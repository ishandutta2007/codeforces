#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,i,j,h[300005],a[300005],l[300005],r[300005];
long long mx[1200005],tag[1200005];
void build(int x,int l,int r){
	mx[x]=tag[x]=-0x3f3f3f3f3f3f3f3fll;
	if(l==r)return;
	int mid=(l+r)/2;
	build(x+x,l,mid);build(x+x+1,mid+1,r);
}
void upd(int x,long long y){
	mx[x]=max(mx[x],y);
	tag[x]=max(tag[x],y);
}
void pushdo(int x){
	upd(x+x,tag[x]);
	upd(x+x+1,tag[x]);
	tag[x]=-0x3f3f3f3f3f3f3f3fll;
}
void update(int x,int l,int r,int ql,int qr,long long y){
	if(ql<=l&&r<=qr){
		upd(x,y);return;
	}
	pushdo(x);
	int mid=(l+r)/2;
	if(ql<=mid)update(x+x,l,mid,ql,qr,y);
	if(qr>mid)update(x+x+1,mid+1,r,ql,qr,y);
	mx[x]=max(mx[x+x],mx[x+x+1]);
}
long long query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return mx[x];
	pushdo(x);
	int mid=(l+r)/2;
	if(qr<=mid)return query(x+x,l,mid,ql,qr);
	if(ql>mid)return query(x+x+1,mid+1,r,ql,qr);
	return max(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&h[i]);
	}
	rep(i,n){
		scanf("%d",&a[i]);
	}
	build(1,0,n);update(1,0,n,0,0,0);
	stack<int> stk;
	rep(i,n){
		while(!stk.empty()&&h[stk.top()]>h[i]){
			r[stk.top()]=i-1;stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		r[stk.top()]=n;stk.pop();
	}
	for(i=n;i;i--){
		while(!stk.empty()&&h[stk.top()]>h[i]){
			l[stk.top()]=i+1;stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()){
		l[stk.top()]=1;stk.pop();
	}
	rep(i,n){
		update(1,0,n,i,r[i],query(1,0,n,l[i]-1,i-1)+a[i]);
	}
	printf("%lld\n",query(1,0,n,n,n));
	return 0;
}