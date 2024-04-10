#include<bits/stdc++.h>
#define int long long
const int N=5005;
using namespace std;

int n,a[N],dp[N];
bool fl[N][N];
int cnt[N];
vector<int> pos[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		pos[i].clear();
		pos[i].push_back(0); 
		for(int j=1;j<=n;j++)
			fl[i][j]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pos[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cnt[j]=0;
		int mx=0; 
		fl[i][i-1]=1;
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;mx=max(mx,cnt[a[j]]);
			if((j-i+1)&1)continue;
			if(mx<=(j-i+1)/2)fl[i][j]=1;
		}
	}
	fl[n+1][n]=1;
	int res=n&1;
	for(int i=1;i<=n;i++){
		memset(dp,-2,sizeof(dp));
		dp[0]=0;
		for(auto x:pos[i]){
			for(auto y:pos[i]){
				if(y>=x)break;
				if(!fl[y+1][x-1])continue;
				dp[x]=max(dp[x],dp[y]+1);
				if(fl[x+1][n])
					res=max(res,dp[x]);
			}
		}
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}