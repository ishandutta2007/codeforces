#include<iostream>
#include<cstring>
#include<cassert>
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
const int N=2e5+7;
const int INF=1e9+7;
int a[N],w[N],s[N][22],mn[N*2];
int n,ans=0;
int check(int L,int R){
	int k=mn[R-L+1];
	return max(s[L][k],s[R-(1<<k)+1][k]);
}
void solve(int l,int r){
	int u=check(l,r);
	int v=w[u];
	if(v-l<r-v){REP(i,l,v-1)if(w[u-a[i]]>v&&w[u-a[i]]<=r)ans++;}
	else {REP(i,v+1,r)if(w[u-a[i]]<v&&w[u-a[i]]>=l)ans++;}
	if(l!=v)solve(l,v-1);
	if(r!=v)solve(v+1,r);
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n){
		w[a[i]]=i;
		s[i][0]=a[i];
	}
	for(int i=1;(1<<i)<=n;i++){
		rep(j,n-(1<<i)+1)s[j][i]=max(s[j][i-1],s[j+(1<<(i-1))][i-1]);
		REP(j,(1<<i)+1,(1<<(i+1)))mn[j]=i;
	}
	solve(1,n);
	printf("%d\n",ans);
	return 0;
}