// Problem: CF1136E Nastya Hasn't Written a Legend
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1136E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
typedef long long ll;
const int N=1e5+100;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,a[N],k[N];
int s[N],ss[N];
int m;
int sum[N<<2],mn[N<<2],len[N<<2],tag[N<<2];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void pushup(int x){
	sum[x]=sum[lc]+sum[rc];
	mn[x]=min(mn[lc],mn[rc]);
}
void pushdown(int x){
	if(tag[x]==inf)return;
	sum[lc]=tag[x]*len[lc];
	mn[lc]=tag[x];
	tag[lc]=tag[x];
	sum[rc]=tag[x]*len[rc];
	mn[rc]=tag[x];
	tag[rc]=tag[x];
	tag[x]=inf;
}
void build(int x,int l,int r){
	tag[x]=inf;
	len[x]=r-l+1;
	if(l==r){
		sum[x]=mn[x]=a[l]-s[l];
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
}
void upd(int x,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		tag[x]=mn[x]=val;
		sum[x]=len[x]*val;
		return;
	}
	if(r<ql||qr<l)return;
	pushdown(x);
	upd(lc,l,mid,ql,qr,val);
	upd(rc,mid+1,r,ql,qr,val);
	pushup(x);
}
int qry(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return sum[x];
	if(r<ql||qr<l)return 0;
	pushdown(x);
	return qry(lc,l,mid,ql,qr)+qry(rc,mid+1,r,ql,qr);
}
int ask(int x,int l,int r,int val){
	if(l==r)return l;
	pushdown(x);
	if(mn[rc]<=val)return ask(rc,mid+1,r,val);
	else return ask(lc,l,mid,val);
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=2;i<=n;i++)read(k[i]),s[i]=s[i-1]+k[i],ss[i]=ss[i-1]+s[i];
	build(1,1,n);
	read(m);
	while(m--){
		char op=getchar();while(op!='s'&&op!='+')op=getchar();
		if(op=='s'){
			int l,r;read(l,r);
			write(qry(1,1,n,l,r)+ss[r]-ss[l-1]);
			putchar('\n');
		}else{
			int x,y;read(x,y);
			int now=qry(1,1,n,x,x);
			upd(1,1,n,x,ask(1,1,n,now+y),now+y);
		}
	}
}