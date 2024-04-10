#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b, dif; cin >> a >> b >> dif;
        if(a > b) swap(a, b);
        if((b-1)/a > dif) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}