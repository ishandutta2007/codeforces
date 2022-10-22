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
bool a[N][2];
int n,q,cnt=0;
int main(){
	scanf("%d%d",&n,&q);
	rep(i,q){
		int x,y; scanf("%d%d",&y,&x);
		y--;
		a[x][y]^=1;
		if(a[x][y^1])cnt+=a[x][y]?1:-1;
		if(a[x-1][y^1])cnt+=a[x][y]?1:-1;
		if(a[x+1][y^1])cnt+=a[x][y]?1:-1;
		if(cnt)puts("No");
		else puts("Yes");
	}
	return 0;
}