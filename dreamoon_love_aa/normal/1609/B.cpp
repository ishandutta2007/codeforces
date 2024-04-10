#include<iostream>
#include<string>
using namespace std;
int n, q;
string s;
void solve() {
    int now=0;
    for(int i = 0; i + 3 <= n; i++) {
        now += (s.substr(i, 3) == "abc");
    }
    while(q--) {
        int pos;
        char c;
        cin >> pos >> c;
        pos--;
        for(int i = max(0, pos - 2); i <= min(pos,n-3); i++) {
            now -= (s.substr(i, 3) == "abc");
        }
        s[pos] = c;
        for(int i = max(0, pos - 2); i <= min(pos, n - 3); i++) {
            now += (s.substr(i, 3) == "abc");
        }
        cout << now << '\n';
    }
}
void input() {
    cin >> n >> q >> s;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}