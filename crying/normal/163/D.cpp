#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const double EPS=1e-6;
struct Node{
	ll u,cnt;
	bool operator<(const Node& n2)const{
		return u>n2.u;
	}
}factor[100];
ll t,n,vis[100],ans,v;
ll a,b,c,LIMA,LIMB;
ll x,y,z;
void dfs2(int pos){
	if(y>LIMB)return;
	if(pos>n){
		z=v/x/y;
		ll s=2*(x*y+y*z+x*z);
		if(ans==-1 || ans>s)ans=s,a=x,b=y,c=z;
		return;
	}
	if(vis[pos]){
		vis[pos]--;y*=factor[pos].u;
		dfs2(pos);
		vis[pos]++;y/=factor[pos].u;
	}
	dfs2(pos+1);
}
void dfs(int pos){
	if(x>LIMA)return;
	if(pos>n){
		ll down_lim=4*x*sqrt(v/x)+2*v/x;
		if(ans!=-1 && ans<=down_lim)return; //
		//B
		LIMB=sqrt(v/x)+EPS;
		y=1;dfs2(1);
		return;
	}
	if(vis[pos]){
		vis[pos]--;x*=factor[pos].u;
		dfs(pos);
		vis[pos]++;x/=factor[pos].u;
	}
	dfs(pos+1);
}
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%d",&n);
		ans=-1;
		v=1;x=1;
		rep(i,1,n){
			scanf("%lld%lld",&factor[i].u,&factor[i].cnt);
			rep(j,1,factor[i].cnt)v*=factor[i].u;
		}	
		sort(factor+1,factor+1+n);
		rep(i,1,n){
			vis[i]=factor[i].cnt;
		}
		LIMA=pow(v,1.00/3.00)+EPS;
		dfs(1);
		printf("%lld %lld %lld %lld\n",ans,a,b,c);
	}
	return 0;
}