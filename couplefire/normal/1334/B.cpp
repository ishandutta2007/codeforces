#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    long long t; cin >> t;
    while(t--){
        long long n, x; cin >> n >> x;
        long long arr[n];
        for(long long i = 0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        reverse(arr, arr+n);
        long long sum = 0;
        long long ans = 0;
        for(long long i = 0; i<n; i++){
            sum += arr[i];
            long double av = (sum+0.0)/(i+1);
            if(av >= x){
                ans = i+1;
            }
        }
        cout << ans << endl;
    }
}