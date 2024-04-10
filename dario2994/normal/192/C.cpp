#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;

int na[500500][2];
int l[500500];
int dp[26][26];

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		na[i][0]=char(s[0])-'a';
		na[i][1]=char(s[s.size()-1])-'a';
		l[i]=s.size();
	}
	//for(int i=0;i<n;i++)cout << na[i][0] << " " << na[i][1] << endl;
	for(int i=n-1;i>=0;i--){
		int u=na[i][0];
		int v=na[i][1];
		for(int x=0;x<26;x++)if(dp[v][x]>0)dp[u][x]=max(dp[u][x],l[i]+dp[v][x]);
		dp[u][v]=max(l[i],dp[u][v]);
	}
	int res=0;
	for(int i=0;i<26;i++)res=max(res,dp[i][i]);
	//for(int i=0;i<26;i++)cout << dp[i][i];
	cout << res;
}