#include <bits/stdc++.h>
using namespace std;

void solve(){
    int px, py; cin >> px >> py;
    string s; cin >> s;
    int minx = 0, miny = 0, maxx = 0, maxy = 0;
    for(auto x : s){
        if(x == 'R') maxx++;
        if(x == 'L') minx--;
        if(x == 'U') maxy++;
        if(x == 'D') miny--;
    }
    if(minx <= px && px <= maxx && miny <= py && py <= maxy) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}