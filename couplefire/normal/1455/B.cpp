#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        bool l = false;
        for(int i = 1; i<3000; i++){
            if(i*(i+1)/2 == x){
                cout << i << endl;
                l = true;
                break;
            }
        }
        if(l) continue;
        int cur = 1;
        while(cur*(cur+1)/2-2 < x) cur++;
        cout << cur << endl;
    }
}