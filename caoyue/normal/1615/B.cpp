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
int T;
int a[25][N];

int main(){
	int Max=200003;
	rep0(i,20){
		rep(j,Max){
			a[i][j]=a[i][j-1]+((j>>i)&1);
		}
	}
	scanf("%d",&T);
	while(T--){
		int l,r; scanf("%d%d",&l,&r);
		int ans=0;
		rep0(i,20)ans=max(ans,a[i][r]-a[i][l-1]);
		printf("%d\n",r-l+1-ans);
	}
	return 0;
}