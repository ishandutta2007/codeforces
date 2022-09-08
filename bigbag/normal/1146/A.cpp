#include <bits/stdc++.h>

using namespace std;

string s;
int cnt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (char c : s) {
        if (c == 'a') {
            ++cnt;
        }
    }
    int len = s.length();
    while (cnt <= len - cnt) {
        --len;
    }
    cout << len << endl;
    return 0;
}