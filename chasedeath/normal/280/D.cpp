#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

//#pragma GCC optimize(2)

template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
inline int max(int a,int b){ return a>b?a:b; }

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) f|=(IO=='-');
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=1e5+10,INF=1e9;


int n,m,a[N];

struct Node{
	int s;
	int ls,lp,rs,rp;
	int ma,l,r;
	Node operator + (const Node x) const {
		Node res;
		res.s=s+x.s;
		if(ls>s+x.ls) res.ls=ls,res.lp=lp;
		else res.ls=x.ls+s,res.lp=x.lp;
		if(x.rs>rs+x.s) res.rs=x.rs,res.rp=x.rp;
		else res.rs=x.s+rs,res.rp=rp;
		res.ma=max(max(ma,x.ma),rs+x.ls);
		if(res.ma==ma) res.l=l,res.r=r;
		else if(res.ma==x.ma) res.l=x.l,res.r=x.r;
		else res.l=rp,res.r=x.lp;
		return res;
	}
}s1[N<<2],s2[N<<2];
int t[N<<2];

void Down(int p) {
	if(!t[p]) return;
	t[p<<1]^=1;
	t[p<<1|1]^=1;
	swap(s1[p<<1],s2[p<<1]);
	swap(s1[p<<1|1],s2[p<<1|1]);
	t[p]=0;
}

void Build(int p,int l,int r) {
	if(l==r) {
		s1[p]=(Node){a[l],a[l],l,a[l],l,a[l],l,l};
		s2[p]=(Node){-a[l],-a[l],l,-a[l],l,-a[l],l,l};
		return;
	}
	int mid=(l+r)>>1;
	Build(p<<1,l,mid);
	Build(p<<1|1,mid+1,r);
	s1[p]=s1[p<<1]+s1[p<<1|1];
	s2[p]=s2[p<<1]+s2[p<<1|1];
}

void Upd(int p,int l,int r,int x,int y) {
	if(l==r) {
		s1[p]=(Node){y,y,l,y,l,y,l,l};
		s2[p]=(Node){-y,-y,l,-y,l,-y,l,l};
		return;
	}
	Down(p);
	int mid=(l+r)>>1;
	x<=mid?Upd(p<<1,l,mid,x,y):Upd(p<<1|1,mid+1,r,x,y);
	s1[p]=s1[p<<1]+s1[p<<1|1];
	s2[p]=s2[p<<1]+s2[p<<1|1];
}

void Set(int p,int l,int r,int ql,int qr) {
	if(l==ql&&r==qr) {
		t[p]^=1;
		swap(s1[p],s2[p]);
		return;
	}
	Down(p);
	int mid=(l+r)>>1;
	if(qr<=mid) Set(p<<1,l,mid,ql,qr);
	else if(ql>mid) Set(p<<1|1,mid+1,r,ql,qr);
	else Set(p<<1,l,mid,ql,mid),Set(p<<1|1,mid+1,r,mid+1,qr);
	s1[p]=s1[p<<1]+s1[p<<1|1];
	s2[p]=s2[p<<1]+s2[p<<1|1];
}

Node Que(int p,int l,int r,int ql,int qr) {
	if(l==ql&&r==qr) return s1[p];
	int mid=(l+r)>>1;
	Down(p);
	if(qr<=mid) return Que(p<<1,l,mid,ql,qr);
	else if(ql>mid) return Que(p<<1|1,mid+1,r,ql,qr);
	else return Que(p<<1,l,mid,ql,mid)+Que(p<<1|1,mid+1,r,mid+1,qr);
}

int tl[N],tr[N];


int main(){
	n=rd();
	rep(i,1,n) a[i]=rd();
	Build(1,1,n);
	rep(querys,1,m=rd()) {
		int opt=rd();
		if(!opt) {
			int x=rd(),y=rd();
			Upd(1,1,n,x,y);
		} else {
			int l=rd(),r=rd(),k=rd(),s=0,ans=0;
			rep(i,1,k) {
				Node t=Que(1,1,n,l,r);
				tl[i]=t.l,tr[i]=t.r;
				s+=t.ma;
				//cout<<"#"<<t.ma<<endl;
				ans=max(ans,s);
				Set(1,1,n,tl[i],tr[i]);
			}
			rep(i,1,k) Set(1,1,n,tl[i],tr[i]);
			printf("%d\n",ans);
		}
	}
}