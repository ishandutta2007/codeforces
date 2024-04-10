#include<bits/stdc++.h>
using namespace std;
int cnt[13],pw[13],res,ten[20];
long long n,m,dp[103][30003];
bool vis[103][30003];
long long dfs(int mod,int now,int x){
	if(now==-1){
		if(mod==0)
			return 1;
		return 0;
	}
	if(vis[mod][x])return dp[mod][x];
	long long ret=0;
	if(now!=res-1)
		if(cnt[0]){
			cnt[0]--;x--;
			ret+=dfs(mod,now-1,x);
			cnt[0]++;x++;
		}
	for(int i=1;i<10;i++)
		if(cnt[i]){
			cnt[i]--;x-=pw[i];
			ret+=dfs((mod+ten[now]*i)%m,now-1,x);
			cnt[i]++;x+=pw[i];
		}
	vis[mod][x]=1;dp[mod][x]=ret;
	return ret;
}
int main(){
	cin>>n>>m;
	long long tmp=n;
	while(tmp!=0){
		res++;
		cnt[tmp%10]++;
		tmp/=10;
	}tmp=res;
	pw[0]=1;ten[0]=1%m;
	for(int i=1;i<res;i++)
		ten[i]=ten[i-1]*10%m;
	for(int i=0;i<10;i++)
		pw[i+1]=pw[i]*(cnt[i]+1);
	res=tmp;
	cout<<dfs(0,res-1,pw[10]-1);
}