// https://codeforces.com/contest/1491/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
    while(t--) {
        int n, u, v;
        cin >> n >> u >> v;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int a = 0;
        int b = 0;
        for(int i=0; i<(n-1); i++) {
            if(a<abs(arr[i+1]-arr[i])) {
                a = abs(arr[i+1]-arr[i]);
            }
        }
        if(a==0) {
            cout << min(u+v,v+v) << endl;
        }
        if(a==1) {
            cout << min(u,v) << endl;
        }
        if(a>=2) {
            cout << 0 << endl;
        }
    }
    return 0;
}