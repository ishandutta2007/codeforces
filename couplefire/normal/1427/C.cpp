#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

int getDist(pair<int, int> a, pair<int, int> b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r, n; cin >> r >> n;
    int dp[n+1];
    vector<pair<pair<int, int>, pair<int, int>>> v;
    dp[0] = 0;
    v.push_back({{0,0},{0,0}});
    int ans = 0;
    int curmax[n+1];
    curmax[0] = 0;
    for(int i = 1; i<=n; i++){
        int t, x, y; cin >> t >> x >> y;
        --x; --y;
        int index = v.size()-1;
        dp[i] = -10000000;
        while(index >= 0 && t-v[index].second.first < 1000){
            if(getDist(v[index].first, {x,y}) <= t-v[index].second.first){
                if(v[index].second.second+1 > dp[i]) dp[i] = v[index].second.second+1;
            }
            --index;
        }
        if(index >= 0) dp[i] = max(dp[i], curmax[index]+1);
        curmax[i] = max(curmax[i-1], dp[i]);
        v.push_back({{x, y},{t, dp[i]}});
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}