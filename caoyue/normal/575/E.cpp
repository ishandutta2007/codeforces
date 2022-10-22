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
const ll N=1e6+7;
const ll INF=1e9+7;
const ll C=100000;
struct pt{ll x,y;}p[N],s[N];
ll n,cnt=0,tp=1;
pt P1,P2,P3;
db R=0;
pt hh;
bool cmp(pt a,pt b){
	ll x1=a.x-hh.x,x2=b.x-hh.x,y1=a.y-hh.y,y2=b.y-hh.y;
	if(!x1){
		if(!x2)return y1>y2;
		return 1;
	}
	if(!x2)return 0;
	ll t=x2*y1-x1*y2;
	if(t)return t>0;
	if(x1!=x2)return x1>x2;
	return y1>y2;
}
ll cross(pt a,pt b,pt c){
	ll x1=b.x-a.x,x2=c.x-a.x,y1=b.y-a.y,y2=c.y-a.y;
	return x1*y2-x2*y1;
}
db dis(pt u,pt v){return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));} 
void calc(pt a,pt b,pt c){
	db l1=dis(a,c),l2=dis(b,c),l3=dis(a,b);
	assert(cross(a,b,c));
	db rr=l1*l2*l3/abs((a.y-b.y)*(c.x-b.x)-(a.x-b.x)*(c.y-b.y));
	if(rr>R){
		R=rr;
		P1=a;
		P2=b;
		P3=c;
	}
}
void solve(ll l,ll r){
	if(l==r-1)return;
	db Mx=-INF;
	ll id;
	REP(j,l+1,r-1){
		ll x1=s[l].x-s[j].x,x2=s[r].x-s[j].x,y1=s[l].y-s[j].y,y2=s[r].y-s[j].y;
		ll c=x1*x2+y1*y2;
		db v=(db)c*abs(c)/(x1*x1+y1*y1)/(x2*x2+y2*y2);
		if(v>Mx){
			Mx=v;
			id=j;
		}
	}
	calc(s[l],s[id],s[r]);
	solve(l,id);
	solve(id,r);
}
void work(){
	REP(i,2,cnt)if(p[i].x<p[1].x||(p[i].x==p[1].x&&p[i].y<p[1].y))swap(p[1],p[i]);
	hh=s[1]=p[1];
	int XX,YY;
	REP(i,2,cnt)if(p[i].x!=p[1].x||p[i].y!=p[1].y)XX=p[i].x,YY=p[i].y;
	REP(i,2,cnt)if(p[i].x==p[1].x&&p[i].y==p[1].y)p[i]=(pt){XX,YY};
	sort(p+2,p+cnt+1,cmp);
	REP(i,2,cnt){
		if(i>2)if(!cross(p[1],p[i-1],p[i]))continue;
		while(tp>1&&cross(s[tp-1],s[tp],p[i])>=0)tp--;
		s[++tp]=p[i];
	}
	solve(1,tp);
}
int main(){
	scanf("%lld",&n);
	rep(i,n){
		ll x,y,v; scanf("%lld%lld%lld",&x,&y,&v);
		if(x-v>=0)p[++cnt]=(pt){x-v,y};
		else{
			if(x+y<=v)p[++cnt]=(pt){0,0};
			else p[++cnt]=(pt){0,y-v+x};
			if(x+C-y<=v)p[++cnt]=(pt){0,C};
			else p[++cnt]=(pt){0,y+v-x};
		}
		if(y-v>=0)p[++cnt]=(pt){x,y-v};
		else{
			if(x+y>v)p[++cnt]=(pt){x-v+y,0};
			if(y+C-x<=v)p[++cnt]=(pt){C,0};
			else p[++cnt]=(pt){x+v-y,0};
		}
		if(x+v<=C)p[++cnt]=(pt){x+v,y};
		else{
			if(C-x+y>v)p[++cnt]=(pt){C,C-x+y-v};
			if(C+C-x-y<=v)p[++cnt]=(pt){C,C};
			else p[++cnt]=(pt){C,y+v-C+x};
		}
		if(y+v<=C)p[++cnt]=(pt){x,y+v};
		else{
			if(C-y+x>v)p[++cnt]=(pt){x+C-y-v,C};
			if(C+C-x-y>v)p[++cnt]=(pt){x+v+y-C,C};
		}
	}
	work();
	printf("%lld %lld\n",P1.x,P1.y);
	printf("%lld %lld\n",P2.x,P2.y);
	printf("%lld %lld\n",P3.x,P3.y);
	return 0;
}