#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+100;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int a[maxn];
LL dp[maxn][25];
int cnt[maxn];
int p,q;
LL now;
int n,k;
void solve(int dep,int l,int r,int opl,int opr){
	if (l>r)return ;
	int mid =l+r >>1;
	int temp = min(opr,mid)+1;
	while (p<temp)now-=--cnt[a[p++]];
	while (q>mid)now-=--cnt[a[q--]];
	while (p>temp)now+=cnt[a[--p]]++;
	while (q<mid)now+=cnt[a[++q]]++;
	int opx =-1;
	for (int i=temp-1;i>=opl;i--){
		now+=cnt[a[--p]]++;
		if (now+dp[i-1][dep-1]<dp[mid][dep]){
			dp[mid][dep]=now+dp[i-1][dep-1];
			opx=i;
		}
	}
	solve(dep,l,mid-1,opl,opx);
	solve(dep,mid+1,r,opx,opr);
}
void print(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=k;j++){
			printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for (int i=0;i<=n;i++){
		for (int j=0;j<=k;j++){
			dp[i][j]=INF;
		}
	}
	dp[0][0]=0;
	q=now=0;
	p=1;
	for (int i=1;i<=k;i++){
		solve(i,i,n,i,n);
	}
//	print();
	printf("%I64d\n",dp[n][k]);
	return 0;
}