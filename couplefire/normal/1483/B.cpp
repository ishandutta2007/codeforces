#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    set<int> pos; set<int> val;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n; i++){
        val.insert(i);
        if(__gcd(arr[i], arr[(i+1)%n]) == 1) pos.insert(i);
    }
    int curpos = 0;
    vector<int> ans;
    while(!pos.empty()){
        // for(auto x : pos){
        //     cout << x+1 << " ";
        // }
        // cout << endl;
        auto it = pos.lower_bound(curpos);
        if(it == pos.end()) it = pos.begin();
        int num1 = *it; auto it2 = val.lower_bound(num1);
        auto it3 = next(it2);
        if(it3 == val.end()) it3 = val.begin();
        int num2 = (*it3);
        ans.push_back(num2);
        pos.erase(num1);
        if(pos.count(num2)) pos.erase(num2);
        auto it4 = next(it3);
        if(val.size() > 1){
            if(it4 == val.end()) it4 = val.begin();
            int num3 = (*it4);
            if(__gcd(arr[num1], arr[num3]) == 1) pos.insert(num1);
            curpos = num3;
        }
        val.erase(num2);
    }
    cout << ans.size() << " ";
    for(auto x : ans) cout << x+1 << " ";
    cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}