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
const int N=107;
const int INF=1e9+7;
int T;
int a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		int s=0,mx=0;
		rep(i,n){
			s+=a[i];
			mx=max(mx,a[i]);
		}
		if(mx+mx>s){
			puts("T");
			continue;
		}
		if(s&1)puts("T");
		else puts("HL");
	}
	return 0;
}