#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    long long arr[n+1];
    for(int i = 0; i<n; i++) cin >> arr[i+1];
    if(n == 1){
        cout << 1 << " " << 1 << endl;
        cout << -arr[1] << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    cout << 1 << " " << n-1 << endl;
    for(int i = 1; i<=n-1; i++) cout << arr[i]*(n-1) << " ";
    cout << endl;
    for(int i = 1; i<=n-1; i++) arr[i] = arr[i]*n;
    cout << n << " " << n << endl;
    cout << arr[n]*(n-1) << " ";
    cout << endl;
    arr[n] = arr[n]*n;
    cout << 1 << " " << n << endl;
    for(int i = 1; i<=n; i++) cout << -arr[i] << " ";
    cout << endl;
}