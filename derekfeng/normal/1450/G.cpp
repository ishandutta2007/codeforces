#include<bits/stdc++.h>
using namespace std;
int n,N,a,b;
char mp[26],s[5005];
int L[26],R[26],cnt[26];
vector<char>ans;
bool dp[1100000];
int main(){
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	for(int i=1;i<=n;i++){
		char c=s[i];
		bool found=0;
		for(int j=0;j<N;j++)if(mp[j]==c){
			R[j]=i,found=1,cnt[j]++;break;
		}
		if(!found)mp[N]=s[i],L[N]=R[N]=i,cnt[N]=1,N++;
	}
	dp[0]=1;
	for(int i=1;i<(1<<N);i++){
		int ll=n+1,rr=0,cc=0;
		for(int j=0;j<N;j++)if((1<<j)&i)
			ll=min(ll,L[j]),rr=max(rr,R[j]),cc+=cnt[j];
		if(a*(rr-ll+1)<=b*cc)
			for(int j=0;j<N;j++)if((1<<j)&i)
				dp[i]|=dp[i^(1<<j)];
		if(dp[i])continue;
		int msk=0;
		for(int j=0;j<N;j++)if((1<<j)&i){
			msk|=(1<<j);
			dp[i]|=dp[msk]&dp[i^msk];
		}
	}
	for(int i=0;i<N;i++)if(dp[((1<<N)-1)^(1<<i)])ans.push_back(mp[i]);
	sort(ans.begin(),ans.end());
	printf("%d ",ans.size());for(auto c:ans)putchar(c),putchar(' ');
}