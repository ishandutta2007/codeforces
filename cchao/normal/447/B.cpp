#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int k; cin >> k;

    char c; int m;
    int w[30];
    for(int i = 0; i < 26; ++i) {
        cin >> w[i];
        if(!i || w[i] > m) { m = w[i]; c = 'a' + i; }
    }

    while(k--) s = s + c;
    int ans = 0;
    for(int i = 0; i < s.length(); ++i) {
        ans += (i+1) * w[s[i] - 'a'];
    }
    cout << ans << endl;

    return 0;
}