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
        int cur = arr[0];
        for(int i = 1; i<n; i++){
            if(arr[i] != cur){
                cur = -1;
                cout << 1 << endl;
                break;
            }
        }
        if(cur != -1){
            cout << n << endl;
        }
    }
}