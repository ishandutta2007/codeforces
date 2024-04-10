#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=1e5+7;
const ll INF=1e9+7;
struct line{ll k,b;}s[N];
struct pt{ll x,y;}p[N];
bool cmp(pt a,pt b){if(a.x==b.x)return a.y<b.y; return a.x<b.x;}
ll n,tp=0;
bool gg(line a,line b,line c){
	ll fm=a.k-b.k,fz=b.b-a.b;
	if(fm<0)fm*=-1,fz*=-1;
	ll y1=fz*a.k+a.b*fm,y2=fz*c.k+c.b*fm;
	return y2>=y1;
}
ll fd(ll x){
	if(x>n)return x;
	while(p[x].x==p[x+1].x)x++;
	return x;
}
int main(){
	scanf("%I64d",&n);
	rep(i,n)scanf("%I64d%I64d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	for(ll i=fd(1);i<=n;i=fd(i+1)){
		if(!tp)s[++tp]=(line){-p[i].x,p[i].y-p[i].x*p[i].x};
		else{
			line q=(line){-p[i].x,p[i].y-p[i].x*p[i].x};
			while(tp>1)if(gg(s[tp],s[tp-1],q))tp--;else break;
			s[++tp]=q;
		}
	}
	printf("%I64d\n",tp-1);
	return 0;
}