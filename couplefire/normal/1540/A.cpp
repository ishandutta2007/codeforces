#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        long long ans = 0;
        vector<int> arr(n);
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        ans = arr.back();
        for(int i = 1; i<(int)arr.size(); i++)
            ans += 1ll*arr[i]*(n-2*i-1);
        cout << ans << endl;
    }
}