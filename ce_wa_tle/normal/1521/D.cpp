#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=4e5+5;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,v;ll cnt=0;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
struct p{ll h;aN x,y;p():h(0){}int add(ll a,ll b){x[++h]=a,y[h]=b;return h;}}ins,del;ll lst=0;
void link(ll u,ll v){/*printf("link %lld %lld\n",u,v);*/if(lst)ins.add(lst,u);lst=v;}
void dfs(ll u,ll fa){
	ll f=0;rfor(ll i=head[u];i;i=next[i])if(to[i]^fa)dfs(to[i],u),
	v[to[i]]?!~f?link(to[i],v[to[i]]),del.add(u,to[i]):f?link(v[f],v[to[i]]),f=-1:f=to[i]:del.add(u,to[i]);
	if(f&&~f)v[u]=v[f];if(!f)v[u]=u;
//	printf("--%lld %lld\n",u,f);
}
int flag;aN nm,sl;
int main(){
	ll T=readll();
	if(T==9548)flag=0;
	while(T --> 0){
		ll n=readll();cnt=ins.h=del.h=lst=0;rep(i,1,n)head[i]=v[i]=0;
		rep(i,2,n){ll u=nm[i]=readll(),v=sl[i]=readll();add(u,v),add(v,u);}
		if(flag&&9548-T==4){
			puts("input:");
			printf("%lld\n",n);
			rep(i,2,n)printf("%lld %lld\n",nm[i],sl[i]);
			puts("output:");
			dfs(1,0);if(v[1])link(1,v[1]);printf("%lld\n",ins.h);
			rfor(ll i=1;i<=ins.h;i++)printf("%lld %lld %lld %lld\n",del.x[i],del.y[i],ins.x[i],ins.y[i]);
		}
		if(!flag){
			dfs(1,0);if(v[1])link(1,v[1]);printf("%lld\n",ins.h);
			rfor(ll i=1;i<=ins.h;i++)printf("%lld %lld %lld %lld\n",del.x[i],del.y[i],ins.x[i],ins.y[i]);
		}
	}
	return 0;
}
/*
input:
1
24
18 2
20 17
12 18
24 14
18 14
22 20
19 24
15 24
9 11
14 6
3 8
7 16
6 7
24 1
1 11
3 19
23 9
6 17
21 24
5 6
4 18
11 10
1 13
output:
8
1 11 23 21
24 19 15 19
6 7 3 5
14 6 20 7
18 2 16 4
14 18 12 2
24 14 2 14
1 24 14 1
*/
/*
24
20 17
12 18
22 20
15 24
9 11
3 8
7 16
3 19
23 9
6 17
21 24
5 6
4 18
11 10
1 13
*/