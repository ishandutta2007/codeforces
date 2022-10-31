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
        for(int i = 0; i<n; i++) cin >> arr[i], --arr[i];
        if(is_sorted(arr, arr+n)) cout << 0 << endl;
        else if(arr[0] == 0) cout << 1 << endl;
        else if(arr[n-1] == n-1) cout << 1 << endl;
        else if(arr[0] == n-1 && arr[n-1] == 0) cout << 3 << endl;
        else cout << 2 << endl;
    }
}