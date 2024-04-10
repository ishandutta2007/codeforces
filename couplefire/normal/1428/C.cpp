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
        string ss = "";
        for(int i = 0; i<n; i++){
            if(ss.empty()){
                ss += s[i];
                continue;
            }
            if(ss.back() == 'A' && s[i] == 'B') ss.pop_back();
            else if(ss.back() == 'B' && s[i] == 'B') ss.pop_back();
            else ss += s[i];
        }
        cout << ss.length() << endl;
    }
}