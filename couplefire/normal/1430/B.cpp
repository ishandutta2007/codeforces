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
        vector<long long> arr(n);
        for(long long i = 0; i<n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        if(k == 0){
            cout << arr.back()-arr.front() << endl;
            continue;
        }
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        k = min(k, n-1);
        long long index = n-2;
        while(k--){
            arr[n-1] += arr[index];
            index--;
        }
        cout << arr[n-1] << endl;
    }
}