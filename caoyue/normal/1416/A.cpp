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
const int N=3e5+7;
const int INF=1e9+7;
int n,T;
int a[N],ls[N],mx[N],w[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n){
			ls[i]=0;
			mx[i]=0;
		}
		rep(i,n){
			mx[a[i]]=max(mx[a[i]],i-ls[a[i]]);
			ls[a[i]]=i;
		}
		rep0(i,n+1)w[i]=INF;
		rep(i,n)mx[i]=max(mx[i],n+1-ls[i]);
		rep(i,n)w[mx[i]]=min(w[mx[i]],i);
		rep(i,n)w[i]=min(w[i],w[i-1]);
		rep(i,n)printf("%d ",(w[i]==INF)?-1:w[i]);
		puts("");
	}
	return 0;
}