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
        int sum = 0;
        vector<int> arr(n);
        for(int i = 0; i<n; i++){
            int a; cin >> a;
            arr[i] = a;
            sum += a;
        }
        if(sum == x){
            cout << "NO" << endl;
            continue;
        }
        sum = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i<n; i++){
            sum += arr[i];
            if(sum == x){
                swap(arr[i], arr[i+1]);
                break;
            }
        }
        cout << "YES" << endl;
        for(int i = 0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}