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
int T,a;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&a);
		int ans=1;
		while(a){
			ans<<=1;
			a-=(a&-a);
		}
		printf("%d\n",ans);
	}
	return 0;
}