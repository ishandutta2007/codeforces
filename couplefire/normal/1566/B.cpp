#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.length();
    vector<int> pos;
    for(int i = 0; i<n; ++i)
        if(s[i]=='0') pos.push_back(i);
    if(pos.empty())
        return void(cout << 0 << '\n');
    if(pos.back()-pos.front()+1==(int)pos.size())
        return void(cout << 1 << '\n');
    cout << 2 << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}