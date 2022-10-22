#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f!=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=1e5+10;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int n,m,s[N];
struct node{
	int mn,cnt;
	int Gcd;
	node(int x=0){mn=x;cnt=1;Gcd=x;}
	friend node operator+(const node&A,const node&B){
		node C;
		if(A.mn==B.mn)C.mn=A.mn,C.cnt=A.cnt+B.cnt;
		else if(A.mn>B.mn)C.mn=B.mn,C.cnt=B.cnt;
		else if(A.mn<B.mn)C.mn=A.mn,C.cnt=A.cnt;
		C.Gcd=gcd(A.Gcd,B.Gcd);
		return C;
	}
}t[N<<2];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void build(int x,int l,int r){
	if(l==r){
		t[x]=node(s[l]);
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	t[x]=t[lc]+t[rc];
}
node qry(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return t[x];
	if(qr<=mid)return qry(lc,l,mid,ql,qr);
	if(mid<ql)return qry(rc,mid+1,r,ql,qr);
	return qry(lc,l,mid,ql,qr)+qry(rc,mid+1,r,ql,qr);
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)read(s[i]);
	build(1,1,n);
	read(m);
	while(m--){
		int l,r;read(l,r);
		node q=qry(1,1,n,l,r);
		if(q.mn==q.Gcd)
			write(r-l+1-q.cnt);
		else write(r-l+1);putchar('\n');
	}
}