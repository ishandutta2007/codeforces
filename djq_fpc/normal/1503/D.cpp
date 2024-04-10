#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,ans=0x3f3f3f3f;
struct ii
{
	int a,b,dlt,l,r;
}a[200005];
bool cmp(ii x,ii y)
{
	if(x.dlt==y.dlt) return x.l<y.l;
	return x.dlt<y.dlt;
}
struct seg
{
	int mi[1600005];
	void build(int n)
	{
		int i;
		fz1(i,n*4) mi[i]=0x3f3f3f3f;
	}
	void update(int x,int l,int r,int y,int c)
	{
		if(l==r){
			mi[x]=c;return;
		}
		int mid=(l+r)/2;
		if(y<=mid)update(x+x,l,mid,y,c);else update(x+x+1,mid+1,r,y,c);
		mi[x]=min(mi[x+x],mi[x+x+1]);
	}
	int query(int x,int l,int r,int ql,int qr)
	{
		if(ql>qr) return 0x3f3f3f3f;
		if(ql<=l&&r<=qr){
			return mi[x];
		}
		int mid=(l+r)/2,s=0x3f3f3f3f;
		if(ql<=mid)s=min(s,query(x+x,l,mid,ql,qr));
		if(qr>mid)s=min(s,query(x+x+1,mid+1,r,ql,qr));
		return s;
	}
}tr1,tr2;
int find_fir(int l,int r,int lim)
{
	int s1=tr1.query(1,1,n+n,l+1,n+n);
	while(s1<lim){
		tr1.update(1,1,n+n,a[s1].l,0x3f3f3f3f);
		s1=tr1.query(1,1,n+n,l+1,n+n);
	}
	int s2=tr2.query(1,1,n+n,1,r-1);
	while(s2<lim){
		tr2.update(1,1,n+n,a[s2].r,0x3f3f3f3f);
		s2=tr2.query(1,1,n+n,1,r-1);
	}
	return min(s1,s2);
}
void solve()
{
	tr1.build(n+n);tr2.build(n+n);
	int i,j,res=0,lst=0,cur=0;
	fz1(i,n){
		tr1.update(1,1,n+n,a[i].l,i);
		tr2.update(1,1,n+n,a[i].r,i);
	}
	int l1=a[1].a,r1=a[1].b;
	int l2=r1,r2=l1;
	for(i=2;i<=n;i++){
		int t1=find_fir(l1,r1,i);
		int t2=find_fir(l2,r2,i);
		if(t1<=n||t2<=n){
			if(t1==t2) return;
			int tt=min(t1,t2);
			if(t2<t1){
				for(j=i;j<t1&&j<t2;j++){
					if(a[j].l>l2||a[j].r<r2) return;
					if(a[j].a<a[j].b) cur++;
					l2=min(a[j].a,a[j].b);r2=max(a[j].a,a[j].b);
				}
				if(a[tt].a>a[tt].b) cur++;
				l1=min(a[tt].a,a[tt].b);r1=max(a[tt].a,a[tt].b);
			}
			else{
				for(j=i;j<t1&&j<t2;j++){
					if(a[j].l>l1||a[j].r<r1) return;
					if(a[j].a>a[j].b) cur++;
					l1=min(a[j].a,a[j].b);r1=max(a[j].a,a[j].b);
				}
				if(a[tt].a<a[tt].b) cur++;
				l2=min(a[tt].a,a[tt].b);r2=max(a[tt].a,a[tt].b);
			}
			i=tt;
		}
		else{
			res+=min(cur,i-1-lst-cur);
			lst=i-1;cur=0;
			l1=a[i].l;r1=a[i].r;
			if(a[i].a>a[i].b){
				cur++;
			}
		}
	}
	res+=min(cur,n-lst-cur);
	ans=min(ans,res);
}
int main()
{
	read(n);
	fz1(i,n){
		read(a[i].a);
		read(a[i].b);
		a[i].l=min(a[i].a,a[i].b);
		a[i].r=max(a[i].a,a[i].b);
		a[i].dlt=abs(a[i].a-a[i].b);
	}
	sort(a+1,a+n+1,cmp);
	solve();
	if(ans<0x3f3f3f3f)cout<<ans<<endl; else puts("-1"); 
	return 0;
}