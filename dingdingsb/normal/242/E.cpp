// Problem: CF242E XOR on Segment
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF242E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<class T>
inline void read(T &x){
	x=0;char c=getchar();bool flag=false;
	for(;!isdigit(c);c=getchar())flag|=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(flag)x=-x;
}
template<class T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+10,M=21;
int b[N];
struct SGT{
	struct node{
		int len;
		int sum;
		bool rev;
	}t[N<<2];
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid ((l+r)>>1)
	void pushup(int x){
		t[x].sum=t[lc].sum+t[rc].sum;
	}
	void pushdown(int x){
		if(t[x].rev){
			t[lc].rev^=1;
			t[lc].sum=t[lc].len-t[lc].sum;
			t[rc].rev^=1;
			t[rc].sum=t[rc].len-t[rc].sum;
			t[x].rev=0;
		}
	}
	void build(int x,int l,int r){
		t[x].len=r-l+1;
		if(l==r){
			t[x].sum=b[l];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	void upd(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr){
			t[x].rev^=1;
			t[x].sum=t[x].len-t[x].sum;
			return;
		}
		if(r<ql||qr<l)return;
		pushdown(x);
		upd(lc,l,mid,ql,qr);
		upd(rc,mid+1,r,ql,qr);
		pushup(x);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return t[x].sum;
		if(r<ql||qr<l)return 0;
		pushdown(x);
		return qry(lc,l,mid,ql,qr)+qry(rc,mid+1,r,ql,qr);
	}
}T[M];
int n,m,a[N];
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int j=0;j<M;j++){
		for(int i=1;i<=n;i++)
			b[i]=a[i]>>j&1;
		T[j].build(1,1,n);
	}
	read(m);
	while(m--){
		int op,l,r,x;read(op);read(l);read(r);
		if(op==1){
			long long ans=0;
			for(int j=0;j<M;j++)
				ans+=((1ll*T[j].qry(1,1,n,l,r))<<j);
			write(ans);putchar('\n');
		}else{
			read(x);
			for(int j=0;j<M;j++)
				if((x>>j)&1)T[j].upd(1,1,n,l,r);
		}
	}
}