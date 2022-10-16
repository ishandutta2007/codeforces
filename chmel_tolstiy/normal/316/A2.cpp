#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int q = count(s.begin(), s.end(), '?');
    int l = 0;
    for (int i = 0; i < 10; ++i)
        l += count(s.begin(), s.end(), 'A' + i) > 0;
    
    int res = 1;
    if (isalpha(s[0])) {
        res *= 9;
        for (int i = 1; i < l; ++i) res *= 10 - i;
    } else {
        for (int i = 0; i < l; ++i) res *= 10 - i;
    }
    if (s[0] == '?') {
        res *= 9;
        --q;
    }
    cout << res;
    for (int i = 0; i < q; ++i) cout << 0;
    cout << endl;
    return 0;
}