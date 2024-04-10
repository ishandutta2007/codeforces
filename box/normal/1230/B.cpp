#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k; string s; cin >> n >> k >> s;
    if(n == 1) {
        if(k) cout << 0 << endl;
        else cout << s << endl;
        return 0;
    }
    if(k == 0) {
        cout << s << endl;
        return 0;
    }
    if(s[0] != '1') {
        s[0] = '1';
        k--;
    }
    for(int p=1; p<n; p++) {
        if(!k) break;
        if(s[p] != '0') {
            s[p] = '0';
            k--;
        }
    }
    cout << s << endl;
}