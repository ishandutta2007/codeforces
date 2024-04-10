#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
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
int mx[N],ed[N],mn[N];
int n,Q;

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&mn[i]);
	scanf("%d",&Q);
	rep(i,Q){
		int op; scanf("%d",&op);
		if(op&1){
			int p,x; scanf("%d%d",&p,&x);
			ed[p]=i;
			mn[p]=x;
		}
		else{
			int x; scanf("%d",&x);
			mx[i]=x;
		}
	}
	for(int i=Q;i;i--)mx[i-1]=max(mx[i-1],mx[i]);
	rep(i,n)printf("%d ",max(mx[ed[i]],mn[i]));
	puts("");
	return 0;
}