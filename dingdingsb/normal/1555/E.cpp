// Problem: E. Boring Segments
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include<bits/stdc++.h>
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
const int N=1e6+100;
int n,m;
struct SGT{
	struct node{
		int mn,tag;
	}t[N<<2];
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid ((l+r)>>1)
	void pushdown(int x){
		if(t[x].tag)
			t[lc].mn+=t[x].tag,t[lc].tag+=t[x].tag,
			t[rc].mn+=t[x].tag,t[rc].tag+=t[x].tag,
			t[x].tag=0;;
	}
	void upd(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l&&r<=qr){
			t[x].mn+=val;
			t[x].tag+=val;
			return;
		}
		if(r<ql||qr<l)return;
		pushdown(x);
		upd(lc,l,mid,ql,qr,val);
		upd(rc,mid+1,r,ql,qr,val);
		t[x].mn=min(t[lc].mn,t[rc].mn);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return t[x].mn;
		if(r<ql||qr<l)return 0x3f3f3f3f;
		pushdown(x);
		return min(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}T;
struct node{
	int l,r,w;
	bool operator<(const node&rhs)const{
		return w<rhs.w;
	}
}p[N];
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)
		read(p[i].l,p[i].r,p[i].w),(p[i].l!=1)&&(p[i].l++);
	sort(p+1,p+1+n);
	int ans=0x3f3f3f3f;
	int l=1,r=0;
	for(;l<=n;l++){
		while(r<n&&!T.t[1].mn)
			r++,T.upd(1,1,m,p[r].l,p[r].r,1);
		if(!T.t[1].mn)break;
		else ans=min(ans,p[r].w-p[l].w);
		T.upd(1,1,m,p[l].l,p[l].r,-1);
	}
	write(ans);
	return 0;
	cout<<"ccfn***8";
}