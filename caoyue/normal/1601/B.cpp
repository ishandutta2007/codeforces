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
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=3e5+7;
const int INF=1e9+7;
int f[N],dis[N],fr[N],vf[N],a[N],b[N],Qu[N*2];
int n;
int ff(int x){return (f[x]==x)?x:f[x]=ff(f[x]);}
void dfs(int x){
	if(x!=n){
		dfs(fr[x]);
		printf("%d ",vf[x]);
	}
} 
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)scanf("%d",&b[i]);
	rep(i,n)f[i]=i;
	int hd=0,ti=1;
	rep(i,n)dis[i]=INF;
	Qu[1]=n;
	dis[n]=0;
	while(hd!=ti){
		int t=Qu[++hd];
		if(a[t]>=t){
			printf("%d\n",dis[t]+1);
			dfs(t);
			puts("0");
			return 0;
		}
		for(int j=ff(t);j>=t-a[t];j=ff(j)){
			if(dis[j+b[j]]>dis[t]+1){
				dis[j+b[j]]=dis[t]+1;
				fr[j+b[j]]=t;
				vf[j+b[j]]=j;
				Qu[++ti]=j+b[j];
			}
			f[j]=j-1;
		}
	}
	puts("-1");
	return 0;
}