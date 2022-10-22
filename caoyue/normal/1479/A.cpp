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
#define F fflush(stdout)
const int N=1e5+7;
const int INF=1e9+7;
int n;
int a[N];
int query(int x){
	if(x==0||x==n+1)return INF;
	printf("? %d\n",x);
	F;
	int v; scanf("%d",&v);
	return v;
}
void check(int l,int r){
	if(r-l+1<=10){
		REP(i,l-1,r+1)a[i]=query(i);
		REP(i,l,r){
			if(a[i]<min(a[i-1],a[i+1])){
				printf("! %d\n",i);
				return;
			}
		}
	}
	int mid=(l+r)>>1;
	int h1=query(mid+1),h2=query(mid);
	if(h1<h2)check(mid+1,r);
	else check(l,mid);
}
int main(){
	scanf("%d",&n);
	check(1,n);
	return 0;
}