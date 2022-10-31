#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        long long ans = 0;
        map<int, long long> sum;
        for(int i = 0; i<n; i++){
            ans += 1ll*(n-i)*sum[arr[i]];
            sum[arr[i]] += i+1;
        }
        cout << ans << endl;
    }
}