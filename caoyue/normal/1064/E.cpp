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
const int N=1000;
const int INF=1e9+7;
int n;
void fp(ll q,ll &x,ll &y){
	x=1000-q%1000;
	if(x<0)x+=1000;
	y=(x+q)/1000;
	if(y<0){
		x=x-y*1000;
		y=0;
	}
}
int main(){
	scanf("%d",&n);
	ll L=0,R=1e11;
	rep(i,n){
		ll q=(L+R)/2,x,y;
		fp(q,x,y);
		if(x<0||x>1e9||y<0||y>1e9)return 0;
		printf("%I64d %I64d\n",x,y);
		fflush(stdout);
		char k[17]; scanf("%s",k);
		if(k[0]=='b')L=q;
		else R=q;
	}
	ll q=(L+R)>>1,x,y;
	fp(q,x,y);
	printf("%I64d %I64d %I64d %I64d\n",x,y,x+1000,y+1);
	return 0;
}