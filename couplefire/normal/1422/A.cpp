#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        vector<long long> v(3);
        cin >> v[0] >> v[1] >> v[2];
        cout << v[0]+v[1]+v[2]-1 << endl;
    }
}