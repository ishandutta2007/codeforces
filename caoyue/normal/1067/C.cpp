#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<vector>
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
int n,h1=0,h2=0;

int main(){
	scanf("%d",&n);
	n--;
	printf("0 0\n");
	while(n){
		h1++;
		if(n){printf("%d %d\n",0,h1); n--;}
		if(n){printf("%d %d\n",h1,0); n--;}
		if(n){printf("%d %d\n",0,-h1); n--;}
		if(n){printf("%d %d\n",-h1,0); n--;}
	}
	return 0;
}