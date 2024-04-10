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
int n,m,i,j,l,r,mid,ans;
struct ii{int x,y;}a[100005],b[100005],c[100005];
map<int,int> cntx,cnty;
int ca,cb,cc;
bool cmpx(ii x,ii y){return x.x<y.x;}
bool cmpy(ii x,ii y){return x.y<y.y;}
bool checkx(ii *a,ii *b,int x)
{
	sort(a+1,a+m+1,cmpx);
	sort(b+1,b+m+1,cmpx);
	int limx=-0x3f3f3f3f,cnt,f=1;
	cnt=0;fz1(i,m) if(a[i].x>=limx&&cnt<x) cnt++,limx=max(limx,a[i].x);if(cnt<x) return 0;
	cnt=0;fz1(i,m) if(b[i].x>=limx&&cnt<x) cnt++,limx=max(limx,b[i].x);if(cnt<x) return 0;
	return 1;
}
bool checky(ii *a,ii *b,int x)
{
	sort(a+1,a+m+1,cmpy);
	sort(b+1,b+m+1,cmpy);
	int limy=-0x3f3f3f3f,cnt,f=1;
	cnt=0;fz1(i,m) if(a[i].y>=limy&&cnt<x) cnt++,limy=max(limy,a[i].y);if(cnt<x) return 0;
	cnt=0;fz1(i,m) if(b[i].y>=limy&&cnt<x) cnt++,limy=max(limy,b[i].y);if(cnt<x) return 0;
	return 1;
}
bool checkx(ii *a,ii *b,ii *c,int x)
{
	int limx=-0x3f3f3f3f,cnt,f=1;
	cnt=0;fz1(i,m) if(a[i].x>=limx&&cnt<x) cnt++,limx=max(limx,a[i].x);if(cnt<x) return 0;
	limx++;
	cnt=0;fz1(i,m) if(b[i].x>=limx&&cnt<x) cnt++,limx=max(limx,b[i].x);if(cnt<x) return 0;
	limx++;
	cnt=0;fz1(i,m) if(c[i].x>=limx&&cnt<x) cnt++,limx=max(limx,c[i].x);if(cnt<x) return 0;
	return 1;
}
bool checky(ii *a,ii *b,ii *c,int x)
{
	int limy=-0x3f3f3f3f,cnt,f=1;
	cnt=0;fz1(i,m) if(a[i].y>=limy&&cnt<x) cnt++,limy=max(limy,a[i].y);if(cnt<x) return 0;
	limy++;
	cnt=0;fz1(i,m) if(b[i].y>=limy&&cnt<x) cnt++,limy=max(limy,b[i].y);if(cnt<x) return 0;
	limy++;
	cnt=0;fz1(i,m) if(c[i].y>=limy&&cnt<x) cnt++,limy=max(limy,c[i].y);if(cnt<x) return 0;
	return 1;
}
bool checkxy2(ii *a,ii *b,ii *c,int x)
{
	int limx=0x3f3f3f3f,limy=-0x3f3f3f3f,cnt,f=1;
	cnt=0;fd1(i,m) if(a[i].x<=limx&&cnt<x) cnt++,limx=min(limx,a[i].x);if(cnt<x) return 0;
	limx--;
	cnt=0;fz1(i,m) if(b[i].x<=limx&&b[i].y>=limy&&cnt<x) cnt++,limy=max(limy,b[i].y);if(cnt<x) return 0;
	limy++;
	cnt=0;fz1(i,m) if(c[i].x<=limx&&c[i].y>=limy&&cnt<x) cnt++,limy=max(limy,c[i].y);if(cnt<x) return 0;
	return 1;
}
bool checkxy(ii *a,ii *b,ii *c,int x)
{
	sort(a+1,a+m+1,cmpx);
	sort(b+1,b+m+1,cmpy);
	sort(c+1,c+m+1,cmpy);
	if(checkxy2(a,b,c,x)) return 1;
	int limx=-0x3f3f3f3f,limy=-0x3f3f3f3f,cnt,f=1;
	cnt=0;fz1(i,m) if(a[i].x>=limx&&cnt<x) cnt++,limx=max(limx,a[i].x);if(cnt<x) return 0;
	limx++;
	cnt=0;fz1(i,m) if(b[i].x>=limx&&b[i].y>=limy&&cnt<x) cnt++,limy=max(limy,b[i].y);if(cnt<x) return 0;
	limy++;
	cnt=0;fz1(i,m) if(c[i].x>=limx&&c[i].y>=limy&&cnt<x) cnt++,limy=max(limy,c[i].y);if(cnt<x) return 0;
	return 1;
}
bool checkyx2(ii *a,ii *b,ii *c,int x)
{
	int limx=-0x3f3f3f3f,limy=0x3f3f3f3f,cnt,f=1;
	cnt=0;fd1(i,m) if(a[i].y<=limy&&cnt<x) cnt++,limy=min(limy,a[i].y);if(cnt<x) return 0;
	limy--;
	cnt=0;fz1(i,m) if(b[i].x>=limx&&b[i].y<=limy&&cnt<x) cnt++,limx=max(limx,b[i].x);if(cnt<x) return 0;
	limx++;
	cnt=0;fz1(i,m) if(c[i].x>=limx&&c[i].y<=limy&&cnt<x) cnt++,limx=max(limx,c[i].x);if(cnt<x) return 0;
	return 1;
}
bool checkyx(ii *a,ii *b,ii *c,int x)
{
	sort(a+1,a+m+1,cmpy);
	sort(b+1,b+m+1,cmpx);
	sort(c+1,c+m+1,cmpx);
	if(checkyx2(a,b,c,x)) return 1;
	int limx=-0x3f3f3f3f,limy=-0x3f3f3f3f,cnt,f=1;
	cnt=0;fz1(i,m) if(a[i].y>=limy&&cnt<x) cnt++,limy=max(limy,a[i].y);if(cnt<x) return 0;
	limy++;
	cnt=0;fz1(i,m) if(b[i].x>=limx&&b[i].y>=limy&&cnt<x) cnt++,limx=max(limx,b[i].x);if(cnt<x) return 0;
	limx++;
	cnt=0;fz1(i,m) if(c[i].x>=limx&&c[i].y>=limy&&cnt<x) cnt++,limx=max(limx,c[i].x);if(cnt<x) return 0;
	return 1;
}
bool check(int x)
{
//	if(x<=ca&&x<=cb&&x<=cc) return 1;
//	if(x<=ca&&x<=cb) return 1;
//	if(x<=ca&&x<=cc) return 1;
//	if(x<=cb&&x<=cc) return 1;
	
//	if(x<=ca&&(checkx(b,c,x)||checky(b,c,x)||checkx(c,b,x)||checky(c,b,x))) return 1;
//	if(x<=cb&&(checkx(a,c,x)||checky(a,c,x)||checkx(c,a,x)||checky(c,a,x))) return 1;
//	if(x<=cc&&(checkx(a,b,x)||checky(a,b,x)||checkx(b,a,x)||checky(b,a,x))) return 1;
	
	sort(a+1,a+m+1,cmpx);
	sort(b+1,b+m+1,cmpx);
	sort(c+1,c+m+1,cmpx);
	if(checkx(a,b,c,x)) return 1;
	if(checkx(a,c,b,x)) return 1;
	if(checkx(b,a,c,x)) return 1;
	if(checkx(b,c,a,x)) return 1;
	if(checkx(c,a,b,x)) return 1;
	if(checkx(c,b,a,x)) return 1;
	
	sort(a+1,a+m+1,cmpy);
	sort(b+1,b+m+1,cmpy);
	sort(c+1,c+m+1,cmpy);
	if(checky(a,b,c,x)) return 1;
	if(checky(a,c,b,x)) return 1;
	if(checky(b,a,c,x)) return 1;
	if(checky(b,c,a,x)) return 1;
	if(checky(c,a,b,x)) return 1;
	if(checky(c,b,a,x)) return 1;
	
	if(checkxy(a,b,c,x)) return 1;
	if(checkxy(a,c,b,x)) return 1;
	if(checkxy(b,a,c,x)) return 1;
	if(checkxy(b,c,a,x)) return 1;
	if(checkxy(c,a,b,x)) return 1;
	if(checkxy(c,b,a,x)) return 1;
	
	if(checkyx(a,b,c,x)) return 1;
	if(checkyx(a,c,b,x)) return 1;
	if(checkyx(b,a,c,x)) return 1;
	if(checkyx(b,c,a,x)) return 1;
	if(checkyx(c,a,b,x)) return 1;
	if(checkyx(c,b,a,x)) return 1;
	
	return 0;
}
int main()
{
	read(n);m=n/3;int cca=0,ccb=0,ccc=0;
	fz1(i,n){
		int x,y,t;read(x);read(y);read(t);
		if(t==1)a[++cca]=(ii){x,y};
		if(t==2)b[++ccb]=(ii){x,y};
		if(t==3)c[++ccc]=(ii){x,y};
	}
	cntx.clear();cnty.clear();
	fz1(i,m){
		ca=max(ca,++cntx[a[i].x]);
		ca=max(ca,++cnty[a[i].y]);
	}
	cntx.clear();cnty.clear();
	fz1(i,m){
		cb=max(cb,++cntx[b[i].x]);
		cb=max(cb,++cnty[b[i].y]);
	}
	cntx.clear();cnty.clear();
	fz1(i,m){
		cc=max(cc,++cntx[c[i].x]);
		cc=max(cc,++cnty[c[i].y]);
	}
	l=1;r=n/3+1;
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;ans=mid;
		}
		else r=mid;
	}
	cout<<ans*3<<endl;
	return 0;
}