#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(10);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        ll sum = 0;
        for(int i = 0; i<n; ++i)
            cin >> arr[i], sum += arr[i];
        sort(arr.begin(), arr.end());
        cout << arr.back()+(.0+sum-arr.back())/(n-1) << '\n';
    }
}