// Problem: CF794F Leha and security system
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF794F
// Memory Limit: 500 MB
// Time Limit: 2000 ms
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
#define int long long
const int N=1e5+10,M=10;
int n,m,a[N];
struct node{
	int sum[M];
	int tag[M];
	node(){for(int i=0;i<M;i++)tag[i]=i;}
	void upd(int x,int y){
		assert(x!=y);
		sum[y]+=sum[x];sum[x]=0;
		for(int i=0;i<M;i++)if(tag[i]==x)
			tag[i]=y;
	}
	void upd(node&fa){
		static int tsum[M],ttag[M];
		memcpy(tsum,sum,sizeof sum);
		memcpy(ttag,tag,sizeof sum);
		for(int i=0;i<M;i++)if(fa.tag[i]!=i){
			for(int j=0;j<M;j++)if(tag[j]==i)
				ttag[j]=fa.tag[i];
			tsum[fa.tag[i]]+=sum[i];
			tsum[i]-=sum[i];
		}
		memcpy(sum,tsum,sizeof sum);
		memcpy(tag,ttag,sizeof tag);
	}
	int calc(){
		int ans=0;
		for(int i=1;i<M;i++)
			ans+=i*sum[i];
		return ans;
	}
}t[N<<3];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void pushup(int x){
	for(int i=0;i<M;i++)
		t[x].sum[i]=t[lc].sum[i]+t[rc].sum[i];
}
void pushdown(int x){
	t[lc].upd(t[x]);
	t[rc].upd(t[x]);
	for(int i=0;i<M;i++)
		t[x].tag[i]=i;
}
void build(int x,int l,int r){
	if(l==r){
		for(int i=1;a[l]/i;i*=10)
			t[x].sum[a[l]/i%10]+=i;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
}
void upd(int x,int l,int r,int ql,int qr,int a,int b){
	if(ql<=l&&r<=qr){
		t[x].upd(a,b);
		return;
	}
	if(r<ql||qr<l)return;
	pushdown(x);
	upd(lc,l,mid,ql,qr,a,b);
	upd(rc,mid+1,r,ql,qr,a,b);
	pushup(x);
}
int qry(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return t[x].calc();
	if(r<ql||qr<l)return 0;
	pushdown(x);
	return qry(lc,l,mid,ql,qr)+qry(rc,mid+1,r,ql,qr);
}
signed main(){
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	build(1,1,n);
	while(m--){
		int op;read(op);
		if(op==1){
			int l,r,x,y;read(l);read(r);read(x);read(y);
			if(x==y)continue;
			upd(1,1,n,l,r,x,y);
		}else{
			int l,r;read(l);read(r);
			write(qry(1,1,n,l,r));putchar('\n');
		}
	}
}