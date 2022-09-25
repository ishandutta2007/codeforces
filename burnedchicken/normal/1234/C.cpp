#include <bits/stdc++.h>

#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;

int main(){
	int q,n;
	char x;
	cin >> q;
	loop(q){
		cin >> n;
		bool b[n][2];
		loop(n){
			cin >> x;
			if(x>'2') b[i][0]=true;
			else b[i][0]=false;
		}
		loop(n){
			cin >> x;
			if(x>'2') b[i][1]=true;
			else b[i][1]=false;
		}
		bool dp[n][2];
		if(not b[0][0]) dp[0][0]=true;
		else dp[0][0]=false;
		if(b[0][0]&&b[0][1]) dp[0][1]=true;
		else dp[0][1]=false;
		loop(n){
			if(i==0) continue;
			dp[i][0]=dp[i][1]=false;
			if(dp[i-1][0]){
				if(not b[i][0]) dp[i][0]=true;
				if(b[i][0]&&b[i][1]) dp[i][1]=true;
			}
			if(dp[i-1][1]){
				if(not b[i][1]) dp[i][1]=true;
				if(b[i][0]&&b[i][1]) dp[i][0]=true;
			}
		}
		if(dp[n-1][1]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}