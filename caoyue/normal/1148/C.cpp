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
const int N=3e5+7;
const int INF=1e9+7;
int a[N],w[N],g1[N*10],g2[N*10];
int n,m=0;
void swa(int x,int y){
	if(x==y)return;
	g1[++m]=x;
	g2[m]=y;
	if(x>y)swap(g1[m],g2[m]);
	swap(w[a[x]],w[a[y]]);
	swap(a[x],a[y]);
}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
		w[a[i]]=i;
	}
	REP(i,2,n-1){
		int q,p=(i>n/2)?1:n;
		if(w[i]>n/2){
			swa(w[i],1);
			q=1;
		}
		else {
			swa(w[i],n);
			q=n;
		}
		if(p!=q)swa(p,q);
		swa(i,p);
	}
	if(a[1]==n)swa(1,n);
	printf("%d\n",m);
	rep(i,m)printf("%d %d\n",g1[i],g2[i]);
	return 0;
}