#include<iostream>
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int now = 0;
    for(char c: s) {
        if(c == 'Q') {
            now++;
        }
        else {
            now--;
            if(now < 0) now = 0;
        }
    }
    cout << (now <= 0 ? "Yes" : "No") << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}