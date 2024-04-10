#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; long long w;
        cin >> n >> w;
        long long half = (w+1)/2;
        vector<pair<long long, int>> arr(n);
        for(int i = 0; i<n; i++){
            cin >> arr[i].first;
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        auto it = lower_bound(arr.begin(), arr.end(), make_pair(half, -1));
        if(it != arr.end() && (*it).first <= w){
            cout << 1 << endl;
            cout << (*it).second+1 << endl;
            continue;
        }
        long long cur = 0;
        vector<int> ans;
        for(int i = 0; i<n && cur < half; i++){
            cur += arr[i].first;
            ans.push_back(arr[i].second);
        }
        if(cur > w || cur < half){
            cout << -1 << endl;
            continue;
        }
        cout << ans.size() << endl;
        for(auto x : ans){
            cout << x+1 << " ";
        }
        cout << endl;
    }
}