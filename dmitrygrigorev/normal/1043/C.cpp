#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i=0; i < s.size(); i++){
        if (s[i] == 'b'){
            if (i == s.size() - 1){
                cout << 0 << " ";
                continue;
            }
            if (s[i+1] == 'b'){
                cout << 0 << " ";
                continue;
            }
            cout << 1 << " ";
        }
        else{
            if (i == s.size() - 1){
                cout << 1 << " ";
                continue;
            }
            if (s[i+1] == 'b'){
                cout << 1 << " ";
                continue;
            }
            cout << 0 << " ";
        }
    }

}