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
const int K = 6000;
int n, k, ai;
vector<int> data;
int dp[201][K+1];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
    }
    for (int i=0; i <= n; i++){
        for (int j=0; j <= K; j++){
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for (int i=0; i < n; i++){
        int f = 0, t = 0;
        while (data[i] % 5 == 0){
            f ++;
            data[i] /= 5;
        }
        while (data[i] % 2 == 0){
            t ++;
            data[i] /= 2;
        }
        for (int j=min(i+1, k); j > 0; j--){
            for (int p=K; p>=f; p--){
                dp[j][p] = max(dp[j][p], dp[j-1][p-f] + t);
            }
        }
    }
    int ans = 0;
    for (int i=0; i <= K; i++){
        ans = max(ans, min(i, dp[k][i]));
    }
    cout << ans << endl;
    return 0;
}