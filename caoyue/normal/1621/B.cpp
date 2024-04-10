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
int T,n;
int L[N],R[N],c[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d%d%d",&L[i],&R[i],&c[i]);
		int x=L[1],y=R[1],d=R[1]-L[1],cx=c[1],cy=c[1],cd=c[1];
		rep(i,n){
			if(L[i]<x){
				x=L[i];
				cx=c[i];
			}
			else if(L[i]==x)cx=min(cx,c[i]);
			if(R[i]>y){
				y=R[i];
				cy=c[i];
			}
			else if(R[i]==y)cy=min(cy,c[i]);
			if(R[i]-L[i]>d){
				d=R[i]-L[i];
				cd=c[i];
			}
			else if(R[i]-L[i]==d)cd=min(cd,c[i]);
			if(d==y-x)printf("%d\n",min(cd,cx+cy));
			else printf("%d\n",cx+cy);
		}
	}
	return 0;
}