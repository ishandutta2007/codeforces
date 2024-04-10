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
const int N=3e5+7;
const int INF=1e9+7;
int T,n;
int a[N],v[N],Ans[N];
void solve(int l,int r,int x,int y){
	if(x==1)return;
	if(!v[y]){
		REP(i,2,x)Ans[i]=0;
		return;
	}
	Ans[x]=1;
	if(v[y]>1){
		REP(i,2,x-1)Ans[i]=0;
		return;
	}
	if(a[l]!=y&&a[r]!=y){
		REP(i,2,x-1)Ans[i]=0;
		return;
	}
	if(a[l]==y)solve(l+1,r,x-1,y+1);
	else solve(l,r-1,x-1,y+1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		rep(i,n)v[i]=0;
		rep(i,n)v[a[i]]++;
		if(!v[1]){
			rep(i,n)putchar('0');
			puts("");
			continue;
		}
		bool fl=1;
		rep(i,n)if(!v[i])fl=0;
		Ans[1]=fl;
		solve(1,n,n,1);
		rep(i,n)putchar('0'+Ans[i]);
		puts("");
	}
	return 0;
}