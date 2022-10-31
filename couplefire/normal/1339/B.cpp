#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n);
        int mid = (n-1)/2;
        int l = mid, r = mid+1;
        bool left = 1;
        while(l >= 0 || r < n){
            if(left) cout << arr[l--] << " ";
            else cout << arr[r++] << " ";
            left = 1-left;
        }
        cout << endl;
    }
}