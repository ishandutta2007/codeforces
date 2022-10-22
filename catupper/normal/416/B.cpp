#include<iostream>
#include<algorithm>
using namespace std;
typedef long long Int;

Int n, m, t;
Int dp[54000][5];
int main(){
	cin >> m >> n;
	for(int i = 1;i <= m;i++){
		if(i > 1)cout << " ";
		for(int j = 0;j < n;j++){
			cin >> t;
			dp[i][j] = dp[i - 1][j] + t;
			if(j){
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + t);
			}
		}
    	cout << dp[i][n - 1];
	}                        
	cout << endl;
	return 0;
}