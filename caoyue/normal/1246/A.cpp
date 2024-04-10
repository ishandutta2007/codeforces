#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<time.h>
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
int n,p;
int bc(int x){
	int ans=0;
	while(x){
		ans+=(x&1);
		x>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&p);
	rep0(i,1000000){
		int d=n-p*i;
		if(d<0)break;
		int t=bc(d);
		if(d>=i&&t<=i){
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1"); 
	return 0;
}