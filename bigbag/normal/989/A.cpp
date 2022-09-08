#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    cin >> s;
    for (int i = 0; i + 2 < s.length(); ++i) {
        set<char> q;
        q.insert(s[i]);
        q.insert(s[i + 1]);
        q.insert(s[i + 2]);
        if (q.find('.') != q.end()) {
            q.erase('.');
        }
        if (q.size() == 3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}