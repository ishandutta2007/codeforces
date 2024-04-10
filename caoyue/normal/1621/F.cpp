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
const ll N=2e5+7;
const ll INF=1e9+7;
ll T,n,A,B,C,L,R,c0,c1,z0,z1;
char s[N];
ll t1[N],t0[N];

int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&A,&B,&C);
		scanf("%s",s+1);
		bool f1=0,f0=0;
		rep(i,n){
			if(s[i]=='0')f0=1;
			if(s[i]=='1')f1=1;
		}
		if(n==1){
			puts("0");
			continue;
		}
		if(!f0||!f1){
			if(f0)printf("%lld\n",A);
			else printf("%lld\n",B);
			continue;
		}
		L=1;
		R=n;
		while(s[L]!='1')L++;
		while(s[R]!='1')R--;
		c0=c1=z0=z1=0;
		s[L-1]=s[R+1]='0';
		for(ll i=L;i<=R;i++){
			ll nw=i;
			while(s[nw+1]==s[i])nw++;
			if(s[i]=='1')t1[++c1]=nw-i+1;
			else t0[++c0]=nw-i+1;
			i=nw;
		}
		REP(i,L,R){
			if(s[i]==s[i-1]){
				if(s[i]=='1')z1++;
				else z0++;
			}
		}
		ll ans=0;
		sort(t0+1,t0+c0+1);
		rep0(a,2){
			if(L==1&&a)continue;
			rep0(b,2){
				if(R==n&&b)continue;
				ll ss=a*(L-1)+b*(n-R),vs=a*((L-2)*A-C)+b*((n-R-1)*A-C),vg=0;
				if(L!=1&&!a)vg+=(L-2);
				if(R!=n&&!b)vg+=(n-1-R);
				rep0(u,2){
					if(z1<u)continue;
					ll hh=z1-u,vl=u*B,gg=z0+vg;
					rep0(j,c0+1){
						if(j){
							hh-=(t0[j]-1);
							if(hh<0)break;
							vl+=(t0[j]-1)*(A+B);
							vl+=(B-C);
							gg-=(t0[j]-1);
						}
						if(hh+1<ss)break;
						if(hh+1==ss)ans=max(ans,vl+vs+(ss-1)*B);
						else{
							ll v=vl+vs+ss*B,h=hh-ss;
							if(h<gg)ans=max(ans,v+h*B+(h+1)*A);
							else ans=max(ans,v+gg*(A+B));
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}