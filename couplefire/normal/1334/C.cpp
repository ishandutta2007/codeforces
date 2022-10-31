#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t; cin >> t;
    while(t--){
        long long n; cin >> n;
        pair<long long, long long> arr[n];
        for(long long i = 0; i<n; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        long long ans = 0;
        long long dam = 0;
        for(long long i = 0; i<n; i++){
            ans += max(0ll, arr[i].first-dam);
            dam = arr[i].second;
        }
        long long bestans = ans;
        for(long long i = 1; i<n; i++){
            ans += arr[i].first - max(0ll, arr[i].first-arr[i-1].second);
            long long last = (i-2+n)%n;
            ans -= min(arr[last].second, arr[i-1].first);
            bestans = min(bestans, ans);
        }
        cout << bestans << endl;
    }
}