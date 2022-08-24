#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int K = 1000000007;
int32_t main(){
    int n;
    cin >> n;
    int dp[n][n+1];
    for (int i=0; i < n; i++){
        for (int j=0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i=1; i < n; i++){
        for (int j=0; j <= n; j++){
            for (int k=0; k <= n; k++){
                if (j + k - 1 > n) break;
                int p = (dp[i-1][j] * dp[i-1][k]) % K;
                if (j + k + 1 <= n){
                    dp[i][j+k+1] += p;
                    dp[i][j+k+1] %= K;
                }
                if (j + k <= n){
                    dp[i][j+k] += p;
                }
                if (j + k <= n){
                    int pl = p * j * 2;
                    dp[i][j+k] += pl;
                }
                if (j + k <= n){
                    int pl = p * k * 2;
                    dp[i][j+k] += pl;
                    dp[i][j+k] %= K;
                }
                if (j + k - 1 >= 0 && j + k - 1 <= n){
                    int ex = p * (j + k) * (j + k - 1);
                    dp[i][j+k-1] += ex;
                    dp[i][j+k-1] %= K;
                }
            }
        }
    }
    cout << dp[n-1][1] << endl;
    return 0;
}