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
        int mi = 100;
        for(int i = 0; i<100; i++){
            if(b+i == 1) continue;
            int cur = i;
            int ta = a;
            while(ta != 0){
                ta = ta/(b+i);
                cur++;
            }
            mi = min(mi, cur);
        }
        cout << mi << endl;
    }
}