#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n%2) cout << "Bob" << endl;
        else {
            int lg = 0;
            while((1<<lg) < n) ++lg;
            if((1<<lg) == n) cout << (lg%2?"Bob":"Alice") << endl;
            else cout << "Alice" << endl;
        }
    }
}