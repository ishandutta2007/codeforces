#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    long long ma = pow(1000000000000000, 1.0/(n-1));
    long long arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    long long mi = 0;
    for(int i = 0; i<n; i++) mi += arr[i];
    for(int i = 1; i<=ma; i++){
        long long cur = 1;
        long long temp = 0;
        for(int j = 0; j<n; j++){
            if(cur >= 1000000000000000ll){
                temp = -1;
                break;
            }
            temp += abs(arr[j]-cur);
            cur *= i;
        }
        if(temp != -1) mi = min(mi, temp);
    }
    cout << mi << endl;
}