#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
const LL Inf=1e12;
int n,k,a[N],cnt[N],nl=1,nr,now,lst;LL dp[2][N],res;
void make(int l,int r){
	while(nl>l)res+=(LL)cnt[a[--nl]]++;
	while(nr<r)res+=(LL)cnt[a[++nr]]++;
	while(nl<l)res-=(LL)--cnt[a[nl++]];
	while(nr>r)res-=(LL)--cnt[a[nr--]];
}
void solve(int l,int r,int L,int R){
	if(l>r||L>R)return;
	int mid=(l+r)>>1,trsid;LL nowd;
	for(int i=L;i<=min(R,mid);i++){
		make(i+1,mid);nowd=dp[lst][i]+res;
		if(nowd<dp[now][mid])dp[now][mid]=nowd,trsid=i;
	}
	solve(l,mid-1,L,trsid);solve(mid+1,r,trsid,R);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)dp[1][i]=dp[1][i-1]+(LL)cnt[a[i]],cnt[a[i]]++;
	for(int i=1;i<=n;i++)cnt[i]=0,dp[0][i]=Inf;
	for(int i=2;i<=k;i++){
		now=i&1;lst=now^1;solve(1,n,0,n);
		for(int j=1;j<=n;j++)dp[lst][j]=Inf;
	}
	printf("%lld\n",dp[k&1][n]);
	return 0;
}