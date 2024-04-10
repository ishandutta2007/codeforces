#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        cout << (n*m-1 == k ? "YES" : "NO") << endl;
    }
}