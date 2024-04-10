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
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=2e5+100;
int n,m,a[N];
struct node{
	int lval,rval,L,R,fl,sum;
	node(int x=0):lval(x),rval(x),L(1),R(1),fl(1),sum(1){}
	node(int lval,int rval,int L,int R,int fl,int sum):lval(lval),rval(rval),L(L),R(R),fl(fl),sum(sum){}
	friend node operator+(const node&a,const node&b){
		node ans=node(a.lval,b.rval,a.L,b.R,a.fl&&b.fl&&a.rval<=b.lval,a.sum+b.sum);
		if(a.rval<=b.lval){
			ans.sum+=a.R*b.L;
			if(a.fl)ans.L=a.L+b.L;
			if(b.fl)ans.R=a.R+b.R;
		}return ans;
	}
}t[N<<2];
void build(int x,int l,int r){
	if(l==r)
		return t[x]=node(a[l]),void();
	build(lc,l,mid);build(rc,mid+1,r);
	t[x]=t[lc]+t[rc];
}
void upd(int x,int l,int r,int pos,int val){
	if(l==r)return t[x]=node(val),void();
	if(pos<=mid)upd(lc,l,mid,pos,val);
	else upd(rc,mid+1,r,pos,val);
	t[x]=t[lc]+t[rc];
}
node qry(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return t[x];
	if(qr<=mid)return qry(lc,l,mid,ql,qr);
	if(mid<ql)return qry(rc,mid+1,r,ql,qr);
	return qry(lc,l,mid,ql,qr)+qry(rc,mid+1,r,ql,qr);
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	build(1,1,n);
	while(m--){
		int op,x,y;read(op,x,y);
		if(op==1){
			upd(1,1,n,x,y);
		}else{
			auto res=qry(1,1,n,x,y);
			write(res.sum);putchar('\n');
		}
	}
}