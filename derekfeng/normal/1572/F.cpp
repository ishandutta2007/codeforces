#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef long long ll;
const int INF=2e9+114,M=333;
int B1[666],num[200005];
int n,L[666],R[666],q;
ll B2[666];
struct Sqrt{
	void init(){
		int N=(n-1)/M+1;
		for(int i=1;i<=N;i++){
			L[i]=(i-1)*M+1;
			R[i]=min(n,L[i]+M-1);
		}
	}
	void upd(int i,int x){
		int b=(i-1)/M+1;
		num[i]+=x,B1[b]+=x;
		B2[b]+=(R[b]-i+1)*x;
	}
	ll qry(int l,int r){
		int b1=(l-1)/M+1,b2=(r-1)/M+1;
		int cur=0,val=0;
		for(int i=1;R[i]<l;i++)val+=B1[i],cur=R[i];
		while(cur<l-1)cur++,val+=num[cur];
		ll ans=0;
		if(b1==b2){
			while(cur<r)cur++,val+=num[cur],ans+=val;
			return ans;
		}
		while(cur<R[b1])cur++,val+=num[cur],ans+=val;
		for(int i=b1+1;i<b2;i++){
			ans+=(ll)(R[i]-L[i]+1)*val+B2[i];
			val+=B1[i],cur=R[i];
		}
		while(cur<r)cur++,val+=num[cur],ans+=val;
		return ans;
	}
}B;
struct node{
	int mx,se,cnt;
	int a,b;
}tr[525000];
void push(int l,int r,int i,int a,int b){
	int len=r-l+1;
	tr[i].mx+=a,tr[i].a+=a;
	if(tr[i].se!=-INF)tr[i].se+=b;tr[i].b+=b;
}
void pushdown(int l,int r,int i){
	int ls=i<<1,rs=i<<1|1,mid=(l+r)>>1,tmp=max(tr[ls].mx,tr[rs].mx);
	if(tr[i].a!=0||tr[i].b!=0){
		if(tr[ls].mx==tmp)push(l,mid,ls,tr[i].a,tr[i].b);
		else push(l,mid,ls,tr[i].b,tr[i].b);
		if(tr[rs].mx==tmp)push(mid+1,r,rs,tr[i].a,tr[i].b);
		else push(mid+1,r,rs,tr[i].b,tr[i].b);
		tr[i].a=tr[i].b=0;
	}
}
void pushup(int i){
	int ls=i<<1,rs=i<<1|1;
	tr[i].se=-INF;
	tr[i].mx=max(tr[ls].mx,tr[rs].mx);
	tr[i].cnt=0;
	if(tr[i].mx==tr[ls].mx)tr[i].cnt+=tr[ls].cnt,tr[i].se=max(tr[i].se,tr[ls].se);
	else tr[i].se=max(tr[i].se,tr[ls].mx);
	if(tr[i].mx==tr[rs].mx)tr[i].cnt+=tr[rs].cnt,tr[i].se=max(tr[i].se,tr[rs].se);
	else tr[i].se=max(tr[i].se,tr[rs].mx);
}
void built(int l,int r,int i){
	if(l==r){
		tr[i].mx=l;
		tr[i].se=-INF,tr[i].cnt=1;
		tr[i].a=tr[i].b=0;
		return;
	}
	int mid=(l+r)>>1;
	built(l,mid,i<<1),built(mid+1,r,i<<1|1);
	pushup(i);
}
void add(int l,int r,int i,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		push(l,r,i,x,x);
		return;
	}
	pushdown(l,r,i);
	int mid=(l+r)>>1;
	add(l,mid,i<<1,a,b,x),add(mid+1,r,i<<1|1,a,b,x);
	pushup(i);
}
int qr(int l,int r,int i,int p){
	if(l==r)return tr[i].mx;
	pushdown(l,r,i);
	int mid=(l+r)>>1;
	if(p<=mid)return qr(l,mid,i<<1,p);
	return qr(mid+1,r,i<<1|1,p);
}
void mnn(int l,int r,int i,int a,int b,int x){
	if(r<a||b<l||tr[i].mx<=x)return;
	if(a<=l&&r<=b&&tr[i].se<x){
		B.upd(x+1,-tr[i].cnt),B.upd(tr[i].mx+1,tr[i].cnt);
		push(l,r,i,x-tr[i].mx,0);
		return;
	}
	pushdown(l,r,i);
	int mid=(l+r)>>1;
	mnn(l,mid,i<<1,a,b,x),mnn(mid+1,r,i<<1|1,a,b,x);
	pushup(i);
}
int main(){
	scanf("%d%d",&n,&q);
	built(1,n,1);
	B.init();
	for(int i=1;i<=n;i++)B.upd(i,1),B.upd(i+1,-1);
	while(q--){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			int p=qr(1,n,1,x);
			add(1,n,1,x,x,y-p);
			if(y>p)B.upd(p+1,1),B.upd(y+1,-1);
			if(y<p)B.upd(y+1,-1),B.upd(p+1,1);
			if(x!=1)mnn(1,n,1,1,x-1,x-1);
		}else printf("%lld\n",B.qry(x,y));
	}
}