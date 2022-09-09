#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,i,j;
int a[100005],f[100005];
int mx[400005],tag[400005];
void upd(int x,int c){
	mx[x]+=c;tag[x]+=c;
}
void pushdo(int x){
	if(tag[x]){
		upd(x+x,tag[x]);
		upd(x+x+1,tag[x]);
		tag[x]=0;
	}
}
void build(int x,int l,int r){
	if(l==r){
		mx[x]=f[l];
		return;
	}
	int mid=(l+r)/2;
	build(x+x,l,mid);build(x+x+1,mid+1,r);
	mx[x]=min(mx[x+x],mx[x+x+1]);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql>qr) return 0x3f3f3f3f;
	if(ql<=l&&r<=qr) return mx[x];
	int mid=(l+r)/2;pushdo(x);
	if(qr<=mid)return query(x+x,l,mid,ql,qr);
	if(ql>mid) return query(x+x+1,mid+1,r,ql,qr);
	return min(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
}
void update(int x,int l,int r,int y,int c){
	if(l==r){
		mx[x]=min(mx[x],c);
		return;
	}
	int mid=(l+r)/2;pushdo(x);
	if(y<=mid)update(x+x,l,mid,y,c);else update(x+x+1,mid+1,r,y,c);
	mx[x]=min(mx[x+x],mx[x+x+1]);
}
void print(int x,int l,int r){
	if(l==r){
		cerr<<mx[x]<<' ';
		return;
	}
	int mid=(l+r)/2;pushdo(x);
	print(x+x,l,mid);print(x+x+1,mid+1,r);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;rep(i,n)cin>>a[i];
	if(n==1){
		puts("1");
		return 0;
	}
	rep(i,n) f[i]=0x3f3f3f3f;
	build(1,0,n);
	rep(i,n){
		int nf=min(query(1,0,n,a[i],a[i]),min(query(1,0,n,0,a[i]-1),query(1,0,n,a[i]+1,n))+1);
		if(a[i]!=a[i-1])upd(1,1);update(1,0,n,a[i-1],nf);
//		print(1,0,n);cerr<<endl;
	}
	cout<<mx[1]<<endl;
	return 0;
}