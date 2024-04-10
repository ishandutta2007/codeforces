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
int T,n;
ll W;
ll w[N];
bool vis[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%I64d",&n,&W);
		rep(i,n)scanf("%I64d",&w[i]);
		rep(i,n)vis[i]=0;
		ll s=0,fl=0,id;
		rep(i,n){
			if(w[i]>W)continue;
			if(w[i]>=(W+1)/2){
				fl=1;
				id=i;
				break;
			}
			vis[i]=1;
			s+=w[i];
			if(s>=(W+1)/2)break;
		}
		if(fl){
			puts("1");
			printf("%I64d\n",id);
		}
		else{
			if(s>=(W+1)/2){
				int ans=0;
				rep(i,n)if(vis[i])ans++;
				printf("%d\n",ans);
				rep(i,n)if(vis[i])printf("%d ",i);
				puts("");
			}
			else puts("-1");
		}
	}
	return 0;
}