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
const int N=5e5+7;
const int INF=1e9+7;
int T,n;
char s[N];
int w[N*2];
void solve(int x,int y){
	if(!w[x]){
		if(w[x-1]){
			w[x-1]--;
			putchar('1');
			solve(x-1,y+1);
		}
		return;
	}
	if(w[x]==1){
		if(!w[x-1]){
			putchar('0');
			w[x]--;
			solve(x+1,y+1);
		}
		else{
			putchar('1');
			w[x-1]--;
			solve(x-1,y+1);
		}
		return;
	}
	w[x]--;
	putchar('0');
	solve(x+1,y+1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int nw=0,mx=-n-1;
		REP(i,-n-5,n+5)w[N+i]=0;
		rep(i,n){
			if(s[i]=='1'){
				nw--;
				w[nw+N]++;
			}
			else {
				w[nw+N]++;
				nw++;
			}
		}
		solve(N,1);
		puts("");
	}
	return 0;
}