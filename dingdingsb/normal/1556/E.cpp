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
int n,m,a[N],b[N];
int s[N];
int mx[N<<2],mn[N<<2];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
void pushup(int x){
	mx[x]=max(mx[lc],mx[rc]);
	mn[x]=min(mn[lc],mn[rc]);
}
void build(int x,int l,int r){
	if(l==r)return mx[x]=mn[x]=s[l],void();
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(x);
}
int qrymx(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return mx[x];
	if(r<ql||qr<l)return -inf;
	return max(qrymx(lc,l,mid,ql,qr),qrymx(rc,mid+1,r,ql,qr));
}
int qrymn(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return mn[x];
	if(r<ql||qr<l)return inf;
	return min(qrymn(lc,l,mid,ql,qr),qrymn(rc,mid+1,r,ql,qr));
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i]-b[i];
	build(1,1,n);
	while(m--){
		int l,r;read(l,r);
		if(s[l-1]!=s[r])puts("-1");
		else if(qrymx(1,1,n,l,r)>s[l-1])puts("-1");
		else write(s[l-1]-qrymn(1,1,n,l,r)),putchar('\n');
	}
}