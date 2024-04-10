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
const int N=1e5+7;
const int INF=1e9+7;
int n,X,Y;
int a[N],x[N],y[N];

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&x[i],&y[i]);
	if(n&1){puts("NO"); return 0;}
	X=x[1]+x[n/2+1];
	Y=y[1]+y[n/2+1];
	rep(i,n/2)if(x[i]+x[i+n/2]!=X||y[i]+y[i+n/2]!=Y){puts("NO"); return 0;}
	puts("YES");
	return 0;
}