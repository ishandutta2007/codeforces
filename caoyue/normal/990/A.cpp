#include<bits/stdc++.h>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
ll n,m,a,b;

int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&a,&b);
	printf("%I64d\n",min(n%m*b,(m-n%m)*a));
	return 0;
}