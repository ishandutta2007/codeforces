#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long solve(int n, int m, vector<int> arr){
    int dp[m];
    dp[m-1] = arr[m-1];
    set<pair<int, int>> st;
    st.insert({arr[m-1]-m+1, m-1});
    for(int i = m-2; i>=0; i--){
        int look = arr[i]-1-i;
        if(st.lower_bound(make_pair(look, -1)) == st.end()) dp[i] = min(arr[i]-1+m-i, n-1);
        else{
            auto stuff = *st.lower_bound(make_pair(look, -1));
            if(stuff.first != look){
                dp[i] = min(arr[i]-1+m-i, n-1);
            }
            else dp[i] = dp[stuff.second];
        }
        st.insert({arr[i]-i, i});
    }
    long long aa = 0;
    for(int i = 0; i<n; i++){
        int look = i+1;
        if(st.lower_bound(make_pair(look, -1)) == st.end()){
            aa += min(n-1, i+m+1)-i;
            // cout << i+1 << " " << min(n-1, i+m+1)+1 << endl;
        }
        else{
            auto stuff = *st.lower_bound(make_pair(look, -1));
            if(stuff.first != look){
                aa += min(n-1, i+m+1)-i;
            }
            else aa += dp[stuff.second]-i;
            // cout << i+1 << " " << dp[stuff.second]+1 << endl;
        }
    }
    return aa;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> arr;
    arr.resize(m);
    for(int i = 0; i<m; i++) cin >> arr[i], --arr[i];
    long long ans = 0;
    ans += solve(n, m, arr);
    for(int i = 0; i<m; i++) arr[i] = n-1-arr[i];
    ans += solve(n, m, arr);
    ans += n;
    cout << ans << endl;
}