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
const int N=1e5+7;
const int INF=1e9+7;
int T,cnt=0;
char s1[N],s2[N];
int a[N],b[N],c[N*2];
void solve(int l,int r,int o,int v){
	if(l==r){
		if((a[r]^v)!=b[1])c[++cnt]=r-l+1;
		return;
	}
	if(o){
		if((a[r]^v)==b[r-l+1])c[++cnt]=1;
		c[++cnt]=r-l+1;
		solve(l,r-1,o^1,v^1);
	}
	else{
		if((a[l]^v)==b[r-l+1])c[++cnt]=1;
		c[++cnt]=r-l+1;
		solve(l+1,r,o^1,v^1);
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		rep(i,n)a[i]=(s1[i]-'0');
		rep(i,n)b[i]=(s2[i]-'0');
		cnt=0;
		solve(1,n,0,0);
		printf("%d ",cnt);
		rep(i,cnt)printf("%d ",c[i]);
		puts("");
	}
	return 0;
}