#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n; 
    int tot = 0, ans = 0;
    vector<int> arr(n+1);
    for(int i = 1; i<=n; i++)
        cin >> arr[i], tot += arr[i];
    vector<int> psum1(n+1, 0), psum2(n+1, 0);
    for(int i = 1; i<=n; i++)
        psum1[i] = psum1[i-1]+arr[i];
    psum2[1] = arr[1];
    for(int i = 2; i<=n; i++)
        psum2[i] = psum2[i-2]+arr[i];
    
    if(n == 1){
        cout << 1 << '\n';
        return;
    }

    if(n == 2){
        cout << (arr[1]!=arr[2]?2:1) << '\n';
        return;
    }
    
    { // Take the first element
        for(int i = 1; i<n; i++){
            // don't take last
            int lo = 0, hi = floor((.0+n-1-i)/2.0);
            while(lo < hi){
                int mid = lo+(hi-lo+1)/2;
                int sum = psum1[i]+psum2[i+mid*2]-psum2[i];
                if(sum*2 < tot) lo = mid;
                else hi = mid-1;
            }
            if(psum1[i]*2 < tot)
                ans += lo+1;
            
            // take last
            lo = 0, hi = floor((.0+n-2-i)/2.0);
            while(lo < hi){
                int mid = lo+(hi-lo+1)/2;
                int sum = psum1[i]+psum2[i+mid*2]-psum2[i]+arr[n];
                if(sum*2 < tot) lo = mid;
                else hi = mid-1;
            }
            if((psum1[i]+arr[n])*2 < tot)
                ans += lo+1;
        }
    }

    { // take the second element
        for(int i = 2; i<n; i++){
            // don't take last
            int lo = 0, hi = floor((.0+n-1-i)/2.0);
            while(lo < hi){
                int mid = lo+(hi-lo+1)/2;
                int sum = psum1[i]+psum2[i+mid*2]-psum2[i]-arr[1];
                if(sum*2 < tot) lo = mid;
                else hi = mid-1;
            }
            if((psum1[i]-arr[1])*2 < tot)
                ans += lo+1;
            
            // take last
            lo = 0, hi = floor((.0+n-2-i)/2.0);
            while(lo < hi){
                int mid = lo+(hi-lo+1)/2;
                int sum = psum1[i]+psum2[i+mid*2]-psum2[i]+arr[n]-arr[1];
                if(sum*2 < tot) lo = mid;
                else hi = mid-1;
            }
            if((psum1[i]+arr[n]-arr[1])*2 < tot)
                ans += lo+1;
        }
    }

    { // take a suffix that start at at least i = 3, could be empty
        for(int i = 3; i<=n+1; i++)
            if(2*(psum1[n]-psum1[i-1]) < tot)
                ans++;
    }
    
    cout << (ans)%998244353ll << '\n';
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}