#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    int cnt[2]; cnt[0] = cnt[1] = 0;
    for(int i = 0; i<n; i++) cnt[arr[i]]++;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int a; cin >> a; --a;
            cnt[arr[a]]--;
            arr[a] = 1-arr[a];
            cnt[arr[a]]++;
        }
        else{
            int k; cin >> k;
            if(cnt[1] >= k) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}