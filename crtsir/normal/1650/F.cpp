#include<bits/stdc++.h>
using namespace std;
long long dp[100003][103];
int pth[100003][103];
int a[100003];
vector<int>t[100003],p[100003],idx[100003],ans;
long long calc(int x){
	for(int i=0;i<=100;i++)
		dp[0][i]=1145141919810233;
	dp[0][0]=0;pth[0][0]=-1;
	for(int i=1;i<=t[x].size();i++){
		for(int j=0;j<=100;j++)
			dp[i][j]=dp[i-1][j],pth[i][j]=j;
		for(int j=99;j>=0;j--)
			if(dp[i][min(100,j+p[x][i-1])]>dp[i-1][j]+t[x][i-1]){
				dp[i][min(100,j+p[x][i-1])]=dp[i-1][j]+t[x][i-1];
				pth[i][min(100,j+p[x][i-1])]=j;
			}
	}
	int nwi=t[x].size(),nwj=100;
	vector<int>res;
	while(nwi){
		if(nwj!=pth[nwi][nwj])
			res.push_back(idx[x][nwi-1]);
		nwj=pth[nwi][nwj];
		nwi--;
	}
	for(int i=res.size()-1;i>=0;i--)
		ans.push_back(res[i]);
	return dp[t[x].size()][100];
}
int n,m;
void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		t[i].clear();
		p[i].clear();
		idx[i].clear();
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int E,T,P;
		cin>>E>>T>>P;E--;
		t[E].push_back(T);
		p[E].push_back(P);
		idx[E].push_back(i);
	}
	ans.clear();long long sum=0;
	for(int i=0;i<n;i++){
		sum+=calc(i);
		if(sum>a[i]){
			cout<<-1<<endl;
			return;
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]+1<<' ';cout<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)
		solve();
}