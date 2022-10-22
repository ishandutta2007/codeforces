#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep0(i,n) REP(i,0,n-1)
#define rep(i,n) REP(i,1,n)
#define ll long long
const ll N=200005;
const ll M=9000005;
ll gcd(ll a,ll b){
	if(!b)return a;
	return gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1; y=0;
		return;
	}
	exgcd(b,a%b,x,y); 
	ll t=x;
	x=y;
	y=t-a/b*y;
}
ll pos[N],dp[N],gd[N],ps[N],ys[N],ansmod[N],ans[N];
bool cb[N];
struct edge{
	ll v,next;
}e[M];
ll num=0,n,m,cnt;
ll fj(ll x){
	ll tot=0;
	REP(i,2,x){
		if(x%i==0)ys[++tot]=i;
		if(x==0)break;
		while(x%i==0)x/=i;
	}
	return tot;
}
void add(ll x,ll y){
	e[num]=(edge){y,pos[x]};
	pos[x]=num++;
}
void dagdp(){
	memset(dp,0,sizeof(dp));
	dp[m]=gd[m];
	for(ll i=m-1;i>0;i--)for(ll j=pos[i];j>=0;j=e[j].next)dp[i]=max(dp[i],dp[e[j].v]+gd[i]);
}
void zjqb(ll x){
	for(ll i=ps[x];~i;i=e[i].next)ansmod[++cnt]=e[i].v;
	for(ll i=pos[x];~i;i=e[i].next){
		if(dp[e[i].v]==dp[x]-gd[x]){
			zjqb(e[i].v);
			break;
		}
	}
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	memset(cb,1,sizeof(cb));
	memset(ps,-1,sizeof(ps));
	memset(pos,-1,sizeof(pos));
	memset(gd,0,sizeof(gd));
	rep(i,n){ll x; scanf("%I64d",&x); cb[x]=0;}
	rep0(i,m){if(!cb[i])continue; ll k=gcd(m,i); gd[k]++; e[num]=(edge){i,ps[k]}; ps[k]=num++;}
	ll tt=fj(m);
	for(ll i=m;i>0;i--)rep(j,tt)if(i%ys[j]==0)add(i/ys[j],i);
	dagdp();
	cnt=0;
	zjqb(1);
	cout<<cnt<<endl;
	ans[1]=ansmod[1];
	REP(i,2,cnt){
		ll q1=ansmod[i-1],q2=ansmod[i],q3=m;
		ll k1=gcd(q1,q3);
		q1/=k1; q2/=k1; q3/=k1;
		ll x,y; exgcd(q1,q3,x,y);
		if(x<0)x+=q3;
		ans[i]=(x*q2)%m;
	}
	rep(i,cnt)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}