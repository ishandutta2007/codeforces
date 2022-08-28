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
int n,m,i,j,a[200005],rnd[200005],lc[200005],rc[200005],s[200005],tags[200005],taga[200005],rt;
struct ii
{
	int c,q;
}b[200005];
bool cmp(ii x,ii y)
{
	if(x.q==y.q) return x.c<y.c;
	return x.q>y.q;
}
void upd(int x,int ds,int da)
{
	a[x]-=da;taga[x]+=da;
	s[x]+=ds;tags[x]+=ds;
}
void pushdo(int x)
{
	if(tags[x]||taga[x]){
		if(lc[x]) upd(lc[x],tags[x],taga[x]);
		if(rc[x]) upd(rc[x],tags[x],taga[x]);
		tags[x]=taga[x]=0;
	}
} 
void split(int x,int y,int &l,int &r)
{
	if(!x){
		l=r=0;
		return;
	}
	pushdo(x);
	if(a[x]<=y){
		l=x;
		split(rc[x],y,rc[x],r);
	}
	else{
		r=x;
		split(lc[x],y,l,lc[x]);
	}
}
int merge(int x,int y)
{
	if(!x||!y)return x+y;pushdo(x);pushdo(y);
	if(rnd[x]>rnd[y]){
		rc[x]=merge(rc[x],y);return x;
	}
	else{
		lc[y]=merge(x,lc[y]);return y;
	}
}
vector<int> va,vb,vc;
void dfs(int x)
{
	if(!x) return;
	pushdo(x);if(lc[x])dfs(lc[x]);if(rc[x]) dfs(rc[x]);
}
void tov(int x,vector<int> &a)
{
	if(!x) return;
	pushdo(x);
	if(lc[x]) tov(lc[x],a);
	a.push_back(x);
	if(rc[x]) tov(rc[x],a);
	lc[x]=rc[x]=0; 
}
int main()
{
	read(n);
	fz1(i,n){
		read(b[i].c);read(b[i].q);
	}sort(b+1,b+n+1,cmp);
	read(m);
	fz1(i,m){
		read(a[i]);
		rnd[i]=rand()*32768+rand();
		int t1,t2;
		split(rt,a[i],t1,t2);
		rt=merge(merge(t1,i),t2);
	}//if(n==100)printf("%d\n",a[1]);
	fz1(i,n){
		int t=b[i].c;int t1,t2,t3,t4,t5,t6;
		split(rt,t-1,t1,t2);
		upd(t2,1,t);
		split(t2,t+t-1,t3,t4);
		vb.clear();
		tov(t3,vb);
		ff(vb,it){
			split(t1,a[*it],t5,t6);
			t1=merge(merge(t5,*it),t6);
		}
		rt=merge(t1,t4);
	}dfs(rt);fz1(i,m){
		printf("%d ",s[i]);
	}
	return 0;
}