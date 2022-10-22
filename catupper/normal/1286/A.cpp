#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int dp[110][110][110][2];
Int n, p;
int main(){
    cin >> n;
    for(int i = 0;i < 110;i++)
        for(int j = 0;j < 110;j++)
            for(int k = 0;k < 110;k++)
                dp[i][j][k][0] = dp[i][j][k][1] = INF;
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    for(int i = 1;i <= n;i++){
        cin >> p;
        for(int j = 0;j <= n;j++){
            for(int k = 0;k <= n;k++){
                if(p == 0){
                    dp[i][j][k][0] = min(j?dp[i-1][j-1][k][0]:INF,
                                         j?dp[i-1][j-1][k][1]+1:INF);
                    
                    dp[i][j][k][1] = min(k?dp[i-1][j][k-1][1]:INF,
                                         k?dp[i-1][j][k-1][0]+1:INF);
                }
                else if(p % 2 == 0){
                    dp[i][j][k][0] = min(j?dp[i-1][j-1][k][0]:INF,
                                         j?dp[i-1][j-1][k][1]+1:INF);
                    
                    dp[i][j][k][1] = INF;
                }
                else{
                    dp[i][j][k][0] = INF;
                  
                    dp[i][j][k][1] = min(k?dp[i-1][j][k-1][1]:INF,
                                         k?dp[i-1][j][k-1][0]+1:INF);
                }
            }
        }
    }
    cout << min(dp[n][n/2][n-n/2][0], dp[n][n/2][n-n/2][1]) << endl;
    return 0;
}