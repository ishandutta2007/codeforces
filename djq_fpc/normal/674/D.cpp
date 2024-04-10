#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
#define ll long long
using namespace std;
ll n,m,i,j,a[100005],deg[100005],num[100005],dv[100005],rem[100005],sum[100005];
multiset<ll> bi[100005],ans;
void link(ll x,ll y)
{
	bi[x].insert(sum[y]);
}
void cut(ll x,ll y)
{
	bi[x].erase(bi[x].find(sum[y]));
}
void ins(ll x)
{
	if(!bi[x].empty()){
		ans.insert(dv[x]+*bi[x].begin());
		ans.insert(dv[x]+*bi[x].rbegin());
	}
}
void del(ll x)
{
	if(!bi[x].empty()){
		ans.erase(ans.find(dv[x]+*bi[x].begin()));
		ans.erase(ans.find(dv[x]+*bi[x].rbegin()));
	}
}
void link2(ll x,ll y)
{
	a[x]=y;
	ll f=a[y],g=a[f];
	del(y);del(f);del(g);
	cut(g,f);cut(f,y);
	
	sum[f]-=dv[y];
	sum[y]-=dv[y]+rem[y];
	deg[y]++;
	dv[y]=num[y]/deg[y];
	rem[y]=num[y]%deg[y];
	sum[f]+=dv[y];
	sum[y]+=dv[y]+rem[y];
	sum[y]+=dv[x];
	
	link(y,x);link(f,y);link(g,f);
	ins(y);ins(f);ins(g);
}
void cut2(ll x,ll y)
{
	a[x]=0;
	ll f=a[y],g=a[f];
	del(y);del(f);del(g);
	cut(g,f);cut(f,y);cut(y,x);
	
	sum[f]-=dv[y];
	sum[y]-=dv[y]+rem[y];
	deg[y]--;
	dv[y]=num[y]/deg[y];
	rem[y]=num[y]%deg[y];
	sum[f]+=dv[y];
	sum[y]+=dv[y]+rem[y];
	sum[y]-=dv[x];
	
	link(f,y);link(g,f);
	ins(y);ins(f);ins(g);
}
int main()
{
	scanf("%lld%lld",&n,&m);
	fz1(i,n){
		scanf("%lld",&num[i]);
	}
	fz1(i,n){
		scanf("%lld",&a[i]);
		deg[i]+=2;deg[a[i]]++;
	}
	fz1(i,n){
		dv[i]=num[i]/deg[i];
		rem[i]=num[i]%deg[i];
	}
	fz1(i,n){
		sum[i]+=dv[i]+rem[i];
		sum[a[i]]+=dv[i];
	}
	fz1(i,n){
		link(a[i],i);
	}
	fz1(i,n){
		ins(i);
	}
	while(m--)
	{
		ll op;
		scanf("%lld",&op);
		if(op==1){
			ll x,y;
			scanf("%lld%lld",&x,&y);
			cut2(x,a[x]);
			link2(x,y);
		}
		if(op==2){
			ll x;
			scanf("%lld",&x);
			printf("%lld\n",sum[x]+dv[a[x]]);
		}
		if(op==3){
			printf("%lld %lld\n",*ans.begin(),*ans.rbegin());
		}
	}
	return 0;
}