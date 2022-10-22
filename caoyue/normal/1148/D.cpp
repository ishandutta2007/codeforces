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
int a[N],b[N],g1[N],g2[N];
int n,c1=0,c2=0;
bool cmp1(int x,int y){return b[x]>b[y];}
bool cmp2(int x,int y){return b[x]<b[y];}

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",&a[i],&b[i]);
	rep(i,n){
		if(a[i]<b[i])g1[++c1]=i;
		else g2[++c2]=i;
	}
	if(c1>c2){
		sort(g1+1,g1+c1+1,cmp1);
		printf("%d\n",c1);
		rep(i,c1)printf("%d ",g1[i]);
		puts("");
	}
	else{
		sort(g2+1,g2+c2+1,cmp2);
		printf("%d\n",c2);
		rep(i,c2)printf("%d ",g2[i]);
		puts("");
	}
	return 0;
}