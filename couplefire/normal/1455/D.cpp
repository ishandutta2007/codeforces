#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        int arr[n+1];
        arr[0] = -1;
        for(int i = 1; i<=n; i++) cin >> arr[i];
        bool f = true;
        for(int i = 1; i<=n; i++){
            if(arr[i] < arr[i-1]){
                f = false;
                break;
            }
        }
        if(f){
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(arr[i] > x) swap(arr[i], x), ans++;
            f = true;
            for(int i = 1; i<=n; i++){
                if(arr[i] < arr[i-1]){
                    f = false;
                    break;
                }
            }
            if(f){
                cout << ans << endl;
                break;
            }
        }
        if(f) continue;
        else cout << -1 << endl;
    }
}