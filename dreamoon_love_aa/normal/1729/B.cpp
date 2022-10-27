#include<iostream>
#include<algorithm>
using namespace std;
void solve() {
    int n;
    string s;
    cin >> n >> s;
    string an;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '0') {
            an += 'a' + stoi(s.substr(i - 2, 2)) - 1;
            i -= 2;
        } else {
            an += 'a' + stoi(s.substr(i, 1)) - 1;
        }
    }
    reverse(an.begin(), an.end());
    cout << an << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}