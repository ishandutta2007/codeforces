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
int a[N];

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,fl=0; scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		for(int i=30;~i;i--){
			int s1=0;
			rep(j,n)if((a[j]>>i)&1)s1++;
			if(s1%2==0)continue;
			if(s1%4==1)puts("WIN");
			else if((n-s1)&1)puts("WIN");
			else puts("LOSE");
			fl=1;
			break;
		}
		if(!fl)puts("DRAW");
	}
	return 0;
}