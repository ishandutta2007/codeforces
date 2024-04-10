#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_N = 200'010;
char s[MAX_N];
void solve() {
    int n;
    cin >> n;
    cin >> s;
    if(count(s,s + 2 * n, '0') % 2) {
        cout << "-1\n";
        return;
    }
    char need = '0';
    vector<int> an;
    for(int i = 0; i < 2 * n; i += 2) {
        if(s[i] != s[i + 1]) {
            if(s[i] == need) {
                an.push_back(i + 1);
            } else {
                an.push_back(i + 2);
            }
            need ^= 1;
        }
    }
    cout << an.size();
    for(int i = 0; i < an.size(); i++) {
        cout << ' ' << an[i];
    }
    cout << '\n';
    for(int i = 1; i < n; i++) {
        cout << i * 2 << ' ';
    }
    cout << 2 * n << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}