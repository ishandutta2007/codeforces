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
        vector<int> arr(n);
        int sumneg = 0, sumpos = 0;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            if(arr[i] > 0) sumpos += arr[i];
            if(arr[i] < 0) sumneg += -arr[i];
        }
        sort(arr.begin(), arr.end());
        if(sumpos > sumneg){
            cout << "YES" << endl;
            reverse(arr.begin(), arr.end());
            for(auto i : arr) cout << i << " ";
            cout << endl;
        }
        else if(sumpos < sumneg){
            cout << "YES" << endl;
            for(auto i : arr) cout << i << " ";
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}