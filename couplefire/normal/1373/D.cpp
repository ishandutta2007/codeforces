#include <bits/stdc++.h>
using namespace std;
#define INF 10000000000000000

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        long long cur = 0;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            if(i%2 == 0) cur += 0ll+arr[i];
        }
        if(n == 1){
            cout << cur << endl;
            continue;
        }
        long long dpodd[n], dpeven[n], ddpodd[n], ddpeven[n];
        dpeven[0] = 0;
        dpodd[0] = -INF;
        dpeven[1] = 0;
        dpodd[1] = arr[1]-arr[0];
        ddpeven[0] = 0;
        ddpodd[0] = -INF;
        ddpeven[1] = 0;
        ddpodd[1] = arr[0]-arr[1];
        for(int i = 2; i<n; i++){
            dpeven[i] = 0, dpodd[i] = -INF;
            ddpeven[i] = 0, ddpodd[i] = -INF;
            dpeven[i] = max(dpeven[i], 0ll+arr[i]-arr[i-1]+dpodd[i-2]);
            dpodd[i] = max(dpodd[i], 0ll+arr[i]-arr[i-1]+dpeven[i-2]);
            ddpeven[i] = max(ddpeven[i], 0ll+arr[i-1]-arr[i]+ddpodd[i-2]);
            ddpodd[i] = max(ddpodd[i], 0ll+arr[i-1]-arr[i]+ddpeven[i-2]);
        }
        long long maxadd = 0;
        for(int i = 0; i<n; i++){
            if(i%2 == 1) maxadd = max(maxadd, max(dpeven[i], dpodd[i]));
            else maxadd = max(maxadd, max(ddpeven[i], ddpodd[i]));
        }
        cout << cur+maxadd << endl;
    }
}