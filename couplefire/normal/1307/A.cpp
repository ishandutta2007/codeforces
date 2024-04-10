#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n, d; cin >> n >> d;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin >> arr[i];
        }
        int index = 1;
        int ans = arr[0];
        while(d > 0 && index < n){
            if(arr[index] > 0){
                arr[index]--;
                d -= index;
                ans ++;
            }
            else index++;
        }
        if(d < 0) ans--;
        cout << ans << endl;
    }
}