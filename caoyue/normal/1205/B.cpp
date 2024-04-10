#include<iostream>
#include<cstring>
#include<cassert>
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
#define ll long long
#define db double
const ll N=1e5+7;
const ll INF=1e9+7;
ll n,cnt=0,ans=INF;
ll a[N],sm[64],w[N],d1[64],d2[64],dis[128],fr[128];
bool q[N],t[128][128];
void bfs(ll x){
	queue<int>q;
	while(!q.empty())q.pop();
	q.push(x);
	rep(i,cnt)dis[i]=(i==x)?0:INF;
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		rep(j,cnt){
			if(t[u][j]){
				if(dis[j]>dis[u]+1){
					dis[j]=dis[u]+1;
					fr[j]=u;
					q.push(j);
				}
				else if(fr[u]!=j)ans=min(ans,dis[u]+dis[j]+1);
			}
		} 
	}
}
int main(){
	scanf("%I64d",&n);
	rep(i,n)scanf("%I64d",&a[i]);
	rep(i,n)rep0(j,60)sm[j]+=((a[i]>>j)&1);
	rep0(j,60)if(sm[j]>2){puts("3"); return 0;}
	rep0(j,60){
		ll id1=-1,id2=-1;
		if(sm[j]==2){
			rep(i,n){
				if((a[i]>>j)&1){
					if(~id1)id2=i;
					else id1=i;
				}
			}
			q[id1]=q[id2]=1;
			d1[j]=id1;
			d2[j]=id2;
		}
	}
	rep(i,n)if(q[i])w[i]=++cnt;
	rep0(j,60)if(sm[j]==2)t[w[d1[j]]][w[d2[j]]]=t[w[d2[j]]][w[d1[j]]]=1;
	rep(i,cnt)bfs(i);
	if(ans!=INF)printf("%I64d\n",ans);
	else puts("-1");
	return 0;
}