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
        int arr[n];
        for(int i = 0; i<n; i++) cin >> arr[i];
        if(arr[0]+arr[1] <= arr[n-1]){
            cout << 1 << " " << 2 << " " << n << endl;
        }
        else cout << -1 << endl;
    }
}