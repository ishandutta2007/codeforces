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
int T;
int n,x;
int a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		rep(i,n)scanf("%d",&a[i]);
		int mx=0,fl=1;
		rep(i,n){
			mx=max(mx,a[i]);
			if(a[i]==x){
				puts("1");
				fl=0;
				break;
			}
		}
		if(fl)printf("%d\n",max(2,(x-1)/mx+1));
	}
	return 0;
}