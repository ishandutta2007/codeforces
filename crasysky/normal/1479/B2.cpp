#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; 
int a[N],dp[N],la[N];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	n=unique(a+1,a+1+n)-a-1;
	rep(i,1,n){
		int p=la[a[i]]; la[a[i]]=i;
		dp[i]=dp[i-1];
		if (p) dp[i]=max(dp[i],dp[p+1]+1);
	}
	printf("%d\n",n-dp[n]); 
	return 0;
}