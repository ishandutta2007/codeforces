#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,q;int a[N];
int rev[N<<3],cov[N<<3];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
#define Range -100004,100004
void pushdown(int x){
	if(cov[x]!=0){
		cov[lc]=cov[x];rev[lc]=0;
		cov[rc]=cov[x];rev[rc]=0;
		cov[x]=0;
	}
	if(rev[x]){
		rev[lc]^=1;
		rev[rc]^=1;
		rev[x]=0;
	}
}
void Cov(int x,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		cov[x]=val,rev[x]=0;return;
	}
	pushdown(x);
	if(ql<=mid)Cov(lc,l,mid,ql,qr,val);
	if(mid<qr)Cov(rc,mid+1,r,ql,qr,val);
}
void Rev(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return void(rev[x]^=1);
	pushdown(x);
	if(ql<=mid)Rev(lc,l,mid,ql,qr);
	if(mid<qr)Rev(rc,mid+1,r,ql,qr);
}
int qry(int x,int l,int r,int pos){
	if(l==r){
		int a;if(l<=0)a=-1;else a=1;
		if(cov[x]!=0)a=cov[x];
		if(rev[x])a*=-1;
		return abs(l)*a;
	}
	pushdown(x);
	if(pos<=mid)return qry(lc,l,mid,pos);
	return qry(rc,mid+1,r,pos);
}
signed main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(q--){
		char c=getchar();while(c!='<'&&c!='>')c=getchar();
		int x;scanf("%d",&x);
		if(c=='>'){
			if(x>=0){
				Cov(1,Range,x+1,100001,-1);
				Cov(1,Range,-100001,-x-1,-1);
			}else{
				Rev(1,Range,x+1,-x-1);
				Cov(1,Range,-x,100001,-1);
				Cov(1,Range,-100001,x,-1);
			}
		}else{
			if(x<=0){
				Cov(1,Range,-100001,x-1,1);
				Cov(1,Range,-x+1,100001,1);
			}else{
				Rev(1,Range,-x+1,x-1);
				Cov(1,Range,x,100001,1);
				Cov(1,Range,-100001,-x,1);
			}
		}
	}
		for(int i=1;i<=n;i++)
			printf("%d ",qry(1,Range,a[i]));
}