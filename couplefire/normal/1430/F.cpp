#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2005;
const int INF = 1e15;

int n, k, dp[N];
array<int, 3> arr[N];

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    fill(dp, dp+N, INF);
    dp[n] = 0;
    for(int i = n-1; i>=0; i--){
        int rem = k, cnt = 0;
        for(int j = i; j<n; j++){
            int add = (arr[j][2]-rem+k-1)/k;
            if(add > arr[j][1]-arr[j][0]) break;
            cnt += arr[j][2]; rem = rem+add*k-arr[j][2];
            if(j == n-1) dp[i] = min(dp[i], cnt);
            else if(add < arr[j+1][0]-arr[j][0]) dp[i] = min(dp[i], cnt+rem+dp[j+1]);
        }
    }
    cout << (dp[0]==INF?-1:dp[0]) << endl;
}