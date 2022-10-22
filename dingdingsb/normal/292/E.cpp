// Problem: CF292E Copying Data
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF292E
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
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e5+100;
int n,m;
int a[N],b[N];
int tag[N<<2],len[N<<2];
void pushdown(int x){
	if(tag[x]){
		tag[lc]=tag[x];
		tag[rc]=tag[x]+len[lc];
		tag[x]=0;
	}
}
void build(int x,int l,int r){
	len[x]=r-l+1;
	if(l==r)return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void upd(int x,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		tag[x]=val+l-ql;
		return;
	}
	if(r<ql||qr<l)return;
	pushdown(x);
	upd(lc,l,mid,ql,qr,val);
	upd(rc,mid+1,r,ql,qr,val);
}
int qry(int x,int l,int r,int pos){
	if(l==r){
		if(tag[x])return a[tag[x]];
		return b[l];
	}
	pushdown(x);
	if(pos<=mid)return qry(lc,l,mid,pos);
	return qry(rc,mid+1,r,pos);
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	build(1,1,n);
	while(m--){
		int op,x,y,k;read(op);
		if(op==1){
			read(x,y,k);
			upd(1,1,n,y,y+k-1,x);
		}else{
			read(x);
			write(qry(1,1,n,x));
			putchar('\n');
		}
	}
}