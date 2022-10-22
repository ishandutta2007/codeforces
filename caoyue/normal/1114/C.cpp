#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=3e6+7;
const ll INF=1e18+7;
ll n,b,cnt=0;
ll p[N],c[N]; 
int main(){
	cin>>n>>b;
	REP(i,2,sqrt(b)){
		if(b%i==0){
			p[++cnt]=i;
			c[cnt]=0;
			while(b%i==0)b/=i,c[cnt]++;
		}
	}
	if(b>1){
		p[++cnt]=b;
		c[cnt]=1;
	}
	ll ans=INF;
	rep(i,cnt){
		ll h=n,u=0;
		while(1){
			h/=p[i];
			if(h)u+=h;
			else break;
		}
		ans=min(ans,u/c[i]);
	}
	cout<<ans<<endl;
	return 0;
}