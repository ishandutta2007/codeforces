#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=20,S=(1<<16)+10,V=2048;
bitset<V> dp[S]; int a[N],id[N]; priority_queue<pr> q;
int main(){
	int n,k,v=0; scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]),v+=a[i];
	dp[0][0]=1; int u=(1<<n)-1;
	rep(s,0,u){	
		per(i,v/k,1) if (dp[s][i*k]) dp[s][i]=1;
		rep(i,1,n) 
			if (!(s>>i-1&1)) dp[s|(1<<i-1)]|=dp[s]<<a[i];
	}
	puts(dp[u][1]?"YES":"NO");
	if (!dp[u][1]) return 0;
	int c=1e9;
	for (int s=u,j=1;s;)
		for (int t=j,ok=0;!ok;t*=k,c-=!ok)
			rep(i,1,n){
				if (t<a[i]) continue;
				if ((s>>i-1&1)&&dp[s^(1<<i-1)][t-a[i]]){
					id[i]=c,s^=1<<i-1,j=t-a[i],ok=1; 
					break;
				}
			}
	rep(i,1,n) q.push(mp(-(id[i]-c),a[i]));
	while (q.size()>1){
		pr x=q.top(); q.pop();
		pr y=q.top(); q.pop();
		printf("%d %d\n",x.se,y.se);
		int v=x.se+y.se,u=0;
		while (v%k==0) v/=k,++u;
		q.push(mp(-(-x.fi+u),v));
	}
	return 0;
}