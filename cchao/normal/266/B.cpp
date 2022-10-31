#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; string s; cin >> a >> b >> s;
    while(b--) {
        for(int i = 0; i < s.length() - 1; ) {
            if(s[i] == 'B' && s[i+1] == 'G') {
                swap(s[i], s[i+1]);
                i += 2;
            }
            else {
                i += 1;
            }
        }
    }
    cout << s << endl;
    return 0;
}