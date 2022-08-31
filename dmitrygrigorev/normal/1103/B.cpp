#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string s;
    cin >> s;
    if (s=="mistake" || s == "end") exit(0);
    cout << "? 0 1" << endl;
    string res;
    cin >> res;
    if (res == "x"){
        cout << "! " << 1 << endl;
        return;
    }
    int T = 1;
    while (true){
        cout << "? " << T << " " << 2*T << endl;
        cin >> res;
        if (res == "x") break;
        T *= 2;
    }
    int L = T, R = 2*T;
    while (R-L>1){
        int M = (L+R)/2;
        cout << "? " << T << " " << M << endl;
        cin >> res;
        if (res == "x") R = M;
        else L = M;
    }
    cout << "! " << R << endl;
}
signed main(){
    while (true){
        solve();
    }
}