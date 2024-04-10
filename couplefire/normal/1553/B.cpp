#include <bits/stdc++.h>
using namespace std;

string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

void solve(){
    string s, t; cin >> s >> t;
    for(int i = 0; i<(int)s.length(); i++){
        for(int j = 0; j<(int)s.length()-i; j++){
            int blah = (int)t.length()-j-1;
            if(blah<0) continue;
            if(i+j-blah<0) continue;
            if(s.substr(i, j+1)==t.substr(0, j+1) && rev(s.substr(i+j-blah, blah))==t.substr(j+1, blah))
                return void(cout << "YES" << '\n');
        }
    }
    return void(cout << "NO" << '\n');
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}