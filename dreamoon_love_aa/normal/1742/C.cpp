#include<iostream>
#include<string>
using namespace std;
const int SIZE = 8;
void solve() {
    string ans = "B";
    for(int i = 0; i < SIZE; i++) {
        string s;
        cin >> s;
        if(s == string(SIZE, 'R')) {
            ans = "R";
        }
    }
    cout << ans << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}