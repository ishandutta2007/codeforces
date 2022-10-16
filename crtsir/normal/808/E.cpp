#include<bits/stdc++.h>
using namespace std;
long long n,m;
pair<pair<long long,long long>,long long>dp[300003];
vector<long long>c[3];
bool cmp(long long x,long long y){return x>y;}
void solve(long long x,long long y){
	long long p=-1;
	long long A=dp[x-y-1].first.second,B=dp[x-y-1].second;
	if(y==0&&A+1>=c[y].size())return;else if(y==0)p=dp[x-y-1].first.second+1,A++;
	if(y==1&&B+1>=c[y].size())return;else if(y==1)p=dp[x-y-1].second+1,B++;
	dp[x]=max(dp[x],make_pair(make_pair(dp[x-y-1].first.first+c[y][p],A),B));
}
int main(){
	scanf("%d%d",&n,&m);
	for(long long i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);a--;
		c[a].push_back(b);
	}
	sort(c[0].begin(),c[0].end(),cmp);
	sort(c[1].begin(),c[1].end(),cmp);
	sort(c[2].begin(),c[2].end(),cmp);
	for(int i=1;i<c[2].size();i++)c[2][i]+=c[2][i-1];
	dp[0]=make_pair(make_pair(0,-1),-1);
	for(long long i=1;i<=m;i++)
		for(long long j=0;j<min(2ll,i);j++)
			solve(i,j);
	for(long long i=1;i<=m;i++)dp[i]=max(dp[i],dp[i-1]);
	long long ans=dp[m].first.first;
	for(long long i=0;i<m/3&&i<c[2].size();i++)ans=max(ans,dp[m-i*3-3].first.first+c[2][i]);
	cout<<ans;
}