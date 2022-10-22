#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e4+7;
const ll INF=1e9+7;
const ll T=1e9+7;
const db eps=1e-9;
db gg=-10;
ll n,m,sd=0,tot=0;
struct pir{ll x,y;}p1[N],p2[N],s[N];
struct frac{
	ll x,y;
	friend bool operator < (frac a,frac b){
		if(a.y<0)a.x*=-1,a.y*=-1;
		if(b.y<0)b.y*=-1,b.x*=-1;
		if((a.x<0)^(b.x<0))return a.x<b.x;
		bool fl=(a.x<0);
		a.x=abs(a.x);
		b.x=abs(b.x);
		ll u1=a.x/T,u2=a.x%T,v1=b.y/T,v2=b.y%T;
		ll g1=a.y/T,g2=a.y%T,h1=b.x/T,h2=b.x%T;
		ll d1=u2*v2%T,d2=(u2*v2/T)+u1*v2+u2*v1;
		ll d3=d2/T+u1*v1;
		d2%=T;
		ll e1=g2*h2%T,e2=(g2*h2/T)+g1*h2+g2*h1;
		ll e3=e2/T+g1*h1;
		e2%=T;
		if(d3!=e3)return (d3<e3)^fl;
		if(d2!=e2)return (d2<e2)^fl;
		return (d1<e1)^fl;
	}
};

bool check(pir *a,pir *b,ll x,ll y,ll nn,ll mm){
	db mx=-INF,mi=INF;
	rep(i,nn){
		if(i==x||i==y)continue;
		ll ux=a[x].x-a[i].x,uy=a[x].y-a[i].y;
		ll vx=a[y].x-a[i].x,vy=a[y].y-a[i].y;
		ll s=ux*vy-uy*vx,c=ux*vx+uy*vy;
		if(!s)continue;
		if(s>0)mx=max(mx,(db)c/sqrt(ux*ux+uy*uy)/sqrt(vx*vx+vy*vy));
		else mi=min(mi,-(db)c/sqrt(ux*ux+uy*uy)/sqrt(vx*vx+vy*vy));
	}
	if(mi<mx-eps)return 0;
	rep(i,mm){
		ll ux=a[x].x-b[i].x,uy=a[x].y-b[i].y;
		ll vx=a[y].x-b[i].x,vy=a[y].y-b[i].y;
		ll s=ux*vy-uy*vx,c=ux*vx+uy*vy;
		if(!s){
			if(b[i].x<a[x].x&&b[i].x>a[y].x)return 0;
			if(b[i].x>a[x].x&&b[i].x<a[y].x)return 0;
			if(b[i].y<a[x].y&&b[i].y>a[y].y)return 0;
			if(b[i].y>a[x].y&&b[i].y<a[y].y)return 0;
			continue;
		}
		if(s>0)mi=min(mi,(db)c/sqrt(ux*ux+uy*uy)/sqrt(vx*vx+vy*vy));
		else mx=max(mx,-(db)c/sqrt(ux*ux+uy*uy)/sqrt(vx*vx+vy*vy));
		if(mi<mx-eps)return 0;
	}
	if(mx<mi-eps)return 1;
	frac mxx=(frac){-INF,1},mii=(frac){INF,1};
	rep(i,nn){
		if(i==x||i==y)continue;
		ll ux=a[x].x-a[i].x,uy=a[x].y-a[i].y;
		ll vx=a[y].x-a[i].x,vy=a[y].y-a[i].y;
		ll s=ux*vy-uy*vx,c=ux*vx+uy*vy;
		if(!s)continue;
		if(s>0)mxx=max(mxx,(frac){c*abs(c),(ux*ux+uy*uy)*(vx*vx+vy*vy)});
		else mii=min(mii,(frac){-c*abs(c),(ux*ux+uy*uy)*(vx*vx+vy*vy)});
	}
	if(mii<mxx)return 0;
	rep(i,mm){
		ll ux=a[x].x-b[i].x,uy=a[x].y-b[i].y;
		ll vx=a[y].x-b[i].x,vy=a[y].y-b[i].y;
		ll s=ux*vy-uy*vx,c=ux*vx+uy*vy;
		if(!s){
			if(b[i].x<a[x].x&&b[i].x>a[y].x)return 0;
			if(b[i].x>a[x].x&&b[i].x<a[y].x)return 0;
			if(b[i].y<a[x].y&&b[i].y>a[y].y)return 0;
			if(b[i].y>a[x].y&&b[i].y<a[y].y)return 0;
			continue;
		}
		if(s>0)mii=min(mii,(frac){c*abs(c),(ux*ux+uy*uy)*(vx*vx+vy*vy)});
		else mxx=max(mxx,(frac){-c*abs(c),(ux*ux+uy*uy)*(vx*vx+vy*vy)});
		if(i%5==0)if(mii<mxx)return 0;
	}
	return mxx<mii;
}
pir hh;
bool cmp(pir u,pir v){
	ll x1=u.x-hh.x,x2=v.x-hh.x,y1=u.y-hh.y,y2=v.y-hh.y;
	if(!x1){
		if(!x2)return y1>y2;
		return 1;
	}
	if(!x2)return 0;
	if(x1*y2!=x2*y1)return x2*y1>x1*y2;
	if(x1!=x2)return x1>x2;
	return y1>y2;
}
ll cross(pir u,pir v,pir w){
	ll x1=v.x-u.x,x2=w.x-u.x,y1=v.y-u.y,y2=w.y-u.y;
	return x1*y2-x2*y1;
}
ll p[N];
bool fl;
void solve(pir *g,ll l,ll r,ll sz,pir *u1,pir *u2,ll nn,ll mm){
	if(check(g,u2,l,r,sz,mm)){
		fl=1;
		return;
	}
	if(l==r-1||(l==sz&&r==1))return;
	frac mx=(frac){-INF,1};
	ll id=0;
	REP(i,l+1,r-1){
		ll x1=g[l].x-g[i].x,x2=g[r].x-g[i].x,y1=g[l].y-g[i].y,y2=g[r].y-g[i].y;
		ll c=x1*x2+y1*y2;
		frac u=(frac){c*abs(c),(x1*x1+y1*y1)*(x2*x2+y2*y2)};
		if(mx<u){
			mx=u;
			id=i;
		}
	}
	solve(g,l,id,sz,u1,u2,nn,mm);
	if(fl)return;
	solve(g,id,r,sz,u1,u2,nn,mm);
}
bool check2(pir *a,pir *b,ll nn,ll mm){
	REP(i,2,nn)if(a[i].x<a[1].x||(a[i].x==a[1].x&&a[i].y<a[1].y))swap(a[1],a[i]);
	hh=a[1];
	sort(a+2,a+nn+1,cmp);
	ll tp=1;
	s[1]=a[1];
	p[1]=1;
	REP(i,2,nn){
		if(i>2&&cross(a[1],a[i-1],a[i])==0)continue;
		while(tp>1&&cross(s[tp-1],s[tp],a[i])>=0)tp--;
		s[++tp]=a[i];
		p[tp]=i;
	}
	fl=0;
	solve(s,1,tp,tp,a,b,nn,mm);
	return fl;
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	rep(i,n)scanf("%I64d%I64d",&p1[i].x,&p1[i].y);
	rep(i,m)scanf("%I64d%I64d",&p2[i].x,&p2[i].y);
	if(n==1||m==1){
		puts("Yes");
		return 0;
	}
	if(check2(p1,p2,n,m))puts("Yes");
	else if(check2(p2,p1,m,n))puts("Yes");
	else puts("No");
	return 0;
}