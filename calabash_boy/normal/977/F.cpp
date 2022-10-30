#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int n,a[maxn];
int dp[maxn],nxt[maxn];
map<int,pair<int,int> > cnt;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	for (int i=n-1;i>=0;i--){
		if (cnt[a[i]+1].first){
			dp[i] = cnt[a[i]+1].first+1;
			nxt[i] = cnt[a[i]+1].second;
		}else{
			dp[i] =1;
			nxt[i] =n;
		}
		if (dp[i]>cnt[a[i]].first){
			cnt[a[i]] = make_pair(dp[i],i);
		}
	}
	int maxAns =-1;
	int maxIndex =-1;
	for (int i=0;i<n;i++){
		if (dp[i]>maxAns){
			maxAns = dp[i];
			maxIndex = i;
		}
	}
	printf("%d\n",maxAns);
	int temp = maxIndex;
	while (temp<n){
		printf("%d ",temp+1);
		temp = nxt[temp];
	}
	return 0;
}