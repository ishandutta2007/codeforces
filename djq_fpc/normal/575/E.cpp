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
int n,m,i,j;
const double eps=1e-9;
struct ii
{
	int x,y;
};
ii operator -(ii x,ii y)
{
	return (ii){x.x-y.x,x.y-y.y};
} 
bool cmp(ii x,ii y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
int dis(ii x,ii y)
{
	return abs(x.x-y.x)+abs(x.y-y.y);
}
double dis2(ii x,ii y)
{
	return sqrt(1.0*(x.x-y.x)*(x.x-y.x)+1.0*(x.y-y.y)*(x.y-y.y));
}
long long crs(ii x,ii y)
{
	return 1ll*x.x*y.y-1ll*x.y*y.x;
}
vector<ii> all,cov;
ii stk[2000005];int tp;
void update1(ii x)
{
	if(0<=x.x&&x.x<=100000&&0<=x.y&&x.y<=100000) all.push_back(x);
}
void update2(ii p,int r,ii x)
{
	if(dis(p,x)<=r) all.push_back(x);
}
int main()
{
	read(n);
	for(i=1;i<=n;i++){
		int x,y,r;
		read(x);read(y);read(r);
		if(x+r<=100000) update1((ii){x+r,y});
		else{
			update1((ii){100000,y-(r-(100000-x))});
			update1((ii){100000,y+(r-(100000-x))});
		}
		if(x-r>=0) update1((ii){x-r,y});
		else{
			update1((ii){0,y-(r-x)});
			update1((ii){0,y+(r-x)});
		}
		if(y+r<=100000) update1((ii){x,y+r});
		else{
			update1((ii){x-(r-(100000-y)),100000});
			update1((ii){x+(r-(100000-y)),100000});
		}
		if(y-r>=0) update1((ii){x,y-r});
		else{
			update1((ii){x-(r-y),0});
			update1((ii){x+(r-y),0});
		}
		update2((ii){x,y},r,(ii){0,0});
		update2((ii){x,y},r,(ii){0,100000});
		update2((ii){x,y},r,(ii){100000,0});
		update2((ii){x,y},r,(ii){100000,100000});
	}
	sort(all.begin(),all.end(),cmp);
	stk[tp=1]=all[0];
	for(i=1;i<all.size();i++){
		if(all[i].x==all[i-1].x&&all[i].y==all[i-1].y) continue;
		while(tp>1&&crs(stk[tp]-stk[tp-1],all[i]-stk[tp])>=0) tp--;
		stk[++tp]=all[i];
	}
	for(i=1;i<tp;i++) cov.push_back(stk[i]);
	reverse(all.begin(),all.end());
	stk[tp=1]=all[0];
	for(i=1;i<all.size();i++){
		if(all[i].x==all[i-1].x&&all[i].y==all[i-1].y) continue;
		while(tp>1&&crs(stk[tp]-stk[tp-1],all[i]-stk[tp])>=0) tp--;
		stk[++tp]=all[i];
	}
	for(i=1;i<tp;i++) cov.push_back(stk[i]);
	double ans=-1e18;int res=0;
	for(i=0;i<cov.size();i++){
		int j=(i+1)%cov.size();
		int k=(i+2)%cov.size();
		double tmp=dis2(cov[i],cov[j])*dis2(cov[i],cov[k])*dis2(cov[j],cov[k])/4/abs(crs(cov[j]-cov[i],cov[k]-cov[i])/2.0);
		if(tmp>ans){
			ans=tmp;res=i;
		}
	}
	printf("%d %d\n",cov[res].x,cov[res].y);
	printf("%d %d\n",cov[(res+1)%cov.size()].x,cov[(res+1)%cov.size()].y);
	printf("%d %d\n",cov[(res+2)%cov.size()].x,cov[(res+2)%cov.size()].y);
	return 0;
}