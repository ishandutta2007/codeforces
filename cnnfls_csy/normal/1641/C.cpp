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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
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
int n,m,i,j,c0[200005],c1[200005];
int op[200005],pl[200005],pr[200005],px[200005];
set<int> s;
struct seg{int mi,id,sec;}tr[800005];
seg merge(seg x,seg y)
{
	seg z;
	if(x.mi>y.mi) z.mi=x.mi,z.id=x.id,z.sec=max(x.sec,y.mi); else z.mi=y.mi,z.id=y.id,z.sec=max(y.sec,x.mi);
	return z;
}
void build(int x,int l,int r)
{
	if(l==r){tr[x]=(seg){c0[l],l,0};return;}
	int mid=(l+r)/2;build(x+x,l,mid);build(x+x+1,mid+1,r);
	tr[x]=merge(tr[x+x],tr[x+x+1]);
}
seg query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return tr[x];
	int mid=(l+r)/2;
	if(qr<=mid) return query(x+x,l,mid,ql,qr);
	if(ql>mid) return query(x+x+1,mid+1,r,ql,qr);
	return merge(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
}
int main()
{
	read(n);read(m);
	fz1(i,n) c0[i]=c1[i]=m+1,s.insert(i);
	fz1(i,m){
		read(op[i]);
		if(op[i]==0){
			read(pl[i]),read(pr[i]),read(px[i]);
			if(px[i]==0){
				set<int>::iterator it=s.lower_bound(pl[i]);
				while(it!=s.end()&&*it<=pr[i]){
					c0[*it]=i;it=s.erase(it);
				}
			}
		}
		else read(px[i]);
	}
	build(1,1,n);
	fz1(i,m){
		if(op[i]==0&&px[i]==1){
			seg tmp=query(1,1,n,pl[i],pr[i]);
			c1[tmp.id]=min(c1[tmp.id],tmp.sec);
		}
		if(op[i]==1){
			if(c0[px[i]]<=i&&c1[px[i]]<=i) assert(1064==822);
			else if(c0[px[i]]<=i) puts("NO");
			else if(c1[px[i]]<=i) puts("YES");
			else puts("N/A");
		}
	}
	return 0;
}