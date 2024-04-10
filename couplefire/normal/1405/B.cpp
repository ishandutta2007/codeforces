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
        long long arr[n];
        for(int i = 0; i<n; i++) cin >> arr[i];
        long long ans = 0;
        for(int i = 0; i<n-1; i++){
            if(arr[i] < 0){
                ans += -arr[i];
                arr[n-1] += arr[i];
            }
            else if(arr[i] > 0){
                arr[i+1] += arr[i];
            }
        }
        cout << ans << endl;
    }
}