#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    if ((s.back() - '0') & 1) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
}