#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll sum;
	int mx,se,cnt,num;
	int a,b;
}tr[524300];
int n,a[150005],b[1500005];
void push(int i,int a,int b){
	tr[i].sum+=(ll)a*tr[i].cnt+(ll)b*(tr[i].num-tr[i].cnt);
	tr[i].mx+=a,tr[i].se+=b;
	tr[i].a+=a,tr[i].b+=b;
}
void pushdown(int i){
	int ls=i<<1,rs=i<<1|1,tmp=max(tr[ls].mx,tr[rs].mx);
	if(tr[i].a!=0||tr[i].b!=0){
		if(tmp==tr[ls].mx)push(ls,tr[i].a,tr[i].b);
		else push(ls,tr[i].b,tr[i].b);
		if(tmp==tr[rs].mx)push(rs,tr[i].a,tr[i].b);
		else push(rs,tr[i].b,tr[i].b);
		tr[i].a=tr[i].b=0;
	}
}
void pushup(int i){
	int ls=i<<1,rs=i<<1|1;
	tr[i].sum=tr[ls].sum+tr[rs].sum;
	tr[i].num=tr[ls].num+tr[rs].num;
	tr[i].mx=max(tr[ls].mx,tr[rs].mx);
	tr[i].se=-1e9,tr[i].cnt=0;
	if(tr[ls].mx==tr[i].mx)tr[i].cnt+=tr[ls].cnt,tr[i].se=max(tr[i].se,tr[ls].se);
	else tr[i].se=max(tr[i].se,tr[ls].mx);
	if(tr[rs].mx==tr[i].mx)tr[i].cnt+=tr[rs].cnt,tr[i].se=max(tr[i].se,tr[rs].se);
	else tr[i].se=max(tr[i].se,tr[rs].mx);
}
void built(int l,int r,int i){
	tr[i].a=tr[i].b=0;
	if(l==r){
		tr[i].sum=0;
		tr[i].cnt=tr[i].num=0;
		tr[i].mx=-1e9,tr[i].se=-2e9;
		return;
	}
	int mid=(l+r)>>1;
	built(l,mid,i<<1),built(mid+1,r,i<<1|1);
	pushup(i);
}
void add(int l,int r,int i,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		push(i,x,x);
		return;
	}
	pushdown(i);
	int mid=(l+r)>>1;
	add(l,mid,i<<1,a,b,x),add(mid+1,r,i<<1|1,a,b,x);
	pushup(i);
}
void mnn(int l,int r,int i,int a,int b,int x){
	if(r<a||b<l||tr[i].mx<x)return;
	if(a<=l&&r<=b&&tr[i].se<x){
		push(i,x-tr[i].mx,0);
		return;
	}
	pushdown(i);
	int mid=(l+r)>>1;
	mnn(l,mid,i<<1,a,b,x),mnn(mid+1,r,i<<1|1,a,b,x);
	pushup(i);
}
void upd(int l,int r,int i,int p,int x){
	if(l==r){
		tr[i].sum=x+1;
		tr[i].a=tr[i].b=0;
		tr[i].cnt=tr[i].num=1;
		tr[i].mx=x+1,tr[i].se=-1e9;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(i);
	if(p<=mid)upd(l,mid,i<<1,p,x);
	else upd(mid+1,r,i<<1|1,p,x);
	pushup(i);
}
int bit[150005];
void add(int i){
	for(;i<=n;i+=i&-i)bit[i]++;
}
int got(int i){
	int ans=0;
	for(;i;i-=i&-i)ans+=bit[i];
	return ans;
}
ll ans[150005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]=i;
	built(1,n,1);
	for(int i=1;i<=n;i++){
		int p=b[i],t=got(p)+1;
		if(p>1)mnn(1,n,1,1,p-1,t);
		if(p<n)add(1,n,1,p+1,n,1);
		upd(1,n,1,p,i);
		ans[i]=tr[1].sum;
		add(p);
	}
	reverse(a+1,a+n+1);for(int i=1;i<=n;i++)b[a[i]]=i;
	memset(bit,0,sizeof(bit));
	built(1,n,1);
	for(int i=1;i<=n;i++){
		int p=b[i],t=got(p)+1;
		if(p>1)mnn(1,n,1,1,p-1,t);
		if(p<n)add(1,n,1,p+1,n,1);
		upd(1,n,1,p,i);
		ans[i]+=tr[1].sum;
		add(p);
	}
	for(int i=1;i<=n;i++)printf("%I64d\n",ans[i]-(ll)i*(i+2));
}