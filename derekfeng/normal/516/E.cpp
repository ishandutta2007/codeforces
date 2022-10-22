#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n,m,G,a,b,N;
vector<ll>mpa[200005],mpb[200005];
ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d=a;if(b!=0){d=extgcd(b,a%b,y,x);
	y-=(a/b)*x;}else x=1,y=0;return d;
}
ll inv(ll m,ll n){
	ll X,Y;extgcd(m,n,X,Y);
	return (X%n+n)%n;
}
ll dis[200005],val[200005];
void sol(ll n,ll m,vector<ll>&a,vector<ll>&b){
	int iv=inv(m,n);ll nn=n,mm=m;n/=G,m/=G;
	map<ll,ll>mp;map<ll,bool>mpi;
	for(auto x:a){
		ll tmp=(x/G)*iv%n;
		if(!mp.count(tmp))mp[tmp]=1e18;
		mp[tmp]=min(mp[tmp],x),mpi[tmp]=1;
	}
	for(auto x:b){
		ll tmp=(x/G)%n*iv%n;
		if(!mp.count(tmp))mp[tmp]=1e18;
		mp[tmp]=min(mp[tmp],x);
	}
	N=0;for(auto [p,x]:mp)dis[N]=x,val[N]=p,N++;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
	for(int i=0;i<N;i++)pq.push({dis[i],i});
	while(!pq.empty()){
		auto [w,u]=pq.top();pq.pop();
		if(w>dis[u])continue;
		ll d=(val[(u+1)%N]+n-val[u])%n;if(d<0)d=n-1;
		ll W=w+mm*d;
		if(W<dis[(u+1)%N]){
			dis[(u+1)%N]=(dis[(u+1)%N],W);
			pq.push({W,(u+1)%N});
		}
	}
	for(int i=0;i<N;i++){
		if(!mpi[val[i]])ans=max(ans,dis[i]);
		if(n==1||val[(i+1)%N]==(val[i]+1)%n)continue;
		ll d=(val[(i+1)%N]+n-val[i])%n-1;if(d<0)d=n-1;
		ans=max(ans,(ll)dis[i]+mm*d);
	}
}
int main(){
	scanf("%d%d",&n,&m),G=__gcd(n,m);if(G>2e5){puts("-1");return 0;}
	scanf("%d",&a);for(int i=0,x;i<a;i++)scanf("%d",&x),mpa[x%G].push_back(x);
	scanf("%d",&b);for(int i=0,x;i<b;i++)scanf("%d",&x),mpb[x%G].push_back(x);
	if(G>a+b){puts("-1");return 0;}
	for(int i=0;i<G;i++){
		if(mpa[i].empty()&&mpb[i].empty()){puts("-1");return 0;}
		sol(n,m,mpa[i],mpb[i]),sol(m,n,mpb[i],mpa[i]);
	}
	printf("%lld\n",ans);
}