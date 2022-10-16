#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
#define inf 1000000000000000000
using namespace std;
int n,m,d[10005],g,r;
int q[20000005][2],head,tail;
ll dis[10005][1005];
ll qwq[10005];
void bfs(){
	memset(dis,-1,sizeof(dis));
	memset(qwq,-1,sizeof(qwq));
	head=tail=10000000;
	q[tail][0]=1,q[tail][1]=0;
	dis[1][0]=0;
	while(head<=tail){
		int nowp=q[head][0],nowt=q[head][1];
		if (nowt==0)qwq[nowp]=dis[nowp][nowt];
		head++;
		if (nowp>1){
			int nxtt=nowt+d[nowp]-d[nowp-1];
			if (nxtt==g&&dis[nowp-1][0]==-1){
				dis[nowp-1][0]=dis[nowp][nowt]+1;
				++tail;
				q[tail][0]=nowp-1,q[tail][1]=0;
			}
			if (nxtt<g&&dis[nowp-1][nxtt]==-1){
				dis[nowp-1][nxtt]=dis[nowp][nowt];
				--head;
				q[head][0]=nowp-1,q[head][1]=nxtt;
			}
		}
		if (nowp<m){
			int nxtt=nowt+d[nowp+1]-d[nowp];
			if (nxtt==g&&dis[nowp+1][0]==-1){
				dis[nowp+1][0]=dis[nowp][nowt]+1;
				++tail;
				q[tail][0]=nowp+1,q[tail][1]=0;
			}
			if (nxtt<g&&dis[nowp+1][nxtt]==-1){
				dis[nowp+1][nxtt]=dis[nowp][nowt];
				--head;
				q[head][0]=nowp+1,q[head][1]=nxtt;
			}
		}
	}
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++)cin>>d[i];
	cin>>g>>r;
	sort(d+1,d+1+m);
	bfs();
	ll ans=inf;
	for (int i=1;i<=m;i++)
		if (qwq[i]!=-1&&d[m]-d[i]<=g)ans=min(ans,qwq[i]*(g+r)+d[m]-d[i]);
	if (ans==inf)puts("-1");
	else cout<<ans<<endl;
	return 0;
}