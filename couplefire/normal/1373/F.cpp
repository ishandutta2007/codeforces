#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long arr[n], brr[n];
        for(long long i = 0; i<n; i++) cin >> arr[i];
        for(long long i = 0; i<n; i++) cin >> brr[i];
        long long lo = 0, hi = arr[0];
        while(lo < hi){
            long long mid = lo+(hi-lo+1)/2;
            long long prev = arr[0]-mid;
            if(brr[0] < mid){
                hi = mid-1;
                continue;
            }
            long long tarr[n], tbrr[n];
            for(long long i = 0; i<n; i++) tarr[i] = arr[i], tbrr[i] = brr[i];
            tarr[0] -= mid;
            tbrr[0] -= mid;
            tarr[1] = max(0ll, tarr[1]-tbrr[0]);
            bool ok = true;
            for(long long i = 1; i<n-1; i++){
                if(tarr[i] > tbrr[i]){
                    ok = false;
                    break;
                }
                tbrr[i] -= tarr[i];
                tarr[i+1] = max(0ll, tarr[i+1]-tbrr[i]);
            }
            if(!ok){
                hi = mid-1;
            }
            else lo = mid;
        }
        long long mid = lo;
        // cout << lo << endl;
        long long tarr[n], tbrr[n];
        for(long long i = 0; i<n; i++) tarr[i] = arr[i], tbrr[i] = brr[i];
        tarr[0] -= mid;
        tbrr[0] -= mid;
        tarr[1] = max(0ll, tarr[1]-tbrr[0]);
        bool ok = true;
        for(long long i = 1; i<n-1; i++){
            if(tarr[i] > tbrr[i]){
                ok = false;
                break;
            }
            tbrr[i] -= tarr[i];
            tarr[i+1] = max(0ll, tarr[i+1]-tbrr[i]);
        }
        if(ok == false){
            cout << "NO" << endl;
            continue;
        }
        if(tbrr[n-1] >= tarr[n-1]+tarr[0]){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}