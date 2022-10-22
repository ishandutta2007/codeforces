#include<bits/stdc++.h>

using namespace std;

string f(string s, int i) {
    int res = int(s[i] - '0') + int(s[i+1] - '0');
    return s.substr(0, i) + to_string(res) + s.substr(i+2);
}

string solve(string s) {
    int n = s.size();
    for (int i = n-2; ~i; i--)
        if ((int)(s[i] - '0') + (int)(s[i+1] - '0') >= 10)
            return f(s, i);
    return f(s, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--){
        string s; cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}