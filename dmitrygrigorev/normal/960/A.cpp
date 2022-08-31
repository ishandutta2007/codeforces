#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    bool b = false, c = false;
    int A=0, B=0, C=0;
    for (int i=0; i < s.size(); i++){
        if (s[i] == 'a'){
            if (b || c){
                cout << "NO" << endl;
                return 0;
            }
            A++;
        }
        if (s[i] == 'b'){
            if (c){
                cout << "NO" << endl;
                return 0;
            }
            b = true;
            B++;
        }
        if (s[i] == 'c'){
            c = true;
            C++;
        }
    }
    if (A==0 || B==0){
        cout << "NO" << endl;
        return 0;
    }
    if (A!=C && B != C){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}