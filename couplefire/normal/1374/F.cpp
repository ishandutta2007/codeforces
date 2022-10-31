#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int num = 0;
        vector<int> arr(n);
        map<int, vector<int>> mp;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            mp[arr[i]].push_back(i);
        }
        int cur = 0;
        for(auto p : mp){
            auto v = p.second;
            for(auto k : v){
                arr[k] = cur++;
            }
        }
        int inv = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(arr[i] > arr[j]) inv++;
            }
        }
        if(inv%2 == 1 && mp.size() == n){
            cout << -1 << endl;
            continue;
        }
        else if(inv%2 == 1){
            for(auto i : mp){
                if(i.second.size()>1){
                    swap(arr[i.second[0]], arr[i.second[1]]);
                    break;
                }
            }
        }
        vector<int> ops;
        for(int i = 0; i<n-2; i++){
            int pos;
            for(int j = i; j<n; j++){
                if(arr[j] == i){
                    pos = j;
                    break;
                }
            }
            // cout << pos+1 << " ";
            while(pos-i >= 2){
                ops.push_back(pos-2);
                swap(arr[pos], arr[pos-2]);
                swap(arr[pos-1], arr[pos]);
                pos -= 2;
            }
            if(pos == i) continue;
            ops.push_back(i); ops.push_back(i);
            swap(arr[i], arr[i+1]);
            swap(arr[i+1], arr[i+2]);
        }
        // for(auto i : arr) cout << i << " ";
        // cout << endl;
        cout << ops.size() << endl;
        for(auto i : ops){
            cout << i+1 << " ";
        }
        cout << endl;
    }
}