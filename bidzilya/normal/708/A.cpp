#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void Reverse(char& c) {
    if (c == 'a') {
        c = 'z';
    } else {
        --c;
    }
}

void Reverse(string& s, int l, int r) {
    for (int i = l; i <= r; ++i) {
        Reverse(s[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    cin >> s;

    int n = s.length();

    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            int l = i;
            int r = l;
            while (r + 1 < n && s[r + 1] != 'a') {
                ++r;
            }
            Reverse(s, l, r);
            cout << s << endl;
            return 0;
        }
    }

    Reverse(s, n - 1, n - 1);

    cout << s << endl;

    return 0;
}