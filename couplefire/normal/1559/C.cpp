#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(int i = 0; i<n; ++i)
            cin >> arr[i];
        if(arr[0]==1){
            cout << n+1 << ' ';
            for(int i = 1; i<=n; ++i)
                cout << i << ' ';
            cout << '\n';
            continue;
        }
        if(arr[n-1]==0){
            for(int i = 1; i<=n+1; ++i)
                cout << i << ' ';
            cout << '\n';
            continue;
        }
        bool work = 0;
        for(int i = 0; i<n-1; ++i){
            if(arr[i]==0 && arr[i+1]==1){
                for(int j = 0; j<=i; ++j)
                    cout << j+1 << ' ';
                cout << n+1 << ' ';
                for(int j = i+1; j<n; ++j)
                    cout << j+1 << ' ';
                cout << '\n'; work = 1;
                break;
            }
        }
        if(!work) cout << -1 << '\n';
    }
}