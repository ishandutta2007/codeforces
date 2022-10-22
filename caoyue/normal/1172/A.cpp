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
const int N=4e5+7;
const int INF=1e9+7;
int a[N],b[N],c[N];
int n;
void ins(int L,int R,int v){
	c[L]+=v;
	c[R+1]-=v;
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)scanf("%d",&b[i]);
	rep(i,n)if(a[i])ins(n-a[i]+1,2*n,1);
	rep(i,n){
		if(b[i]){
			if(i>=b[i])ins(i-b[i],i-b[i],1);
			ins(i-b[i]+1+n,n*2,1);
		}
	}
	rep(i,2*n)c[i]+=c[i-1];
	rep0(i,2*n+1){
		if(c[i]==n){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}