#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s;
        int sum = 0, c0 = 0, c2 = 0;
        for (char c : s) {
            int x = c - '0';
            sum += x;
            c0 += x == 0;
            c2 += x % 2 == 0;
        }
        if (sum % 3 == 0 && c0 && c2 >= 2) {
            puts("red");
        } else {
            puts("cyan");
        }
    }
    return 0;
}