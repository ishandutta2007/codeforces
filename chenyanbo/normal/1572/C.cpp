#include <bits/stdc++.h>
using namespace std;
const int N=3001;
int a[N], id[N], dp[N][N];
vector<int> pos[N];
 
int main(){
    int t, n;
	cin >> t;
	while(t--) {
        cin >>n;
 
        for(int i = 1; i <= n; ++i) pos[i].clear();
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            id[i] = pos[a[i]].size();
            pos[a[i]].push_back(i);
        }
 
        for(int i = n; i > 0; --i) {
            dp[i][i] = 0;
            for(int j = i + 1; j <= n; ++j) {
                if(a[i] == a[i + 1]){
                    dp[i][j] = dp[i + 1][j];
                    continue;
                }
 
                dp[i][j] = dp[i + 1][j] + 1;                                                            
 
 
                for(int p = id[i] + 1, k; p < pos[a[i]].size() && (k = pos[a[i]][p]) <= j; ++p){
                    dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j] + 1);
                }                                                            
            }                                                            
        }                                                            
        cout<<dp[1][n]<<endl;
	}
              
                                                                      
             
                                      
	return 0;
}