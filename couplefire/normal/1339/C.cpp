#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long arr[n];
        for(long long i = 0; i<n; i++) cin >> arr[i];
        long long curmax = arr[0];
        long long ans = 0;
        for(long long i = 0; i<n; i++){
            if(arr[i] >= curmax){
                curmax = arr[i];
                continue;
            }
            ans = max(ans, (long long)(log2(curmax-arr[i])+1));
        }
        cout << ans << endl;
    }
}