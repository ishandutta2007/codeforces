#include <bits/stdc++.h>
using namespace std;

void solve(){
    cout << 1 << " " << 2 << endl;
    string s; cin >> s;
    if(s=="Done") return;
    int x = 1, y = 1;
    while(1){
        cout << x << " " << y << endl; cin >> s;
        if(s=="Done") return;
        if(s.substr(0, 4)=="Down"){++x; continue;}
        if(y>1){y = 1; continue;}
        for(int i = 2; i<=8; ++i){
            y = i; cout << x << " " << y << endl; cin >> s;
            if(s == "Done") return;
            if(s.substr(0, 4)=="Down"){++x; goto done;}
            if(s.substr(0, 2)=="Up"){y = 1; goto done;}
        } ++x; done:;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}