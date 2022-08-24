#include <bits/stdc++.h>
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    int oth = 0;
    for (int i=0; i < s.size(); i++) if (s[i] != 'a') oth++;
    if (oth % 2 != 0){
        cout << ":(";
        return 0;
    }
    string a = "", b = "", ans="";
    int here = 0;
    for (int i=0; i < s.size(); i++){
        if (s[i] == 'a' && here > oth/2){
            cout << ":(";
            return 0;
        }
        if (s[i] == 'a'){
            ans += s[i];
            continue;
        }
        else{
            if (here < oth/2){
                a+=s[i], ans+=s[i];
            }
            else b += s[i];
            here++;
        }
    }
    if (a!=b){
        cout << ":(";
        return 0;
    }
    cout << ans;
}