#include<bits/stdc++.h>
using namespace std;
#define N 35000
#define A 35000
#define M 50
#define inf 0x3f3f3f3f
int n,a[N+1],dp[N+1][M+1],prv[N+1],las[A+1];
struct node{int l,r,mx,lz;}nd[N<<3];
#define l(x) nd[x].l
#define r(x) nd[x].r
#define mx(x) nd[x].mx
#define lz(x) nd[x].lz
void bld(int stp,int l=0,int r=n-1,int p=1){
	l(p)=l;r(p)=r;lz(p)=0;
	if(l==r){mx(p)=dp[l][stp];return;}
	int mid=l+r>>1;
	bld(stp,l,mid,p<<1);bld(stp,mid+1,r,p<<1|1);
	mx(p)=max(mx(p<<1),mx(p<<1|1));
//	printf("%d([%d,%d]):%d\n",p,l,r,mx(p));
}
void spr(int p){
	if(lz(p)){
		int x=lz(p);lz(p)=0;
		mx(p<<1)+=x;mx(p<<1|1)+=x;
		lz(p<<1)+=x;lz(p<<1|1)+=x;
	}
}
void chg(int l,int r,int p=1){
	if(l<=l(p)&&r>=r(p)){mx(p)++;lz(p)++;return;}
	spr(p);
	int mid=l(p)+r(p)>>1;
	if(l<=mid)chg(l,r,p<<1);
	if(r>mid)chg(l,r,p<<1|1);
	mx(p)=max(mx(p<<1),mx(p<<1|1));
}
int ask(int l,int r,int p=1){
	if(l<=l(p)&&r>=r(p))return mx(p);
	spr(p);
	int mid=l(p)+r(p)>>1,res=-inf;
	if(l<=mid)res=ask(l,r,p<<1);
	if(r>mid)res=max(res,ask(l,r,p<<1|1));
	return res;
}
int main(){
	int m,i,j;scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)prv[i]=las[a[i]],las[a[i]]=i;
	for(i=0;i<=n;i++)for(j=i+1;j<=m;j++)dp[i][j]=-inf;
	for(i=1;i<=n;i++)dp[i][0]=-inf;
	for(j=1;j<=m;j++){
		bld(j-1);
		for(i=1;i<j;i++)chg(prv[i],i-1);
//		for(i=0;i<n;i++)cout<<ask(i,i)<<" ";puts("");
		for(i=j;i<=n;i++){
			chg(prv[i],i-1);
//			for(int k=0;k<n;k++)cout<<ask(k,k)<<" ";puts("");
			dp[i][j]=ask(j-1,i-1);
//			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	printf("%d",dp[n][m]);
	return 0;
}
/*1
4 1
1 2 2 1
*/
/*2
7 2
1 3 3 1 4 4 4
*/
/*3
8 3
7 7 8 7 7 8 1 7
*/