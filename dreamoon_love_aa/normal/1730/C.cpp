#include<iostream>
using namespace std;
void solve() {
    string s;
    cin >> s;
    int st = 0;
    string an;
    int cnt[128] = {};
    for(char c = '0'; c <= '9'; c++) {
        for(int i = (int)s.size() - 1; i >= st; i--) {
            if(s[i] == c) {
                for(int j = st;  j <= i; j++) {
                    if(s[j] == c) {
                        an += c;
                    } else {
                        cnt[min('9', (char)(s[j] + 1))]++;
                    }
                }
                st = i + 1;
                break;
            }
        }
        while(cnt[c]--) an += c;
    }
    cout << an << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}