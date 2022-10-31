#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(2*n);
        for(int i = 0; i<2*n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        for(int i = 0; i<n; i++)
            cout << arr[i] << " " << arr[i+n] << " ";
        cout << endl;
    }
}