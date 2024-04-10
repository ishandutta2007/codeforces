#include<iostream>
#include<algorithm>
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int an = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) an++;
    }
    if(an && s[0] == '0') an--;
    cout << an << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}