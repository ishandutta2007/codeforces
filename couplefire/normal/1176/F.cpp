#include <bits/stdc++.h>
using namespace std;
#define INF 1e16
long long m;
vector<pair<long long, long long>> arr;

long long subtract(long long a, long long b){return (a-b+10)%10;}

long long check(long long num){
    vector<long long> arr1;
    vector<long long> arr2;
    vector<long long> arr3;
    for(long long i = 0; i<m; i++){
        if(arr[i].first == 1) arr1.push_back(arr[i].second);
        else if(arr[i].first == 2) arr2.push_back(arr[i].second);
        else arr3.push_back(arr[i].second);
    }
    sort(arr1.rbegin(), arr1.rend());
    sort(arr2.rbegin(), arr2.rend());
    sort(arr3.rbegin(), arr3.rend());
    if(num == 0) return 0;
    if(num == 1){
        long long ans = -INF;
        if(arr1.size()) ans = max(ans, arr1.front());
        if(arr2.size()) ans = max(ans, arr2.front());
        if(arr3.size()) ans = max(ans, arr3.front());
        return ans;
    }
    if(num == 2){
        long long ans = -INF;
        if(arr1.size() > 1) ans = max(ans, arr1[0]+arr1[1]);
        if(arr1.size() && arr2.size()) ans = max(ans, arr1[0]+arr2[0]);
        return ans;
    }
    long long ans = -INF;
    if(arr1.size() > 2) ans = max(ans, arr1[0]+arr1[1]+arr1[2]);
    return ans;
}

long long check10(long long num){
    vector<long long> arr1;
    vector<long long> arr2;
    vector<long long> arr3;
    for(long long i = 0; i<m; i++){
        if(arr[i].first == 1) arr1.push_back(arr[i].second);
        else if(arr[i].first == 2) arr2.push_back(arr[i].second);
        else arr3.push_back(arr[i].second);
    }
    sort(arr1.rbegin(), arr1.rend());
    sort(arr2.rbegin(), arr2.rend());
    sort(arr3.rbegin(), arr3.rend());
    if(num == 0) return 0;
    if(num == 1){
        long long ans = -INF;
        if(arr1.size()) ans = max(ans, 2*arr1.front());
        if(arr2.size()) ans = max(ans, 2*arr2.front());
        if(arr3.size()) ans = max(ans, 2*arr3.front());
        return ans;
    }
    if(num == 2){
        long long ans = -INF;
        if(arr1.size() > 1) ans = max({ans, 2*arr1[0]+arr1[1], 2*arr1[1]+arr1[0]});
        if(arr1.size() && arr2.size()) ans = max({ans, 2*arr1[0]+arr2[0], arr1[0]+2*arr2[0]});
        return ans;
    }
    long long ans = -INF;
    if(arr1.size() > 2) ans = max({ans, 2*arr1[0]+arr1[1]+arr1[2], arr1[0]+2*arr1[1]+arr1[2], arr1[0]+arr1[1]+2*arr1[2]});
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    long long dp[n+1][10];
    for(long long i = 0; i<10; i++) dp[0][i] = -INF;
    dp[0][0] = 0;
    for(long long i = 0; i<n; i++){
        cin >> m;
        arr.clear();
        arr.resize(m);
        for(long long j = 0; j<m; j++) cin >> arr[j].first >> arr[j].second;
        for(long long j = 0; j<10; j++){
            dp[i+1][j] = -INF;
            for(long long k = 0; k<=3; k++){
                long long t = subtract(j, k);
                if(dp[i][t] == -INF) continue;
                long long ok = false;
                for(long long kk = 0; kk < k; kk++) if(subtract(j, kk) == 0) ok = true;
                if(ok){
                    long long kkk = check10(k);
                    if(kkk != -INF) dp[i+1][j] = max(dp[i+1][j], dp[i][t]+kkk);
                }
                else{
                    long long kkk = check(k);
                    if(kkk != -INF) dp[i+1][j] = max(dp[i+1][j], dp[i][t]+kkk);
                }
            }
        }
    }
    long long ans = -INF;
    for(long long i = 0; i<10; i++){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}