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
const int N=5007;
const int INF=1e9+7;
struct pir{int op,x,y;}p[N];
int T;

int main(){
	scanf("%d",&T);
	rep(i,T){
		int n,cnt=0; scanf("%d",&n);
		rep(i,n){
			int x; scanf("%d",&x);
		}
		for(int i=1;i<=n;i+=2){
			p[++cnt]=(pir){1,i,i+1};
			p[++cnt]=(pir){2,i,i+1};
			p[++cnt]=(pir){1,i,i+1};
			p[++cnt]=(pir){1,i,i+1};
			p[++cnt]=(pir){2,i,i+1};
			p[++cnt]=(pir){1,i,i+1};
		}
		printf("%d\n",cnt);
		rep(i,cnt)printf("%d %d %d\n",p[i].op,p[i].x,p[i].y);
	}
	return 0;
}