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
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int typ,n,m,i,j,k;
int a1[1000005],a2[1000005],qx[1000005],qy[1000005];
long long s1[1000005],s2[1000005],s0[1000005];
int pre0[1000005],pre1[1000005],pre2[1000005];
int suf0[1000005],suf1[1000005],suf2[1000005];
map<long long,int> lst;
struct ii{int val,pos;}f[1000005],g[1000005];
bool operator <(ii x,ii y){return x.val<y.val||(x.val==y.val&&x.pos>y.pos);}
void upd(int x,int y,int val)
{
	if(x>=y) f[x]=max(f[x],(ii){val,y});
	if(y>=x) g[y]=max(g[y],(ii){val,x});
}
void trans(int x,int y,int val)
{
	if(suf1[x]<=n&&suf1[x]<=suf2[y]){
		upd(suf1[x],y,val+1);
	}
	if(suf2[y]<=n&&suf2[y]<=suf1[x]){
		upd(x,suf2[y],val+1);
	}
	if(suf0[max(x,y)]<=n){
		upd(suf0[max(x,y)],suf0[max(x,y)],val+1);
	}
}
int main()
{
//	freopen("zero.in","r",stdin);freopen("zero.out","w",stdout);
	read(n);//read(typ);read(n);read(m);
	fz1(i,n)read(a1[i]);fz1(i,n)read(a2[i]);
	fz1(i,n) s1[i]=s1[i-1]+a1[i],s2[i]=s2[i-1]+a2[i],s0[i]=s0[i-1]+a1[i]+a2[i];
	fz0g(i,n) pre0[i]=pre1[i]=pre2[i]=-1;
	lst.clear();fd0g(i,n)pre0[suf0[i]=(lst.count(s0[i])?lst[s0[i]]:n+1)]=i,lst[s0[i]]=i;
	lst.clear();fd0g(i,n)pre1[suf1[i]=(lst.count(s1[i])?lst[s1[i]]:n+1)]=i,lst[s1[i]]=i;
	lst.clear();fd0g(i,n)pre2[suf2[i]=(lst.count(s2[i])?lst[s2[i]]:n+1)]=i,lst[s2[i]]=i;
	fz1(i,n)pre0[i]=max(pre0[i],pre0[i-1]),pre1[i]=max(pre1[i],pre1[i-1]),pre2[i]=max(pre2[i],pre2[i-1]);
	fd0k(i,n)suf0[i]=min(suf0[i],suf0[i+1]),suf1[i]=min(suf1[i],suf1[i+1]),suf2[i]=min(suf2[i],suf2[i+1]);

	f[0]=g[0]=(ii){0,0};
	fz0g(i,n){
		if(i) f[i]=max(f[i],f[i-1]),g[i]=max(g[i],g[i-1]);
		trans(i,f[i].pos,f[i].val);
		trans(g[i].pos,i,g[i].val);
//		cerr<<f[i].val<<' '<<g[i].val<<endl;
	}

	cout<<f[n].val<<endl;

	return 0;
}