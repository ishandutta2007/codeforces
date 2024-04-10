#include<iostream>
#include<cstring>
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
#define mp make_pair
#define ll long long
#define db double
const ll N=4e5+7;
const ll INF=1e9+7;
ll n,Q;
char s[N];
ll la[N],sa[N],ra[N],nw[N],ct[N],ns[N],na[N],p[N],st[N][22],mn[N],a[N],b[N];
bool cmp(ll x,ll y){return s[x]<s[y];}
void build(){
	rep(i,n)p[i]=i;
	sort(p+1,p+n+1,cmp);
	ll ls=1;
	rep(i,n){
		if(s[p[i]]!=s[p[i-1]])ls=i;
		ra[p[i]]=ls;
		sa[i]=p[i];
	}
	for(ll i=0;(1<<i)<=n;i++){
		memset(nw,0,sizeof(nw));
		memset(la,0,sizeof(la));
		memset(ct,0,sizeof(ct));
		REP(j,n-(1<<i)+1,n){
			ns[ra[j]]=j;
			na[j]=ra[j];
			nw[ra[j]]++;
			la[ra[j]]++;
		}
		rep(j,n){
			if(sa[j]<=(1<<i))continue;
			ll p=sa[j]-(1<<i);
			nw[ra[p]]++;
			if(ra[sa[j]]!=ct[ra[p]]){
				ct[ra[p]]=ra[sa[j]];
				la[ra[p]]=nw[ra[p]];
			}
			ns[ra[p]+nw[ra[p]]-1]=p;
			na[p]=ra[p]+la[ra[p]]-1;
		}
		rep(j,n)sa[j]=ns[j],ra[j]=na[j];
	}
	ll ans=0;
	rep(i,n){
		ll d=ra[i];
		if(d==n){ans=0; continue;}
		if(ans)ans--;
		ll p=sa[d+1];
		while(s[i+ans]==s[p+ans]&&max(i,p)+ans<=n)ans++;
		st[d][0]=ans;
	}
	for(ll i=1;(1<<i)<n;i++){
		rep(j,n-(1<<i)+1)st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		REP(j,(1<<i)+1,(1<<(i+1)))mn[j]=i;
	}
}
ll qry(ll L,ll R){
	if(!L)return 0;
	if(R>=n)return 0;
	ll k=mn[R-L+1];
	return min(st[L][k],st[R-(1<<k)+1][k]);
}
bool cmp1(ll x,ll y){return ra[x]<ra[y];}
stack<pair<ll,ll> >o;

int main(){
	scanf("%I64d%I64d",&n,&Q);
	scanf("%s",s+1);
	build();
	ra[n+1]=n+1;
	while(Q--){
		ll k,l; scanf("%I64d%I64d",&k,&l);
		rep(i,k)scanf("%I64d",&a[i]);
		rep(i,l)scanf("%I64d",&b[i]);
		b[l+1]=n+1;
		sort(a+1,a+k+1,cmp1);
		sort(b+1,b+l+1,cmp1);
		ll nw=0,ans=0,rr=0;
		while(!o.empty())o.pop();
		o.push(mp(0,-1));
		rep(i,k){
			pair<ll,ll>q=o.top();
			int d=qry(ra[b[q.first]],ra[a[i]]-1);
			while(d<=q.second){
				ll t=q.first,v=q.second;
				o.pop();
				ans-=(t-o.top().first)*v;
				q=o.top();
			}
			if(o.top().first!=nw){
				ans+=(nw-o.top().first)*d;
				o.push(mp(nw,d));
			}
			while(ra[b[nw+1]]<ra[a[i]]&&nw!=l){
				nw++;
				ll d=qry(ra[b[nw]],ra[a[i]]-1);
				q=o.top();
				while(q.second>=d){
					ll t=q.first,v=q.second;
					o.pop();
					ans-=(t-o.top().first)*v;
					q=o.top();
				}
				ll u=o.top().first;
				ans+=(nw-u)*d;
				o.push(mp(nw,d));
			}
			if(b[nw+1]==a[i]&&nw!=l)rr+=(n-a[i]+1);
			rr+=ans;
		}
		nw=l+1;
		ans=0;
		while(!o.empty())o.pop();
		o.push(mp(l+1,-1));
		for(ll i=k;i;i--){
			pair<ll,ll>q=o.top();
			ll d=qry(ra[a[i]],ra[b[q.first]]-1);
			while(d<=q.second){
				ll t=q.first,v=q.second;
				o.pop();
				ans-=(o.top().first-t)*v;
				q=o.top();
			}
			if(o.top().first!=nw){
				ans+=(o.top().first-nw)*d;
				o.push(mp(nw,d));
			}
			while(ra[b[nw-1]]>ra[a[i]]&&nw){
				nw--;
				ll d=qry(ra[a[i]],ra[b[nw]]-1);
				q=o.top();
				while(q.second>=d){
					ll t=q.first,v=q.second;
					o.pop();
					ans-=(o.top().first-t)*v;
					q=o.top();
				}
				ll u=o.top().first;
				ans+=(u-nw)*d;
				o.push(mp(nw,d));
			}
			rr+=ans;
		}
		printf("%I64d\n",rr);
	}
	return 0;
}