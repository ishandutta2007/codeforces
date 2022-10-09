#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int cnt0 = 0;
    for (int i = (int)s.size(); i--; ) {
        if (s[i] == '0') cnt0 ++;
        else if (cnt0 > 5) {
            cout << "yes";
            return 0;
        }
    }
    cout << "no";
    return 0;
}