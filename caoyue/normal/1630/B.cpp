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
const int N=5e5+7;
const int INF=1e9+7;
int T,n,k;
int a[N],p[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)p[i]=a[i];
		sort(p+1,p+n+1);
		int v=(n+k+1)/2;
		int mi=INF,id=0,x,y;
		rep(i,n){
			if(i+v-1>n)continue;
			if(p[i+v-1]-p[i]<mi){
				mi=p[i+v-1]-p[i];
				id=i;
			}
		}
		x=p[id];
		y=p[id+v-1];
		printf("%d %d\n",x,y);
		int ls=0,nw=0;
		rep(i,k-1){
			int w=ls+1;
			while(1){
				if(a[w]>=x&&a[w]<=y)nw++;
				else nw--;
				if(nw==i){
					printf("%d %d\n",ls+1,w);
					ls=w;
					break;
				}
				w++;
			}
		}
		printf("%d %d\n",ls+1,n);
	}
	return 0;
}