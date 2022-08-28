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
#define int long long
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int t,n,m,i,j,a[100005];
int mi[400005],tag[400005];
void upd(int x,int c)
{
	mi[x]+=c;tag[x]+=c;
}
void pushdo(int x)
{
	if(tag[x]){
		upd(x+x,tag[x]);
		upd(x+x+1,tag[x]);
		tag[x]=0;
	}
}
void pushup(int x)
{
	mi[x]=min(mi[x+x],mi[x+x+1]);
}
void update(int x,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr){upd(x,c);return;}
	int mid=(l+r)/2;pushdo(x);
	if(ql<=mid) update(x+x,l,mid,ql,qr,c);
	if(qr>mid) update(x+x+1,mid+1,r,ql,qr,c);
	pushup(x);
}
vector<int> b[100005];
int sb[100005];
void solve()
{
	read(n);read(m);
	fz1(i,n) read(a[i]),update(1,1,100000,1,a[i],1);
	fz1(i,m){
		sb[i]=0;b[i].clear();int num;read(num);
		while(num--){int x;read(x);b[i].push_back(x);sb[i]+=x;}
		update(1,1,100000,1,(sb[i]-1)/b[i].size()+1,-1);
	}
	fz1(i,m){
		update(1,1,100000,1,(sb[i]-1)/b[i].size()+1,1);
		ff(b[i],it){
			update(1,1,100000,1,(sb[i]-*it-1)/(b[i].size()-1)+1,-1);
			if(mi[1]>=0) putchar('1'); else putchar('0');
			update(1,1,100000,1,(sb[i]-*it-1)/(b[i].size()-1)+1,1);
		}
		update(1,1,100000,1,(sb[i]-1)/b[i].size()+1,-1);
	}
	fz1(i,n) update(1,1,100000,1,a[i],-1);
	fz1(i,m) update(1,1,100000,1,(sb[i]-1)/b[i].size()+1,1);
	puts("");
}
signed main()
{
	read(t);
	while(t--) solve();
	return 0;
}