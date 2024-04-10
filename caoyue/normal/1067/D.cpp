#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const ll INF=1e18+7;
const db eps=1e-10;
db p[N],vm[N];
ll a[N],b[N];
db maxn=0;
ll n,m=0,sz=1,t;
struct fac{db k,b;}f[N],dd[N],st[N];
bool cmp(fac x,fac y){return x.k<y.k;}
db meet(fac u,fac v){return (u.b-v.b)/(v.k-u.k);}
db ans[4][4],now[44][4][4],rp[4][4],cr3[4][4];
void cf(db cr0[4][4],db cr1[4][4],db cr2[4][4]){
	rep(i,3){
		rep(j,3){
			cr3[i][j]=0;
			rep(k,3)cr3[i][j]+=cr1[i][k]*cr2[k][j];
		}
	}
	rep(i,3)rep(j,3)cr0[i][j]=cr3[i][j];
}
db check(db q,ll t,db p[4][4]){return q*p[1][1]+t*p[1][2]+p[1][3];}
void work(fac v,ll &nw,db &dp,db R){
	if(nw==t)return;
	if(nw*maxn-dp>=R)return;
	now[0][1][1]=1-v.k;
	now[0][1][2]=v.k*maxn;
	now[0][1][3]=v.b;
	now[0][2][2]=now[0][2][3]=now[0][3][3]=1;
	now[0][2][1]=now[0][3][1]=now[0][3][2]=0;
	memset(ans,0,sizeof(ans));
	ll i=0,cs=0;
	for(;maxn*((1ll<<i)+nw)-check(dp,nw,now[i])<=R&&nw+(1ll<<i)<t;i++)cf(now[i+1],now[i],now[i]);
	rep(i,3)ans[i][i]=1;
	for(;~i;i--){
		rep(j,3)rep(k,3)rp[j][k]=ans[j][k];
		cf(ans,ans,now[i]);
		if((nw+cs+(1ll<<i))*maxn-check(dp,nw,ans)<=R&&nw+cs+(1ll<<i)<t)cs+=(1ll<<i);
		else rep(j,3)rep(k,3)ans[j][k]=rp[j][k];
	}
	cf(ans,ans,now[0]);
	db an=dp*ans[1][1]+nw*ans[1][2]+ans[1][3];
	dp=an;
	nw+=cs+1;
}
int main(){
	scanf("%I64d%I64d",&n,&t);
	rep(i,n)scanf("%I64d%I64d%lf",&a[i],&b[i],&p[i]);
	rep(i,n)f[i]=(fac){p[i],p[i]*a[i]};
	rep(i,n)maxn=max(maxn,b[i]*p[i]);
	sort(f+1,f+n+1,cmp);
	dd[++m]=f[1];
	REP(i,2,n){
		if(f[i].k>f[i-1].k+eps||f[i].k<f[i-1].k-eps)dd[++m]=f[i];
		else dd[m].b=max(dd[m].b,f[i].b);
	}
	rep(i,m)f[i]=dd[i];
	st[1]=f[1];
	rep(i,m){	
		while(sz>1){
			db r1=meet(st[sz-1],f[i]),r2=meet(st[sz],f[i]);
			if(r1<r2)break;
			sz--;
		}
		st[++sz]=f[i];
	}
	rep(i,sz-1)vm[i]=meet(st[i],st[i+1]);
	vm[sz]=INF;
	ll nw=0;
	db dp=0;
	rep(i,sz)work(st[i],nw,dp,vm[i]);
	printf("%.9lf\n",dp);
	return 0;
}