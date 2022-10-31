#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int sum = 0;
        for(int i = 0; i<n; i++){
            int a; cin >> a; 
            sum += a;
        }
        if(sum < n) cout << 1 << endl;
        else if(sum == n) cout << 0 << endl;
        else cout << sum-n << endl;
    }
}