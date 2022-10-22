#include<iostream>
#include<cassert>
#include<cstring>
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
const int N=1e5+7;
const int INF=1e9+7;
int n;
int d[N];
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int x,y; scanf("%d%d",&x,&y);
		d[x]++; d[y]++;
	}
	rep(i,n){
		if(d[i]==2){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}