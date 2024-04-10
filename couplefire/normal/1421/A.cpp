#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int ans = a+b;
        for(int i = 0; i<=30; i++){
            if(((1<<i)&a)&((1<<i)&b)) ans -= (1<<(i+1));
        }
        cout << ans << endl;
    }
}