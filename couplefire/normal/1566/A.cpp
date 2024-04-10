#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        n = n/2+1;
        cout << s/n << '\n';
    }
}