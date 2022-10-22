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
const ll N=5e5+7;
const ll INF=1e9+7;
ll T,n,m,cnt=0;
ll id[N],v[N],sm[N],w[N],a[N],in[N],to[N],s[N],s1[N],s2[N];
ll calc(ll x,ll y){
	if(a[n]*x<y)return n+1;
	ll l=1,r=n;
	while(l<r-1){
		ll mid=(l+r)>>1;
		if(a[mid]*x<y)l=mid;
		else r=mid;
	}
	if(a[l]*x>=y)return l;
	return r;
}
bool is[N];

int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		rep(i,n)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		cnt=0;
		rep(i,m){
			scanf("%lld",&w[i]);
			sm[i]=0;
			rep(j,w[i]){
				scanf("%lld",&v[++cnt]);
				id[cnt]=i;
				sm[i]+=v[cnt];
			}
			in[i]=calc(w[i],sm[i]);
		}
		rep(i,cnt)to[i]=calc(w[id[i]]-1,sm[id[i]]-v[i]);
		rep0(i,n+1)s[i]=s1[i]=s2[i]=0;
		rep(i,m)s[in[i]]++;
		bool gg=0;
		rep(i,n){
			s[i]+=s[i-1];
			s1[i]=s1[i-1];
			s2[i]=s2[i-1];
			if(s[i]<=i-n+m-2){
				gg=1;
				break;
			}
			if(s[i]==i-n+m-1)s1[i]++;
			if(s[i]==i-n+m)s2[i]++;
		}
		if(gg||s[n]<m-1){
			rep(i,cnt)putchar('0');
			puts("");
			continue;
		}
		rep(i,cnt){
			is[i]=1;
			if(to[i]>n)is[i]=0;
			if(s[n]!=m&&in[id[i]]<=n)is[i]=0;
			if(in[id[i]]==to[i])if(s1[n])is[i]=0;
			if(in[id[i]]>to[i])if(s1[in[id[i]]-1]-s1[to[i]-1]!=s1[n])is[i]=0;
			if(in[id[i]]<to[i])if(s1[n]||s2[to[i]-1]-s2[in[id[i]]-1]!=0)is[i]=0;
			putchar('0'+is[i]);
		}
		puts("");
	}
	return 0;
}