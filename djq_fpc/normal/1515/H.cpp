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
const int lim=(1<<20)-1;
int n,q,i,j,rt,cnt;
int lc[16000005],rc[16000005];
int tagx[16000005];
int sz[16000005],f[16000005][2];
vector<pair<int,pair<int,int> > > v;
void pushup(int x,int d)
{
	sz[x]=sz[lc[x]]+sz[rc[x]];
	f[x][0]=f[lc[x]][0]|f[rc[x]][0];
	f[x][1]=f[lc[x]][1]|f[rc[x]][1];
	if(sz[lc[x]]==0) lc[x]=0;
	if(sz[rc[x]]==0) rc[x]=0;
	if(lc[x]) f[x][0]|=(1<<d);
	if(rc[x]) f[x][1]|=(1<<d);
	if(sz[x]&&!(f[x][0]||f[x][1])){
		int a;
		a++;
	}
}
void update(int &x,int l,int r,int d,int y)
{
	if(!x){
		x=++cnt;
	}
	if(l==r){
		sz[x]=1;
		f[x][0]|=(lim^y);
		f[x][1]|=y;
		return;
	}
	int mid=(l+r)/2;
	if(y<=mid) update(lc[x],l,mid,d-1,y); else update(rc[x],mid+1,r,d-1,y);
	pushup(x,d);
}
void merge(int &x,int y,int d); 
void updx(int x,int d,int t)
{
	if(d==-1) return; 
	int tt=((f[x][0]^f[x][1])&t);
	f[x][0]^=tt;f[x][1]^=tt;
	tagx[x]^=t;
	if(((t>>d)&1)){
		swap(lc[x],rc[x]);
	}
}
void pushdo(int x,int d)
{
	if(lc[x]){
		if(tagx[x]!=0) updx(lc[x],d-1,tagx[x]);
	}
	if(rc[x]){
		if(tagx[x]!=0) updx(rc[x],d-1,tagx[x]);
	}
	tagx[x]=0;
}
void upda(int x,int k,int d)
{
	if(!x||!((f[x][1]>>k)&1)) return;
	if(!((f[x][0]>>k)&1)){
		updx(x,d,(1<<k));
		return;
	}
	pushdo(x,d);
	if(d==k){
		merge(lc[x],rc[x],d-1);
		rc[x]=0;
		pushup(x,d);
		return;
	}
	upda(lc[x],k,d-1);
	upda(rc[x],k,d-1);
	pushup(x,d);
}
void updo(int x,int k,int d)
{
	if(!x||!((f[x][0]>>k)&1)) return;
	if(!((f[x][1]>>k)&1)){
		updx(x,d,(1<<k));
		return;
	}
	pushdo(x,d);
	if(d==k){
		merge(rc[x],lc[x],d-1);
		lc[x]=0;
		pushup(x,d);
		return;
	}
	updo(lc[x],k,d-1);
	updo(rc[x],k,d-1);
	pushup(x,d);
}
void merge(int &x,int y,int d)
{
	if(!x||!y){
		x=x+y;
		return;
	}
	if(d==-1){
		sz[x]=1;
		return;
	}
	pushdo(x,d);
	pushdo(y,d);
	merge(lc[x],lc[y],d-1);
	merge(rc[x],rc[y],d-1); 
	pushup(x,d);
}
int count(int x,int l,int r,int d,int ql,int qr)
{
	if(!x) return 0;
	if(ql<=l&&r<=qr){
		return sz[x];
	}
	pushdo(x,d);
	int mid=(l+r)/2,s=0;
	if(ql<=mid) s+=count(lc[x],l,mid,d-1,ql,qr);
	if(qr>mid) s+=count(rc[x],mid+1,r,d-1,ql,qr);
	return s;
}
void pushin(int &x,int l,int r,int d,int ql,int qr)
{
	if(!x) return;
	if(ql<=l&&r<=qr){
		v.push_back(make_pair(x,mk(l,r)));
		x=0;return;
	}
	pushdo(x,d);
	int mid=(l+r)/2;
	if(ql<=mid) pushin(lc[x],l,mid,d-1,ql,qr);
	if(qr>mid) pushin(rc[x],mid+1,r,d-1,ql,qr);
	pushup(x,d);
}
void retin(int &x,int l,int r,int d,int ql,int qr,int y)
{
	if(!x){
		x=++cnt;
	}
	if(ql==l&&r==qr){
		merge(x,y,d);
		return;
	}
	pushdo(x,d);
	int mid=(l+r)/2;
	if(ql<=mid) retin(lc[x],l,mid,d-1,ql,qr,y);
	if(qr>mid) retin(rc[x],mid+1,r,d-1,ql,qr,y);
	pushup(x,d);
}
int main()
{
	read(n);read(q);
	fz1(i,n){
		int x;
		read(x);
		update(rt,0,lim,19,x);
	}
	while(q--){
		int op,l,r;
		read(op);read(l);read(r);
		if(op==4){
			printf("%d\n",count(rt,0,lim,19,l,r));
			continue;
		}
		v.clear();
		pushin(rt,0,lim,19,l,r);
		int val;read(val);
		ff(v,it){
			int l=it->se.fi,r=it->se.se,x=it->fi;
			for(i=19;i>=0;i--){
				if(((l>>i)&1)==((r>>i)&1)){
					if(op==1){
						l&=(lim^(1<<i)^((1<<i)&val));
						r&=(lim^(1<<i)^((1<<i)&val));
					}
					if(op==2){
						l|=((1<<i)&val);
						r|=((1<<i)&val);
					}
					if(op==3){
						l^=((1<<i)&val);
						r^=((1<<i)&val);
					}
				}
				else break;
			}
			if(op==1){
				fz0k(j,20) if(!((val>>j)&1))upda(x,j,i);
			}
			if(op==2){
				fz0k(j,20) if(((val>>j)&1))updo(x,j,i);
			}
			if(op==3) updx(x,i,val);
			retin(rt,0,lim,19,l,r,x);
		}
	}
	return 0;
}