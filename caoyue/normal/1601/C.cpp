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
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e6+7;
const int INF=1e9+7;
int T,n,m;
int a[N],b[N],L[N],R[N],fp[N],s[N];
ll c[N];
struct pir{int x,v;}p[N];
bool cmp(pir x,pir y){return x.v<y.v;}
void ins(int x){
	for(int i=x;i<=n;i+=(i&(-i)))c[i]++;
}
ll check(int x){
	ll ans=0;
	for(int i=x;i;i-=(i&(-i)))ans+=c[i];
	return ans;
}
ll solve(int l,int r,int a,int b){
	if(a==b){
		ll ss=0;
		REP(j,l,r){
			if(a>R[j])ss+=(ll)(a-R[j]);
			if(a<L[j])ss+=(ll)(L[j]-a);
		}
		return ss;
	}
	int mid=(a+b)>>1,mx=0,id=l-1;
	s[l-1]=0;
	REP(j,l,r){
		s[j]=0;
		if(mid>=R[j])s[j]=1;
		if(mid+1<=L[j])s[j]=-1;
		s[j]+=s[j-1];
		if(s[j]>mx){
			mx=s[j];
			id=j;
		}
	}
	ll ss=0;
	if(id>=l)ss+=solve(l,id,a,mid);
	if(id<r)ss+=solve(id+1,r,mid+1,b);
	return ss;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)p[i]=(pir){i,a[i]};
		sort(p+1,p+n+1,cmp);
		rep(i,m)scanf("%d",&b[i]);
		sort(b+1,b+m+1);
		b[0]=p[0].v=-1;
		int nl=0,nr=0,ls=0;
		rep(i,n){
			c[i]=0;
			if(p[i].v!=p[i-1].v){
				ls++;
				while(nl<=m&&p[i].v>b[nl])nl++;
				while(nr<=m&&p[i].v>=b[nr])nr++;
			}
			fp[p[i].x]=ls;
			L[p[i].x]=nl-1;
			R[p[i].x]=nr-1;
		}
		ll ans=0;
		for(int i=n;i;i--){
			ans+=check(fp[i]-1);
			ins(fp[i]);
		}
		ans+=solve(1,n,0,m);
		printf("%lld\n",ans);
	}
	return 0;
}