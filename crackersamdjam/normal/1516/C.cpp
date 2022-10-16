#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 200005;

int n, a[105];
bool dp[105][MM*2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	dp[0][MM] = 1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		for(int j = 0; j < MM*2; j++){
			if(j >= a[i])
				dp[i][j] |= dp[i-1][j-a[i]];
			if(j+a[i] < MM*2)
				dp[i][j] |= dp[i-1][j+a[i]];
		}
	}
	if(!dp[n][MM]){
		cout<<"0\n";
	}
	else{
		cout<<"1\n";
		for(int i = 1; i <= n; i++){
			if(!dp[n][MM+a[i]]){
				cout<<i<<'\n';
				break;
			}
		}
	}
}