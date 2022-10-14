#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int c; cin >> c;
    string ans; int count = 0;
    int a = 0, b = 0;
    for(int i=0; i<c; i++) {
        char c; cin >> c;
        if(c == 'a') a++;
        else b++;
        if(a+b == 2) {
            if(a == 2 || b == 2) {
                ans += "ba";
                count++;
            } else {
                if(c == 'a') ans += "ba";
                else ans += "ab";
            }
            a = 0; b = 0;
        }
    }
    cout << count << '\n' << ans << endl;
}