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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,p[300005],q[300005],s[300005],lst;
int mx[1200005],tag[1200005];
void upd(int x,int v)
{
	mx[x]+=v;tag[x]+=v;
}
void pushdo(int x)
{
	if(tag[x]){
		upd(x+x,tag[x]);
		upd(x+x+1,tag[x]);
		tag[x]=0;
	}
}
void update(int x,int l,int r,int ql,int qr,int v)
{
	if(ql<=l&&r<=qr){
		upd(x,v);
		return;
	}
	int mid=(l+r)/2;
	pushdo(x);
	if(ql<=mid) update(x+x,l,mid,ql,qr,v);
	if(qr>mid) update(x+x+1,mid+1,r,ql,qr,v);
	mx[x]=max(mx[x+x],mx[x+x+1]);
}
int main()
{
	read(n);
	fz1(i,n){
		int x;
		read(x);
		p[x]=i;
	}
	fz1(i,n) read(q[i]);
	j=0;
	fd1(i,n){
		update(1,1,n,1,p[i],1);
		while(j<n&&mx[1]>0){
			j++;
			s[j]=i;
			update(1,1,n,1,q[j],-1);
		}
	}
	fz1(i,n){
		printf("%d%c",s[i],spln(i,n));
	}
	return 0;
}