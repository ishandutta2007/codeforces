#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> places; places.push_back(-n);
    for(int i = 0; i<n; i++)
        if(s[i]-'0') places.push_back(i);
    places.push_back(2*n);
    if((int)places.size() == 2){
        cout << s << endl;
        return; 
    }
    for(int i = 0; i<(int)places.size()-1; i++){
        int a = places[i]+1, b = places[i+1]-1;
        for(int j = 0; j<m && a<b && a<n && b >=0; j++, a++, b--){
            if(a >= 0) s[a] = '1';
            if(b < n) s[b] = '1';
        }
    }
    cout << s << endl;
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}