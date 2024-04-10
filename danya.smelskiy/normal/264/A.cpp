#include <bits/stdc++.h>
using namespace std;

string s;


void solve(int x) {
    if (x==s.size()) return;
    if (s[x]=='l') {
        solve(x+1);
        cout<<x+1<<'\n';
    } else {
        cout<<x+1<<'\n';
        solve(x+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    solve(0);
}