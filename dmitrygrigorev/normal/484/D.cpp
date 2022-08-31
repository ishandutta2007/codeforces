using namespace std;
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int data[n];
    for (int i=0; i < n; i++){
        cin >> data[i];
    }
    int dp[n][2];
    for (int i=0; i < n; i++){
        for (int j=0; j < 2; j++){
            dp[i][j] = 0;
        }
    }
    for (int i=1; i < n; i++){
        if (data[i] > data[i-1]) dp[i][0] = dp[i-1][0] + data[i] - data[i-1];
        if (data[i] < data[i-1]) dp[i][1] = dp[i-1][1] + data[i-1] - data[i];
        dp[i][0] = max(dp[i][0], max(dp[i-1][0], dp[i-1][1]));
        dp[i][1] = max(dp[i][1], max(dp[i-1][0], dp[i-1][1]));
    }
    cout << max(dp[n-1][0], dp[n-1][1]);
    return 0;
}