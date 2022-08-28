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
int n,m,i,j,a[300005];
vector<int> bi[300005],pos[300005];
struct ii
{
	int x,y;
}tr[1200005];
ii merge(ii x,ii y)
{
	if(x.x==y.x){
		return (ii){x.x,x.y+y.y};
	}
	if(x.y<y.y) return (ii){y.x,y.y-x.y};
	return (ii){x.x,x.y-y.y};
}
void build(int x,int l,int r)
{
	if(l==r){
		tr[x]=(ii){a[l],1};
		return;
	}
	int mid=(l+r)/2;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
	tr[x]=merge(tr[x+x],tr[x+x+1]);
}
ii query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr){
		return tr[x];
	}
	int mid=(l+r)/2;
	if(qr<=mid) return query(x+x,l,mid,ql,qr);
	if(ql>mid) return query(x+x+1,mid+1,r,ql,qr);
	return merge(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
}
int main()
{
	read(n);read(m);
	fz1(i,n){
		read(a[i]);
		pos[a[i]].push_back(i);
	}
	build(1,1,n);
	while(m--){
		int l,r;
		read(l);read(r);
		int len=r-l+1;
		int s=query(1,1,n,l,r).x;
		s=upper_bound(pos[s].begin(),pos[s].end(),r)-lower_bound(pos[s].begin(),pos[s].end(),l);
		printf("%d\n",max(1,s-(len-s)));
	}
	return 0;
}