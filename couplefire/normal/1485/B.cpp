#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, k; cin >> n >> q >> k;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    while(q--){
        int l, r; cin >> l >> r;
        --l; --r;
        cout << (arr[r]-arr[l]-(r-l))*2+k-arr[r]+arr[l]-1 << endl;
    }
}