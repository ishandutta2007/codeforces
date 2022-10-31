#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int pw = 0;
        while((1<<pw)<=n) pw++;
        cout << (1<<(pw-1))-1 << endl;
    }
}