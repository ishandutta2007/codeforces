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
const int N=1e6+7;
const int INF=1e9+7;
int n,k;
int to[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(n==4){
			if(k==0){
				puts("0 3");
				puts("1 2");
			}
			if(k==1){
				puts("0 2");
				puts("1 3");
			}
			if(k==2){
				puts("0 1");
				puts("2 3");
			}
			if(k==3)puts("-1");
			continue;
		}
		rep0(i,n)to[i]=n-1-i;
		if(k>=n/2){
			if(k==n-1){
				to[0]=1;
				to[1]=0;
				to[n/2-1]=n-1;
				to[n-1]=n/2-1;
				to[n/2]=n-2;
				to[n-2]=n/2;
			}
			else if(k==n/2){
				to[n/2]=n-1;
				to[n-1]=n/2;
				to[n/2-1]=0;
				to[0]=n/2-1;
			}
			else{
				int v=k-n/2;
				to[0]=n-1-v;
				to[n-1-v]=0;
				to[v]=n/2-1;
				to[n/2-1]=v;
				to[n/2]=n-1;
				to[n-1]=n/2;
			}
		}
		else{
			if(k==n/2-1){
				to[n/2-1]=n-1;
				to[n-1]=n/2-1;
				to[n/2]=0;
				to[0]=n/2;
			}
			else if(k){
				to[0]=n-1-k;
				to[k]=n-1;
				to[n-1]=k;
				to[n-1-k]=0;
			}
		}
		rep0(i,n)if(to[i]<i)printf("%d %d\n",to[i],i);
	}
	return 0;
}