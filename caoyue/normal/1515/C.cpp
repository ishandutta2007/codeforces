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
struct pir{
	int x,v;
	friend bool operator <(pir a,pir b){return a.v>b.v;}
};
priority_queue<pir>Q;
int T,n,m,x;
int h[N];
int main(){
	scanf("%d",&T);
	while(T--){
		while(!Q.empty())Q.pop();
		scanf("%d%d%d",&n,&m,&x);
		rep(i,n)scanf("%d",&h[i]);
		puts("YES");
		rep(i,m)Q.push((pir){i,0});
		rep(i,n){
			pir t=Q.top();
			Q.pop();
			printf("%d ",t.x);
			t.v+=h[i];
			Q.push(t);
		}
	}
	return 0;
}