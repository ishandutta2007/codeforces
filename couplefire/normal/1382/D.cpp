#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[2*n+1];
        for(int i = 0; i<2*n; i++) cin >> arr[i+1];
        bool dp[2*n+1][n+1];
        for(int i = 0; i<2*n+1; i++) for(int j = 0; j<n+1; j++) dp[i][j] = 0;
        dp[0][0] = 1;
        int largest[2*n+1];
        largest[0] = 0;
        for(int i = 1; i<=2*n; i++){
            int index = 0, large = 0;
            for(int j = 1; j<=i; j++){
                if(arr[j]>large){
                    index = j, large = arr[j];
                }
            }
            largest[i] = index;
        }
        for(int i = 1; i<=2*n; i++){
            for(int j = 0; j<=2*n; j++){
                int k = 2*n-j;
                dp[i][j] = 0;
                if(j >= (i-largest[i]+1)) dp[i][j] |= dp[largest[i]-1][j-(i-largest[i]+1)];
                if(k >= (i-largest[i]+1)) dp[i][j] |= dp[largest[i]-1][j];
            }
        }
        if(dp[2*n][n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}