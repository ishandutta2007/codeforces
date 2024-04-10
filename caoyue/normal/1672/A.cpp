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
int T;

int main(){
	scanf("%d",&T);
	while(T--){
		bool ans=0;
		int n; scanf("%d",&n);
		rep(i,n){
			int x; scanf("%d",&x);
			if(x%2==0)ans^=1;
		}
		if(ans)puts("errorgorn");
		else puts("maomao90");
	}
	return 0;
}