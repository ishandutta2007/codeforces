#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int mi = 1;
        int ma = -1;
        for(int i = 0; i<n; i++){
            if(s[i] == '-'){
                mi = min(mi, 0);
                ma = max(ma, 0);
            }
            if(s[i] == '<'){
                mi = min(mi, 1);
                ma = max(ma, 1);
            }
            if(s[i] == '>'){
                mi = min(mi, -1);
                ma = max(ma, -1);
            }
        }
        if(mi >= 0 || ma <= 0){
            cout << n << endl;
            continue;
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            int prev = i-1;
            if(prev < 0) prev += n;
            if(s[prev] == '-' || s[i] == '-') cnt++;
        }
        cout << cnt << endl;
    }
}