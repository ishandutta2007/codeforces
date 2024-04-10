#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxm=203;

int n,m,k;
int s[maxn],t[maxn],d[maxn];
long long w[maxn];
int mxi[maxn];
vector<int> sti[maxn];
long long dp[maxn][maxm];

struct cmp{
	bool operator()(int a,int b){
		if(w[a]!=w[b])return w[a]<w[b];
		return d[a]<d[b];
	}
};
priority_queue<int,vector<int>,cmp> q;

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>s[i]>>t[i]>>d[i]>>w[i];
		sti[s[i]].push_back(i);		 
	}
	memset(mxi,-1,sizeof(mxi));
	for(int i=1;i<=n;i++){
		for(int j=0;j<sti[i].size();j++) q.push(sti[i][j]);	
		while((!q.empty())&&(t[q.top()]<i))q.pop();
		if(!q.empty())mxi[i]=q.top();
	}	
	memset(dp,0x3f,sizeof(dp));
	for(int j=0;j<=m;j++)dp[1][j]=0;	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(mxi[i]==-1){
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			}else{
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
				dp[d[mxi[i]]+1][j]=min(dp[d[mxi[i]]+1][j],dp[i][j]+w[mxi[i]]);
			}
		}
	}
	cout<<dp[n+1][m];
	return 0;
}