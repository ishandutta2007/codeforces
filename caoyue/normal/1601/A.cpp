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
const int N=2e5+7;
const int INF=1e9+7;
int T,n;
int v[35],a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		memset(v,0,sizeof(v));
		rep(i,n)rep0(j,30)if((a[i]>>j)&1)v[j]++;
		rep(i,n){
			bool fl=1;
			rep0(j,30)if(v[j]%i!=0){
				fl=0;
				break;
			}
			if(fl)printf("%d ",i);
		}
		puts("");
	}
	return 0;
}