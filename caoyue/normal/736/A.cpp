#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
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
ll n,a,b,nw=1;

int main(){
	scanf("%I64d",&n);
	a=0,b=1;
	while(b<n){
		a=(b+a+1);
		swap(a,b);
		nw++;
	}
	cout<<nw-1<<endl;
	return 0;
}