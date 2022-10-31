#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t; cin >> t;
    while(t--){
        long long n, k; cin >> n >> k;
        long long arr[n];
        for(long long i = 0; i<n; i++) cin >> arr[i];
        long long ma = -1000000009;
        long long mi = 1000000009;
        for(long long i = 0; i<n; i++) mi = min(mi, arr[i]), ma = max(ma, arr[i]);
        for(long long i = 0; i<n; i++) arr[i] = ma-arr[i];
        if(k % 2 == 1){
            for(long long i = 0; i<n; i++) cout << arr[i] << " ";
            cout << endl;
        }
        else{
            for(long long i = 0; i<n; i++) cout << ma-mi-arr[i] << " ";
            cout << endl;
        }
    }
}