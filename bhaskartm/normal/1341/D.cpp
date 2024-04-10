#include <bits/stdc++.h>
using namespace std;
int dp[128][9];
bool dp2[2005][2005];
vector<int>v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	
	cin>>n>>k;
	v.push_back(119);
	v.push_back(18);
	v.push_back(93);
	v.push_back(91);
	v.push_back(58);
	v.push_back(107);
	v.push_back(111);
	v.push_back(82);
	v.push_back(127);
	v.push_back(123);
	for(int i=0; i<128; i++){
		for(int j=0; j<9; j++){
			dp[i][j]=-1;
		}
	}
	
	for(int i=0; i<(1<<8); i++){
		for(int j=0; j<v.size(); j++){
			if((i&v[j])==i){
				
				int x=(__builtin_popcount(v[j]))-(__builtin_popcount(i));
				
				dp[i][x]=max(dp[i][x], j);
			}
		}
	}
	
	vector<int>val;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		int x=0;
		int p=1;
		for(int j=6; j>=0; j--){
			if(s[j]=='0'){
				p=2*p;
				
			}
			else{
				x=x+p;
				p=p*2;
			}
		}
		val.push_back(x);
	}
	
	for(int i=0; i<8; i++){
		if(dp[val[n-1]][i]!=-1){
			dp2[n-1][i]=true;
		}
	}
	
	for(int i=n-2; i>=0; i--){
		for(int j=0; j<=k; j++){
			for(int l=0; l<8; l++){
				if(dp2[i+1][j-l]==true && dp[val[i]][l]!=-1){
					dp2[i][j]=true;
					break;
				}
			}
		}
	}
	if(dp2[0][k]==false){
		cout<<-1;
		return 0;
	}
	for(int i=0; i<n; i++){
		if(i==n-1){
			cout<<dp[val[i]][k];
			return 0;
		}
		int maxi=0;
		int index=0;
		for(int j=0; j<8; j++){
			if(dp2[i+1][k-j]==true){
				if(dp[val[i]][j]>=maxi){
					index=j;
					maxi=dp[val[i]][j];
				}
			}
		}
		k=k-index;
		cout<<maxi;
	}
	return 0;
}