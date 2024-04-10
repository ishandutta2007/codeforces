// https://codeforces.com/contest/1077/problem/F2
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define INF 10000000000000009
long long n, k, x;
long long arr[MAXN];
long long dp[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> x;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    for(int i = 0; i<MAXN; i++) dp[i][0] = -INF;
    dp[0][0] = 0;
    deque<pair<long long, int>> q;
    for(int j = 1; j<=x; j++){
        for(int i = 1; i<=n; i++){
            while(!q.empty() && i-q.back().second > k) q.pop_back();
            long long t = dp[i-1][j-1];
            while(!q.empty() && q.front().first <= t) q.pop_front();
            q.push_front({t, i-1});
            dp[i][j] = q.back().first+arr[i];
        }
        q.clear();
    }
    long long ans = -1;
    for(int i = n; i>n-k; i--){
        ans = max(ans, dp[i][x]);
    }
    cout << ans << endl;
}