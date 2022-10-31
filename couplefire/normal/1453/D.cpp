#include <bits/stdc++.h>
using namespace std;

vector<long long> num;

void solve(){
    vector<int> arr;
    long long k; cin >> k;
    if((k%2ll) == 1ll){
        cout << -1 << endl;
        return;
    }
    int cur = num.size()-1;
    while(k > 0ll){
        while(k >= num[cur]){
            k -= num[cur];
            arr.push_back(1);
            for(int i = 0; i<cur; i++) arr.push_back(0);
        }
        cur--;
    }
    cout << arr.size() << endl;
    for(auto x : arr) cout << x << " ";
    cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    long long cur = 2;
    while(cur <= 1000000000000000000ll){
        num.push_back(cur);
        cur = 2ll*cur+2ll;
    }
    while(t--){
        solve();
    }
}