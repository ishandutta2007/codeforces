#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;
const int M = 22;
const int X = (1<<22) - 1;

int n;
int arr[N], dp[1<<M], ndp[1<<M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i = 0; i < (1<<M); i++) dp[i] = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[arr[i]] = arr[i];
        dp[arr[i]|1] = arr[i];
    }
    for(int j = 1; j < M; j++) {
        for(int i = 0; i < (1<<M); i++) {
            ndp[i] = dp[i];
            if((i >> j) & 1) ndp[i] = max(ndp[i], dp[i - (1<<j)]);
        }
        for(int i = 0; i < (1<<M); i++) dp[i] = ndp[i];
    }
    for(int i = 0; i < n; i++) {
        cout << dp[X - arr[i]] << ' ';
    }
    
    return 0;
}