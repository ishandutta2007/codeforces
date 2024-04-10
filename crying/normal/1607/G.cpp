#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const ll MAXN=2e5+10,INF=1e18;
ll T,n,m,a[MAXN],b[MAXN],suma,sumb,ans; 
ll maxa[MAXN],mina[MAXN],maxsum,minsum;
ll reta[MAXN],retb[MAXN];
ll dis(ll suma,ll sumb,ll a){
	return (suma-a)-(sumb-n*m+a);
}
void solve(){
	cin>>n>>m;
	suma=sumb=maxsum=minsum=0;
	rep(i,1,n){
		cin>>a[i]>>b[i];
		suma+=a[i];sumb+=b[i];
	}
	rep(i,1,n){
		maxa[i]=min(a[i],m);
		mina[i]=m-min(b[i],m);
		maxsum+=maxa[i];minsum+=mina[i];
	}
	ans=INF;
	if(abs(dis(suma,sumb,maxsum))<abs(ans)){
		ans=dis(suma,sumb,maxsum);
	}
	if(abs(dis(suma,sumb,minsum))<abs(ans)){
		ans=dis(suma,sumb,minsum);
	}
	ll val=suma-sumb+n*m;
	if(odd(val)==1){
		ll step=(val-1)/2;
		if(minsum<=step && maxsum>=step)ans=1;
		step=(val+1)/2;
		if(minsum<=step && maxsum>=step)ans=-1;
	}else{
		ll step=val/2;
		if(minsum<=step && maxsum>=step)ans=0;
	}
	printf("%lld\n",abs(ans));
	//construct answer
	ll ret=val-2*minsum;
	rep(i,1,n){
		reta[i]=mina[i];
		retb[i]=m-mina[i];
	}
	rep(i,1,n){
		ll diff=(ret-ans)/2;
		diff=min(diff,maxa[i]-mina[i]);
		ret-=diff*2;
		reta[i]+=diff;retb[i]-=diff;
	}
	rep(i,1,n)printf("%lld %lld\n",reta[i],retb[i]); 
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}