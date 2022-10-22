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
#define F fflush(stdout)
const int N=1e5+7;
const int INF=1e9+7;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(n<=1900){
		int ans=0;
		rep(i,(n+1)/2){
			printf("? 1\n");
			F;
			int x; scanf("%d",&x);
			if(x!=k){
				if(x<k)ans=i;
				else ans=(1-i+n)%n+1;
				break;
			}
		}
		if(ans)printf("! %d\n",ans);
		else{
			if(n&1)printf("! %d\n",1);
			else{
				int p0=0,p1=0;
				rep(i,50){
					printf("? 2\n");
					F;
					int x; scanf("%d",&x);
					p0+=x;
					printf("? %d\n",n);
					F;
					scanf("%d",&x);
					p1+=x;
				}
				if(p0>p1)printf("! 1\n");
				else printf("! %d\n",n/2+1);
			}
		}
	}
	else{
		int T=500,st=0,nw=1,L=-1,R=-1;
		rep(i,T){
			printf("? %d\n",nw);
			F;
			int x; scanf("%d",&x);
			if(x!=k){
				if(x<k){
					L=nw%n+1;
					R=(nw+st+2+n)%n+1;
				}
				else{
					L=(nw-st-3+n)%n+1;
					R=(nw-1+n)%n+1;
				}
				break;
			}
			st++;
			nw=(nw+max(0,i-3)-1+n)%n+1;
		}
		rep(i,10){
			printf("? 1\n");
			F;
			int x; scanf("%d",&x);
		}
		for(int j=L;j!=R;j=j%n+1){
			printf("? %d\n",j);
			F;
			int x; scanf("%d",&x);
			if(x==k){
				printf("! %d\n",j);
				return 0;
			}
		}
	}
	return 0;
}