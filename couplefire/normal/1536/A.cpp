#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; i++)
            cin >> arr[i];
        int mi = (*min_element(arr.begin(), arr.end()));
        if(mi < 0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << 101 << endl;
        for(int i = 0; i<=100; i++)
            cout << i << " ";
        cout << endl;
    }
}