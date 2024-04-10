#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=2e5+10,M=5;
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
int n,m,p,k;
int a[N];
typedef pair<int,int> pii;
typedef vector<pii> vp;
struct node{
	int len;vp c;int tag;
}t[N<<2];
vp merge(vp a,vp&b){
	//ba
	vp _;int mn;
	for(auto x:b){
		for(auto&y:a)
			if(y.first==x.first){
				y.second+=x.second;
				goto loop;
			}
		a.push_back(x);
		if(a.size()<=k)goto loop;
		mn=0x3f3f3f3f;
		for(auto y:a)mn=min(mn,y.second);
		_.clear();
		for(auto y:a)if(y.second-mn)
			_.push_back({y.first,y.second-mn});
		a=_;
		loop:;
	} return a;
}
vp one(int x,int y){
	vp _;_.push_back({x,y});
	return _;
}
void up(int x){
	t[x].c=merge(t[lc].c,t[rc].c);
}
void down(int x){
	if(t[x].tag!=0){
		t[lc].tag=t[x].tag;
		t[lc].c=one(t[x].tag,t[lc].len);
		t[rc].tag=t[x].tag;
		t[rc].c=one(t[x].tag,t[rc].len);
		t[x].tag=0;
	}
}
void build(int x,int l,int r){
	t[x].len=r-l+1;
	if(l==r){
		t[x].c=one(a[l],1);
		return; 
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(x);
}
void upd(int x,int l,int r,int ql,int qr,int val){
	if(ql<=l&&r<=qr){
		t[x].tag=val;
		t[x].c=one(val,t[x].len);
		return;
	}
	if(r<ql||qr<l)return;
	down(x);
	upd(lc,l,mid,ql,qr,val);
	upd(rc,mid+1,r,ql,qr,val);
	up(x);
}
vp ans;
void qry(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		ans=merge(ans,t[x].c);
		return;
	}
	if(r<ql||qr<l)return;
	down(x);
	qry(lc,l,mid,ql,qr);
	qry(rc,mid+1,r,ql,qr);
}
signed main(){
	read(n,m,p);k=100/p;
	for(int i=1;i<=n;i++)read(a[i]);
	build(1,1,n);
	while(m--){
		int op,l,r,v;
		read(op,l,r);
		if(op==1){
			read(v);
			upd(1,1,n,l,r,v);
		}else{
			ans.clear();
			qry(1,1,n,l,r);
			write(ans.size());putchar(' ');
			for(auto x:ans)
				write(x.first),putchar(' ');
			putchar('\n');
		}
	}
}