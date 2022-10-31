#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    long long arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    long long cur = -1;
    for(int i = 1; i<n; i++){
        if(cur == -1) cur = arr[i]-arr[i-1];
        else cur = __gcd(cur, arr[i]-arr[i-1]);
    }
    for(int i = 0; i<m; i++){
        long long c; cin >> c;
        if(cur == -1) cout << c+arr[0] << endl;
        else cout << __gcd(c+arr[0], cur) << endl;
    }
}