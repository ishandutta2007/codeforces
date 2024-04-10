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
int mn[N*2],a[N];
struct pir{int x,d;};
pir mx[22][N],mi[22][N];
int T,n;
pir merx(pir a,pir b){return (a.x>b.x)?a:b;}
pir meri(pir a,pir b){return (a.x<b.x)?a:b;}
int ckx(int L,int R){
	int k=mn[R-L+1];
	return merx(mx[k][L],mx[k][R-(1<<k)+1]).d;
}
int cki(int L,int R){
	int k=mn[R-L+1];
	return meri(mi[k][L],mi[k][R-(1<<k)+1]).d;
}
int si(int a,int b);
int sx(int a,int b){
	if(a==b)return 0;
	return 1+si(a,cki(min(a,b),max(a,b)));
}
int si(int a,int b){
	if(a==b)return 0;
	return 1+sx(a,ckx(min(a,b),max(a,b)));
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,n)scanf("%d",&a[i]);
		if(n==1){
			puts("0");
			continue;
		}
		rep(i,n)mx[0][i]=mi[0][i]=(pir){a[i],i};
		for(int i=1;(1<<i)<=n;i++){
			rep(j,n-(1<<i)+1){
				mx[i][j]=merx(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
				mi[i][j]=meri(mi[i-1][j],mi[i-1][j+(1<<(i-1))]);
			}
			REP(j,(1<<i)+1,(1<<(i+1)))mn[j]=i;
		}
		int u1=ckx(1,n),u2=cki(1,n),ans=1;
		if(u1<u2){
			ans+=sx(1,u1);
			ans+=si(n,u2);
		}
		else{
			ans+=sx(n,u1);
			ans+=si(1,u2);
		}
		printf("%d\n",ans);
	}
	return 0;
}