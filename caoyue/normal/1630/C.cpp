#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int INF=1e9+7;
int n,cnt=0,tot=0;
int a[N],L[N],R[N];
struct pir{int x,y;}p[N],q[N];
bool cmp(pir a,pir b){return a.x<b.x;}

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n){
		L[i]=n+1;
		R[i]=0;
	}
	rep(i,n){
		L[a[i]]=min(L[a[i]],i);
		R[a[i]]=max(R[a[i]],i);
	}
	rep(i,n)if(L[i]<=R[i])p[++cnt]=(pir){L[i],R[i]};
	sort(p+1,p+cnt+1,cmp);
	int nw=0;
	rep(i,cnt){
		if(nw>p[i].y)continue;
		nw=max(nw,p[i].y);
		q[++tot]=p[i];
	}
	int ans=n;
	for(int i=1;i<=tot;){
		if(q[i].x==q[i].y){
			ans--;
			i++;
			continue;
		}
		ans-=2;
		int t=i;
		while(1){
			int u=t;
			while(u!=tot&&q[u+1].x<=q[t].y)u++;
			if(u==t){
				i=t+1;
				break;
			}
			ans--;
			t=u;
		}
	}
	printf("%d\n",ans);
	return 0;
}