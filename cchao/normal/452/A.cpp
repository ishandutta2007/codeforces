#include <bits/stdc++.h>
using namespace std;

string s[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool match(string a, string b) {
    if(a.length() != b.length()) return false;
    for(int i = 0; i < a.length(); ++i)
        if(a[i] != '.' && a[i] != b[i])
            return false;
    return true;
}

int main() {
    int n; string a; cin >> n >> a;
    for(int i = 0; i < 8; ++i) {
        if(match(a, s[i])) {
            cout << s[i] << endl;
            break;
        }
    }
    return 0;
}