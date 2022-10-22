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
const int N=2e5+7;
const int INF=1e9+7;
int n,k;
char s[N];

int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int L1=INF,R1=0,L0=INF,R0=0,s0=0,s1=0;
	rep(i,n){
		if(s[i]=='0'){
			L0=min(L0,i);
			R0=max(R0,i);
			s0++;
		}
		if(s[i]=='1'){
			L1=min(L1,i);
			R1=max(R1,i);
			s1++;
		}
	}
	if(!s0||!s1){
		puts("tokitsukaze");
		return 0;
	}
	if(R0-L0+1<=k||R1-L1+1<=k){
		puts("tokitsukaze");
		return 0;
	}
	if(R0-L0==k&&R1-L1==k&&(!(R0<L1))&&(!(R1<L0))){
		puts("quailty");
		return 0;
	}
	puts("once again");
	return 0;
}