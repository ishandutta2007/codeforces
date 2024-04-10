#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        if(n%2050 != 0){
            cout << -1 << endl;
        }
        else{
            n /= 2050;
            int cnt = 0;
            while(n > 0) cnt+=n%10, n /= 10;
            cout << cnt << endl;
        }
    }
}