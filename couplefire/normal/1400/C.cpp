#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int n = s.length();
        int x; cin >> x;
        int mark[n];
        bool flag = true;
        for(int i = 0; i<n; i++) mark[i] = 1;
        for(int i = 0; i<n; i++){
            if(s[i] == '1') continue;
            if(i - x >= 0) mark[i-x] = 0;
            if(i + x < n) mark[i+x] = 0;
        }
        for(int i = 0; i<n; i++){
            if(s[i] == '1'){
                if((i-x < 0 || mark[i-x] == 0) && (i+x >= n || mark[i+x] == 0)){
                    cout << -1 << endl;
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            for(int i = 0; i<n; i++) cout << mark[i];
            cout << endl;
        }
    }
}