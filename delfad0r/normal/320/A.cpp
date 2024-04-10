#include <bits/stdc++.h>

using namespace std;

bool is_magic(string S) {
    if(S.empty()) {
        return true;
    } else if(S.substr(0, 3) == "144") {
        return is_magic(S.substr(3));
    } else if(S.substr(0, 2) == "14") {
        return is_magic(S.substr(2));
    } else if(S.substr(0, 1) == "1") {
        return is_magic(S.substr(1));
    }
    return false;
}

int main() {
    string N;
    cin >> N;
    cout << ((is_magic(N)) ? ("YES") : ("NO")) << '\n';
}