#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans[200003];
pair<long long,int>dp[200003]; 
pair<long long,int>a[200003];
void did(int x){
	if(x==-1)return;
	cnt++;
	for(int i=x;i>dp[x].second;i--)ans[a[i].second]=cnt;
	did(dp[x].second);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].first,a[i].second=i;
	sort(a,a+n);
	if(n<=5){
		cout<<a[n-1].first-a[0].first<<' '<<1<<endl;
		for(int i=0;i<n;i++)cout<<"1 ";
		return 0;
	}
	for(int i=0;i<200003;i++)dp[i].first=LONG_LONG_MAX;
	dp[2].first=a[2].first-a[0].first;dp[2].second=-1;
	dp[3].first=a[3].first-a[0].first;dp[3].second=-1;
	dp[4].first=a[4].first-a[0].first;dp[4].second=-1;
	for(int i=5;i<n;i++)
		for(int j=i-3;j>1&&i-j<7;j--)
		{ 
			if(dp[i].first>dp[j].first+a[i].first-a[j+1].first)
				dp[i].first=dp[j].first+a[i].first-a[j+1].first,
				dp[i].second=j;
		}
	cout<<dp[n-1].first<<' ';
	did(n-1);
	cout<<cnt<<endl;
	for(int i=0;i<n;i++)cout<<ans[i]<<' ';
}