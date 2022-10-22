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
const int N=7;
const int INF=1e9+7;
int T,x1,y1,x2,y2;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)printf("%d\n",abs(y1-y2));
		else if(y1==y2)printf("%d\n",abs(x1-x2));
		else printf("%d\n",abs(x1-x2)+abs(y1-y2)+2);
	}
	return 0;
}