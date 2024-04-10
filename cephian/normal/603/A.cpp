#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int f = -1, l = n-1;
    for(int i = 1; i < n; ++i) {
        if(s[i] == s[i-1]) {
            if(f == -1) f = i;
            else l = i-1;
        }
    }
        if(f == -1) f = 0;
    for(int i = f; i <= l; ++i) {
        if(s[i] == '1') s[i] = '0';
        else s[i] = '1';
    }
        // cout << s << endl;
    int l0 = 0;
    int l1 = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1')
            l1 = 1+l0;
        else l0 = 1+l1;
    }
    cout << max(l0, l1) << "\n";
    return 0;
}