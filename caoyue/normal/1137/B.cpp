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
const int N=5e5+7;
const int INF=1e9+7;
char S[N],T[N];
int nx[N];
int n,m,n0=0,n1=0,m0=0,m1=0,r0=0,r1=0;

int main(){
	scanf("%s%s",S+1,T+1);
	n=strlen(T+1);
	m=strlen(S+1);
	if(m<n){
		printf("%s\n",S+1);
		return 0;
	}
	rep(i,m)if(S[i]=='0')n0++;else n1++;
	nx[1]=0;
	REP(i,2,n){
		int o=nx[i-1];
		for(;o;o=nx[o])if(T[o+1]==T[i])break;
		if(T[o+1]==T[i])nx[i]=o+1;
		else nx[i]=o;
	}
	rep(i,n)if(T[i]=='1')m1++;else m0++;
	REP(i,nx[n]+1,n)if(T[i]=='0')r0++;else r1++;
	if(n0<m0||n1<m1){
		printf("%s\n",S+1);
		return 0;
	}
	n0-=m0;
	n1-=m1;
	printf("%s",T+1);
	while(n0>=r0&&n1>=r1){
		n0-=r0;
		n1-=r1;
		REP(i,nx[n]+1,n)putchar(T[i]);
	}
	rep0(i,n0)putchar('0');
	rep0(i,n1)putchar('1');
	puts("");
	return 0;
}