#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e3+10;
const ll INF=1e18;
ll n,m,k,p;
ll a[maxn][maxn],Fir[maxn*maxn],Sec[maxn*maxn];
struct My{
	ll x,id;
	inline My(){}
	inline My(ll _x,ll _id){x=_x,id=_id;}
	inline friend bool operator < (const My &x,const My &y){return x.x<y.x;}
};
priority_queue<My> Q;
ll Ans1[maxn*maxn],Ans2[maxn*maxn];
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p); 
	for (ll i=1;i<=n;++i)
		for (ll j=1;j<=m;++j) scanf("%lld",&a[i][j]);
	
	for (ll i=1;i<=n;++i)
		for (ll j=1;j<=m;++j) Fir[i]+=a[i][j],Sec[j]+=a[i][j];
	
	for (ll i=1;i<=n;++i) Q.push(My(Fir[i],i));	
	for (ll i=1;i<=k;++i){
		My now=Q.top(); Q.pop(); 
		Ans1[i]=Ans1[i-1]+now.x; now.x-=m*p; Q.push(now);
	}	
		
	while (!Q.empty()) Q.pop(); 
	for (ll i=1;i<=m;++i) Q.push(My(Sec[i],i));
	for (ll i=1;i<=k;++i){
		My now=Q.top(); Q.pop();
		Ans2[i]=Ans2[i-1]+now.x; now.x-=n*p; Q.push(now);
	}
	ll Ans=-INF;
	for (ll i=0;i<=k;++i) Ans=max(Ans,Ans1[i]+Ans2[k-i]-p*(k-i)*i);
	printf("%lld",Ans);
	return 0;
}