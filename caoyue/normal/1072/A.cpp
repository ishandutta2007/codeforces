#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
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

int main(){
	int n,m,ans=0,k; scanf("%d%d%d",&n,&m,&k);
	rep(i,k){
		ans=ans+n*2+m*2-4;
		m-=4;
		n-=4;
	}
	printf("%d\n",ans); 
	return 0;
}