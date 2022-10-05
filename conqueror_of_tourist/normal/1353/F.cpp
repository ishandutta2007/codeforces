#include <iostream>
using namespace std;
 
typedef long long ll;
 
int main() {
 
    int t;
    cin >> t;
    
    for (int asdf = 0; asdf < t; asdf++){
        int n, m;
        cin >> n >> m;
        
        ll h[n][m];
        ll dp[n][m];
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> (h[i][j]);
                h[i][j] -= (i + j);
            }
        }
        
        ll best = -1;
        
        for (int a = 0; a < n; a++){
            for (int b = 0; b < m; b++){
                ll smol = h[a][b];
                if (smol > h[0][0]) continue;
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++){
                        dp[i][j] = -1;
                    }
                }
                
                dp[0][0] = 0;
                
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++){
                        ll delta = h[i][j] - smol;
                        if (delta >= 0 && dp[i][j] != -1){
                            dp[i][j] += delta;
                            if (i + 1 < n && (dp[i+1][j] == -1 || dp[i + 1][j] > dp[i][j]))
                                dp[i + 1][j] = dp[i][j];
                            if (j + 1 < m && (dp[i][j+1] == -1 || dp[i][j + 1] > dp[i][j]))
                                dp[i][j + 1] = dp[i][j];                            
                        }
                        else{
                            dp[i][j] = -1;
                        }
                    }
                }
                
                ll out = dp[n - 1][m - 1];
                
                if (best == -1 || (out < best && out != -1)){
                    best = out;
                }
            }
        }
        
        cout << best << "\n";
    }
    return 0;
}