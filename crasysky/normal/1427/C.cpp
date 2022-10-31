#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; int t[N],x[N],y[N],dp[N],mx[N];
int aabs(int x){ return x>=0?x:-x; }
int main(){
	int r,n; scanf("%d%d",&r,&n);
	rep(i,1,n) scanf("%d%d%d",&t[i],&x[i],&y[i]);
	x[0]=y[0]=1;
	rep(i,1,n){
		int j=i-1; dp[i]=-1e9;
		for (;j>=0&&t[i]-t[j]<=2*r;--j)
			if (aabs(x[i]-x[j])+aabs(y[i]-y[j])<=t[i]-t[j])
				dp[i]=max(dp[i],dp[j]+1);
		if (j>=0) dp[i]=max(dp[i],mx[j]+1);
		mx[i]=max(mx[i-1],dp[i]);
	}
	printf("%d\n",mx[n]);
	return 0;
}