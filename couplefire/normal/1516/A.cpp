#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n];
        for(int i = 0; i<n; i++) cin >> arr[i];
        int curcnt= 0;
        for(int i = 0; i<n-1; i++){
            while(curcnt < k && arr[i] > 0) --arr[i], ++arr[n-1], curcnt++;
        }
        for(int i = 0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}