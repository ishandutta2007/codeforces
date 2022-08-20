#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int a[26], len = 0;
    for (int i = 0; i < 26; ++i) {
        a[i] = 0;
    }
    char x, u;
    string ans;
    while (cin >> x) {
        a[x-'a'] ++;
        len ++;
    }
    
    for (int i = 0; i < 26; ++i) {
        if (a[i] % 2 == 1) {
            bool temp = false;
            for (int j = 25; j > i; --j) {
                if (a[j] % 2 == 1) {
                    a[i] ++;
                    a[j] --;
                    temp = true;
                    break;
                }
            }
            if (temp == false) {
                u='a'+i;
                break;
            }
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        for (int j = 1; j <= a[i]/2; ++j) {
            ans += ('a'+i);
        }
    }
    cout << ans;
    
    if (len % 2 == 1) {
        cout << u;
    }
    for (int i = 0; i < ans.length(); ++i) {
        cout << ans[ans.length()-1-i];
    }
}