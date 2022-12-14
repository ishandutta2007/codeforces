#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
#define pii pair<int,int>
namespace fast_io
{
	char buf[1<<18],*p1=buf,*p2=buf,sr[1<<23],z[23];int C=-1,Z=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;char c;while(c=gc(),(c<48||c>57)&&c!=-1) if(c==45) y=-1;
		x=c-48;while(c=gc(),47<c&&c<58) x=(x<<3)+(x<<1)+(c^48);return x*y;
	}
	in db gf() {int a=read(),b=read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	template <typename T>
	in void write(T x,char t)
	{
		re y=0;if(x<0) y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y) z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;
	}
	in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++,*s++)sr[++C]=*s;sr[++C]='\n';}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
};
using namespace fast_io;
const int N=1e5+5;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
int n,m,a[N];
int t[N<<2],mx[N<<2],mn[N<<2],lmn[N<<2],lmx[N<<2],rmn[N<<2],rmx[N<<2],inv[N<<2];
int mxl[N<<2],mxr[N<<2],mnl[N<<2],mnr[N<<2],lmxd[N<<2],lmnd[N<<2],rmxd[N<<2],rmnd[N<<2];
in void push_up(re p)
{
	t[p]=t[ls(p)]+t[rs(p)];
	lmx[p]=max(lmx[ls(p)],t[ls(p)]+lmx[rs(p)]);lmn[p]=min(lmn[ls(p)],t[ls(p)]+lmn[rs(p)]);
	rmx[p]=max(rmx[rs(p)],t[rs(p)]+rmx[ls(p)]);rmn[p]=min(rmn[rs(p)],t[rs(p)]+rmn[ls(p)]);
	lmxd[p]=(lmx[p]==lmx[ls(p)]?lmxd[ls(p)]:lmxd[rs(p)]);
	lmnd[p]=(lmn[p]==lmn[ls(p)]?lmnd[ls(p)]:lmnd[rs(p)]);
	rmxd[p]=(rmx[p]==rmx[rs(p)]?rmxd[rs(p)]:rmxd[ls(p)]);
	rmnd[p]=(rmn[p]==rmn[rs(p)]?rmnd[rs(p)]:rmnd[ls(p)]);
	mx[p]=max(max(mx[ls(p)],mx[rs(p)]),rmx[ls(p)]+lmx[rs(p)]);
	mn[p]=min(min(mn[ls(p)],mn[rs(p)]),rmn[ls(p)]+lmn[rs(p)]);
	mxl[p]=(mx[p]==rmx[ls(p)]+lmx[rs(p)]?rmxd[ls(p)]:mx[p]==mx[ls(p)]?mxl[ls(p)]:mxl[rs(p)]);
	mxr[p]=(mx[p]==rmx[ls(p)]+lmx[rs(p)]?lmxd[rs(p)]:mx[p]==mx[ls(p)]?mxr[ls(p)]:mxr[rs(p)]);
	mnl[p]=(mn[p]==rmn[ls(p)]+lmn[rs(p)]?rmnd[ls(p)]:mn[p]==mn[ls(p)]?mnl[ls(p)]:mnl[rs(p)]);
	mnr[p]=(mn[p]==rmn[ls(p)]+lmn[rs(p)]?lmnd[rs(p)]:mn[p]==mn[ls(p)]?mnr[ls(p)]:mnr[rs(p)]);
}
in void adjust(re p)
{
	inv[p]^=1;t[p]=-t[p];swap(mx[p],mn[p]);mx[p]=-mx[p];mn[p]=-mn[p];
	swap(lmxd[p],lmnd[p]);swap(rmxd[p],rmnd[p]);
	swap(mxl[p],mnl[p]);swap(mxr[p],mnr[p]);
	swap(lmx[p],lmn[p]);lmx[p]=-lmx[p];lmn[p]=-lmn[p];
	swap(rmx[p],rmn[p]);rmx[p]=-rmx[p];rmn[p]=-rmn[p];
}
in void init(re p,re x,re y)
{
	t[p]=mx[p]=mn[p]=lmn[p]=lmx[p]=rmn[p]=rmx[p]=x;
	mxl[p]=mnl[p]=mxr[p]=mnr[p]=lmxd[p]=lmnd[p]=rmxd[p]=rmnd[p]=y;
}
in void push_down(re p) {if(inv[p]) adjust(ls(p)),adjust(rs(p)),inv[p]=0;}
void build(re p,re l,re r)
{
	if(l==r) return init(p,a[l],l),void();
	re mid=(l+r)>>1;
	build(ls(p),l,mid);build(rs(p),mid+1,r);
	push_up(p);
}
void inverse(re p,re l,re r,re nl,re nr)
{
	if(nl<=l&&r<=nr) return adjust(p),void();
	re mid=(l+r)>>1;push_down(p);
	if(nl<=mid) inverse(ls(p),l,mid,nl,nr);
	if(nr>mid) inverse(rs(p),mid+1,r,nl,nr);
	push_up(p);
}
void update(re p,re l,re r,re x,re y)
{
	if(l==r) return t[p]=mx[p]=mn[p]=lmn[p]=lmx[p]=rmn[p]=rmx[p]=y,inv[p]=0,void();
	re mid=(l+r)>>1;push_down(p);
	(x<=mid)?update(ls(p),l,mid,x,y):update(rs(p),mid+1,r,x,y); 
	push_up(p);
}
void query(re p,re l,re r,re ql,re qr,re &s,re &ls,re &rs,re &ld,re &rd,re &sl,re &sr,re &mp)
{
	if(ql<=l&&r<=qr) 
	{
		s=t[p],ls=lmx[p],rs=rmx[p],ld=lmxd[p],rd=rmxd[p],sl=mxl[p],sr=mxr[p],mp=mx[p];
		return;
	}
	re mid=(l+r)>>1,s1,s2,ls1,ls2,rs1,rs2,ld1,ld2,rd1,rd2,sl1,sl2,sr1,sr2,mp1,mp2;
	push_down(p);
	if(ql>mid) query(rs(p),mid+1,r,ql,qr,s,ls,rs,ld,rd,sl,sr,mp);
	else if(qr<=mid) query(ls(p),l,mid,ql,qr,s,ls,rs,ld,rd,sl,sr,mp);
	else
	{
		query(ls(p),l,mid,ql,qr,s1,ls1,rs1,ld1,rd1,sl1,sr1,mp1);
		query(rs(p),mid+1,r,ql,qr,s2,ls2,rs2,ld2,rd2,sl2,sr2,mp2);
		s=s1+s2;ls=max(ls1,s1+ls2);rs=max(rs2,s2+rs1);
		ld=(ls==ls1?ld1:ld2);rd=(rs==rs2?rd2:rd1);
		mp=max(max(mp1,mp2),rs1+ls2);
		sl=(mp==rs1+ls2?rd1:(mp==mp1?sl1:sl2));
		sr=(mp==rs1+ls2?ld2:(mp==mp1?sr1:sr2));
	}
}
int main()
{
	n=read();for(re i=1;i<=n;i++) a[i]=read();
	build(1,1,n);m=read();
	for(re i=1;i<=m;i++)
	{
		re op=read(),res=0;
		if(op)
		{
			re l=read(),r=read(),k=read(),s,ls,rs,ld,rd,sl,sr,ans;
			vector<pii>v;
			for(re j=1;j<=k;j++) 
			{
				query(1,1,n,l,r,s,ls,rs,ld,rd,sl,sr,ans);
				if(ans>0) v.emplace_back(sl,sr),res+=ans,inverse(1,1,n,sl,sr); 
				else break;
			}
			for(auto x:v) {re l=x.first,r=x.second;inverse(1,1,n,l,r);}
			write(res,'\n');
		}
		else {re x=read(),y=read();update(1,1,n,x,y);}
	}
	return ot(),0;
}