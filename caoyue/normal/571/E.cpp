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
const ll N=2007;
const ll mod=1e9+7;
const ll INF=1e18;
ll Pow(ll x,ll y){
	ll ans=1,now=x;
	while(y){
		if(y&1)ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
map<ll,ll>mp;
void fw(ll x){
	REP(i,2,sqrt(x)){
		if(x%i==0){
			while(x%i==0)x/=i;
			mp[i]=1;
		}
	}
	if(x>1)mp[x]=1;
}
ll a[N],b[N],t1[N],t2[N],vm[N],s1[N],s2[N],as[N],mt[N],dm[N],dc[N],yc[N];
ll e[10]={2,3,5,7,11,13,17,19,23,29},qm[10],qc[10];
ll n,cnt=0;
void ft(ll *gg,ll x){
	ll nw=x;
	rep(i,cnt){
		gg[i]=0;
		while(nw%vm[i]==0){
			nw/=vm[i];
			gg[i]++;
		}
	}
}
bool check(ll *gg){
	rep(i,n){
		ll v=0;
		ft(t1,a[i]);
		ft(t2,b[i]);
		rep(j,cnt){
			if(gg[j]-t1[j]){
				if(!t2[j])return 0;
				if((gg[j]-t1[j])%t2[j]!=0)return 0;
				v=(gg[j]-t1[j])/t2[j];
				break;
			}
		}
		rep(j,cnt)if(gg[j]!=t1[j]+t2[j]*v)return 0;
	}
	return 1;
}
ll calc(ll *gg){
	ll ans=1;
	rep(i,cnt)ans=ans*Pow(vm[i],gg[i])%mod;
	return ans;
}
int main(){
	scanf("%lld",&n);
	rep(i,n){
		scanf("%lld%lld",&a[i],&b[i]);
		fw(a[i]); fw(b[i]);
	}
	if(n==1){printf("%lld\n",a[1]); return 0;}
	for(map<ll,ll>::iterator s=mp.begin();s!=mp.end();s++){
		vm[++cnt]=s->first;
		mp[s->first]=cnt;
	}
	rep(i,n){
		if(b[i]==1){
			ft(as,a[i]);
			if(check(as))printf("%lld\n",a[i]);
			else puts("-1");
			return 0;
		}
	}
	rep(i,n-1){
		ft(t1,b[i]);
		ft(t2,b[i+1]);
		bool fl=0;
		ll ux,uy,d;
		rep(j,cnt)if(t1[j])ux=t1[j],uy=t2[j],d=j;
		rep(j,cnt){
			if(t1[j]*uy!=t2[j]*ux){
				ft(s1,a[i]);
				ft(s2,a[i+1]);
				ll bb=(s2[d]*t1[j]-s2[j]*t1[d]+t1[d]*s1[j]-t1[j]*s1[d]);
				ll cc=t1[d]*t2[j]-t1[j]*t2[d];
				if(!cc){puts("-1"); return 0;}
				if(cc<0)bb=-bb,cc=-cc;
				if(bb%cc!=0){
					puts("-1");
					return 0;
				}
				ll y=bb/cc;
				if(y<0){
					puts("-1");
					return 0;
				}
				int ub=s2[d]-s1[d]+t2[d]*y;
				if(ub%t1[d]!=0){puts("-1"); return 0;}
				if(ub<0){puts("-1"); return 0;}
				rep(k,cnt)as[k]=s2[k]+t2[k]*y;
				if(check(as))printf("%lld\n",calc(as));
				else puts("-1");
				return 0;
			}
		}
	}
	ll mi=INF,hd;
	rep(i,n)mi=min(mi,a[i]);
	ft(t1,b[1]);
	rep(i,cnt)mt[i]=t1[i];
	rep(i,cnt)if(mt[i]){hd=i; break;}
	dm[1]=t1[hd];
	REP(i,2,n){
		ft(t1,b[i]);
		dm[i]=t1[hd];
		rep(j,cnt)mt[j]=gcd(mt[j],t1[j]);
	}
	ft(t1,mi);
	rep(i,n){
		ft(t2,a[i]);
		dc[i]=t2[hd];
		ll ls=-1;
		rep(j,cnt){
			if(!mt[j])continue;
			if((t2[j]-t1[j])%mt[j]!=0){
				puts("-1");
				return 0;
			}
			if(ls<0)ls=(t2[j]-t1[j])/mt[j];
			else if(t2[j]!=t1[j]+mt[j]*ls){
				puts("-1");
				return 0;
			}
		}
	}
	rep0(i,10)qm[i]=1,qc[i]=0;
	rep(i,n){
		yc[i]=dc[i];
		dc[i]%=dm[i];
		rep0(j,10){
			ll gg=1,nw=dm[i];
			while(nw%e[j]==0)gg*=e[j],nw/=e[j];
			ll ng=dc[i]%gg;
			if(gg>=qm[j]){
				if(ng%qm[j]!=qc[j]){
					puts("-1");
					return 0;
				}
				qm[j]=gg;
				qc[j]=ng;
			}
			else{
				if(qc[j]%gg!=ng){
					puts("-1");
					return 0;
				}
			}
		}
	}
	ll S=0,mm=1;
	rep0(i,10){
		if(qm[i]==1)continue;
		ll sc=1;
		rep0(j,10)if(i!=j)sc*=qm[j];
		ll mc=sc%qm[i],iv;
		rep0(j,qm[i])if(j*mc%qm[i]==1){iv=j; break;}
		iv=iv*qc[i]%qm[i];
		S+=sc*iv;
		mm*=qm[i];
	}
	S%=mm;
	rep(i,n)while(S<yc[i])S+=mm;
	ft(t1,a[1]);
	ft(t2,b[1]);
	rep(i,cnt)as[i]=t2[i]*((S-dc[1])/dm[1])+t1[i];
	printf("%lld\n",calc(as));
	return 0;
}