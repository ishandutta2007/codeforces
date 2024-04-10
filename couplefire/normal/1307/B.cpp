#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    long long t; cin >> t;
    while(t--){
        long long n, x; cin >> n >> x;
        vector<long long> arr(n);
        for(long long i = 0; i<n; i++){
            long long a; cin >> a;
            arr[i] = a;
        }
        sort(arr.begin(), arr.end());
        long long index = upper_bound(arr.begin(), arr.end(), x)-arr.begin();
        if(index == 0){
            cout << 2 << endl;
            continue;
        }
        if(index == n){
            cout << (long long)ceil((0.0+x)/(0.0+arr[index-1])) << endl;
            continue;
        }
        cout << min(2ll, (long long)ceil((0.0+x)/(0.0+arr[index-1]))) << endl;
        
    }
}