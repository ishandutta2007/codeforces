#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    map<int, vector<int>> mp;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    string res = "";
    for(int i = 0; i<n; i++) res += "0";
    int cl = 0, cr = n-1;
    int cur = 1;
    for(auto &x : mp){
        int num = x.first;
        vector<int> vec = x.second;
        if(num != cur){
            cout << res << endl;
            return;
        }
        cur++;
        res[cr-cl] = '1';
        if(vec.size() >= 2 || (vec[0] != cl && vec[0] != cr)){
            set<int> st;
            for(int i = 1; i<=n; i++) st.insert(i);
            if(st.size() != n){
                cout << res << endl;
                return;
            }
            for(int i = 0; i<n; i++) st.erase(arr[i]);
            if(st.size() != 0){
                cout << res << endl;
                return;
            }
            res[0] = '1';
            cout << res << endl;
            return;
        }
        if(vec[0] == cl) cl++;
        else cr--;
    }
    cout << res << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}