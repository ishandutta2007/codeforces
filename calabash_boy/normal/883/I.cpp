#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
const int INF = 0x3f3f3f3f;
int n,k;
int dp[maxn];
int a[maxn];
void input(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+1+n);
}
void solve(){
	if (k==1){
		cout<<0<<endl;
		return ;
	}
	memset(dp,INF,sizeof dp);
	for (int i=2;i<=min(2*k-1,n);i++){
		dp[i] = a[i]-a[1];
	}
	int x =0;
	for (int i=2*k;i<=n;i++){
		int xx=-1;
		for (int j=max(max(k,i-2*k+1),x);j<=i-k;j++){
			int del = max(dp[j],a[i]-a[j+1]);
			if (del<dp[i]){
				xx = j;	
				dp[i]= del;
			}
		}
		x=xx;
	}
	cout<<dp[n]<<endl;
}
int main(){
	input();
	solve();
	return 0;
}