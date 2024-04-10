#include <bits/stdc++.h>
using namespace std;

string rev(string s){
    reverse(s.begin(), s.end());
    return s;
}

bool work(vector<string> v){
    set<string> se;
    for(int i = 0; i<(int)v.size(); ++i){
        string tmp = rev(v[i]);
        if(tmp==v[i]) return 1;
        if(se.count(tmp)) return 1;
        for(int j = 0; j<26; ++j){
            tmp += string(1, char('a'+j));
            if(se.count(tmp)) return 1;
            tmp.pop_back();
        }
        tmp.pop_back();
        if(se.count(tmp)) return 1;
        se.insert(v[i]);
    }
    return 0;
}

void solve(){
    int n; cin >> n;
    vector<string> v(n);
    for(int i = 0; i<n; ++i)
        cin >> v[i];
    cout << (work(v)?"YES":"NO") << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}