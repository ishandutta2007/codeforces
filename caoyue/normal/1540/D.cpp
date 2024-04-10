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
const int M=144;
const int M2=720;
const int INF=1e9+7;
int n,q,m,K,T;
int b[N],ib[N],ik[N],L[M2],R[M2],ls[M2],ld[M2][M*M],X[M2][M],V1[M2][N+M],V2[M2][M*M],V3[M2][M];
void Max(int x,int l,int v){
	int h1=K,h2=(l/T/T+1)*T-1,h3=(l/T+1)*T-1,g1=l/T/T,g2=l/T,g3=l;
	REP(i,g1+1,h1)V3[x][i]=max(V3[x][i],v);
	REP(i,g2+1,h2)V2[x][i]=max(V2[x][i],v);
	if(ld[x][g2]!=ls[x]){
		ld[x][g2]=ls[x];
		int o=g2*T;
		REP(i,o,h3)V1[x][i]=0;
	}
	REP(i,g3,h3)V1[x][i]=max(V1[x][i],v);
}
void bd(int x){
	for(int i=R[x];i>=L[x];i--){
		int nw=b[i]+1;
		for(int j=i+1;j<=R[x];j++)nw+=(b[j]<nw);
		ib[i]=nw;
	}
	REP(i,L[x],R[x])X[x][i-L[x]+1]=ib[i];
	sort(X[x]+1,X[x]+R[x]-L[x]+2);
	ls[x]++;
	rep0(i,K+1)V3[x][i]=0;
	rep0(i,n/T+1)V2[x][i]=0;
	rep(i,R[x]-L[x]+1)Max(x,X[x][i]-i+1,i);
}
int check(int x,int y){
	return max(V3[x][y/T/T],max(V2[x][y/T],(ld[x][y/T]==ls[x])?V1[x][y]:-INF));
}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&b[i]);
	rep(i,n)b[i]=i-b[i]-1;
	T=(n<=3000)?sqrt(n):140;
	K=n/T/T;
	for(int d=1,i=1;i<=n;i+=T,d++){
		rep0(j,T){
			if(i+j>n)break;
			ik[i+j]=d;
		}
		L[d]=i;
		R[d]=min(n,i+T-1);
		m=d;
	}
	rep(i,m)bd(i);
	scanf("%d",&q);
	while(q--){
		int op,x; scanf("%d%d",&op,&x);
		if(op==1){
			int y; scanf("%d",&y);
			b[x]=x-y-1;
			bd(ik[x]);
		}
		else{
			int nw=ib[x];
			REP(j,ik[x]+1,ik[n])nw+=check(j,nw);
			printf("%d\n",nw);
		}
	}
	return 0;
}