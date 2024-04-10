#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(ll i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const ll N=4e5+7;
const ll INF=1e15+7;
ll T,n,m,k;
ll a[N],b[N],u[N];
ll check1(ll v,ll t){
	ll ans=0;
	rep(i,m){
		if(i>=t)v++;
		if(v%2==0)ans+=a[i]/(v/2);
		else ans+=(a[i]-1)/((v-1)/2);
		if(i>=t)v--;
	}
	return ans;
}
ll check2(ll v,ll t){
	ll ans=0;
	rep(i,m){
		if(i<=t)v--;
		if(v%2==0)ans+=(a[i]-(a[i]+(v/2)-1)/(v/2)+1);
		else ans+=(a[i]-(a[i]+((v+1)/2))/((v+1)/2)+1);
		if(i<=t)v++;
	}
	return ans;
}
void cb1(ll x){
	ll sm=0;
	rep(i,m){
		b[i]=((x+1)&1)?((a[i]-1)/(x/2)):(a[i]/((x+1)/2));
		u[i]=((x&1)?((a[i]-1)/((x-1)/2)):(a[i]/(x/2)))-b[i];
		sm+=b[i];
	}
	rep(i,m){
		if(sm+u[i]>=k+m){
			b[i]+=(k+m-sm);
			return;
		}
		b[i]+=u[i];
		sm+=u[i];
	}
}
void cb2(ll x){
	ll sm=0;
	rep(i,m){
		ll x1=x/2,x2=(x+1)/2;
		b[i]=((x-1)&1)?((a[i]+x1)/x1):((a[i]+x1-1)/x1);
		u[i]=(x&1)?((a[i]+x2)/x2):((a[i]+x2-1)/x2);
		b[i]=(a[i]-b[i]+1);
		u[i]=(a[i]-u[i]+1);
		u[i]-=b[i];
		sm+=b[i];
	}
	rep(i,m){
		if(sm+u[i]>=n-k){
			b[i]+=(n-k-sm);
			break;
		}
		b[i]+=u[i];
		sm+=u[i];
	}
	rep(i,m)b[i]=(a[i]-b[i]+1);
}
struct pir{ll x,v;}p[N];
bool cmp1(pir x,pir y){
	if(!x.v){
		if(!y.v)return x.x<y.x;
		return 1;
	}
	if(!y.v)return 0;
	if((a[x.x]/x.v)!=(a[y.x]/y.v))return (a[x.x]/x.v)>(a[y.x]/y.v);
	if(a[x.x]%x.v==0){
		if(a[y.x]%y.v==0)return x.x<y.x;
		return 0;
	}
	if(a[y.x]%y.v==0)return 1;
	return x.x<y.x;
}
bool cmp2(pir x,pir y){
	if((a[x.x]/x.v)!=(a[y.x]/y.v))return (a[x.x]/x.v)<(a[y.x]/y.v);
	if(a[x.x]%x.v==0){
		if(a[y.x]%y.v==0)return x.x>y.x;
		return 1;
	}
	if(a[y.x]%y.v==0)return 0;
	return x.x>y.x;
}
int main(){
	scanf("%lld",&T);
	rep(gg,T){
		scanf("%lld%lld%lld",&n,&m,&k);
		ll ls=0,mx=0,ans=INF;
		rep(i,m){
			ll x; scanf("%lld",&x);
			a[i]=x-ls;
			ls=x;
		}
		a[++m]=n-ls;
		rep(i,m)mx=max(mx,a[i]);
		ll l=2,r=mx*2;
		while(l<r-1){
			ll mid=(l+r)>>1;
			if(check1(mid,m+1)<k+m)r=mid;
			else l=mid;
		}
		ll e=(check1(r,m+1)>=k+m)?r:l;
		cb1(e);
		rep(i,m)p[i]=(pir){i,b[i]};
		sort(p+1,p+m+1,cmp1);
		ll L=1,R=m;
		while(L<R-1){
			ll Mid=(L+R)>>1;
			if(!p[Mid].v)L=Mid;
			else {
				if(check1(a[p[Mid].x]/p[Mid].v*2+(a[p[Mid].x]%p[Mid].v!=0),p[Mid].x)<=k)L=Mid;
				else R=Mid;
			}
		}
		if(p[R].v)if(check1(a[p[R].x]/p[R].v*2+(a[p[R].x]%p[R].v!=0),p[R].x)<=k)L=R;
		rep(i,L){
			if(p[i].v)ans=min(ans,(a[p[i].x]/p[i].v+(a[p[i].x]%p[i].v!=0))-e/2);
			if(p[i].v==a[p[i].x])break;
			e=min(e,((a[p[i].x]%(p[i].v+1)==0)?(a[p[i].x]/(p[i].v+1)*2):((a[p[i].x]/(p[i].v+1))*2+1)));
		}
		
		/*******************************************************************/
		
		l=2,r=mx*2;
		while(l<r-1){
			ll mid=(l+r)>>1;
			if(check2(mid,0)<n-k)l=mid;
			else r=mid;
		}
		e=(check2(l,0)>=n-k)?l:r;
		rep(i,m)b[i]++;
		rep(i,m)p[i]=(pir){i,b[i]};
		sort(p+1,p+m+1,cmp2);
		L=1,R=m;
		while(L<R-1){
			ll Mid=(L+R)>>1;
			if(p[Mid].v>a[p[Mid].x])L=Mid;
			else{
				if(check2(a[p[Mid].x]/p[Mid].v*2+(a[p[Mid].x]%p[Mid].v!=0),p[Mid].x)<=n-k-m)L=Mid;
				else R=Mid;
			}
		}
		if(p[R].v<=a[p[R].x])if(check2(a[p[R].x]/p[R].v*2+(a[p[R].x]%p[R].v!=0),p[R].x)<=n-k-m)L=R;
		rep(i,L){
			if(p[i].v<=a[p[i].x])ans=min(ans,(e+1)/2-a[p[i].x]/p[i].v);
			if(p[i].v==1)break;
			e=max(e,((a[p[i].x]%(p[i].v-1)==0)?(a[p[i].x]/(p[i].v-1)*2):((a[p[i].x]/(p[i].v-1))*2+1)));
		}
		printf("%lld\n",ans);
	}
	return 0;
}