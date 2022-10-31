#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    const int INF = 0x3f3f3f3f;
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    auto solve = [&]()->int{
        int ind = max_element(arr.begin(), arr.end())-arr.begin();
        vector<int> dp1(n, INF);
        dp1[0] = 0;
        for(int i = 1; i<=ind; ++i){
            if(arr[i]>arr[i-1])
                dp1[i] = min(dp1[i], dp1[i-1]);
            if(arr[i]>dp1[i-1])
                dp1[i] = min(dp1[i], arr[i-1]);
        }
        vector<int> dp2(n, INF);
        dp2[n-1] = 0;
        for(int i = n-2; i>=ind; --i){
            if(arr[i]>arr[i+1])
                dp2[i] = min(dp2[i], dp2[i+1]);
            if(arr[i]>dp2[i+1])
                dp2[i] = min(dp2[i], arr[i+1]);
        }
        vector<array<int, 2>> dp3(n, {INF, -INF});
        dp3[ind][0] = dp1[ind];
        int ans = 0;
        for(int i = ind+1; i<n; ++i){
            if(arr[i-1]>arr[i])
                dp3[i][0] = min(dp3[i][0], dp3[i-1][0]);
            if(dp3[i-1][0]<arr[i])
                dp3[i][1] = max(dp3[i][1], arr[i-1]);
            if(arr[i-1]<arr[i])
                dp3[i][1] = max(dp3[i][1], dp3[i-1][1]);
            if(dp3[i-1][1]>arr[i])
                dp3[i][0] = min(dp3[i][0], arr[i-1]);
            if(dp3[i][1]>dp2[i]) ++ans;
        }
        return ans;
    };
    int res = solve();
    reverse(arr.begin(), arr.end());
    res += solve();
    cout << res << '\n';
}