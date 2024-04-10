#include <iostream>
#include <vector>
using namespace std;

inline int GetDx(char c) {
    if (c == 'U' || c == 'D') {
        return 0;
    }
    if (c == 'L') {
        return -1;
    }
    return 1;
}

inline int GetDy(char c) {
    if (c == 'L' || c == 'R') {
        return 0;
    }
    if (c == 'U') {
        return 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        int y = 0;
        for (int j = i; j < n; ++j) {
            x += GetDx(s[j]);
            y += GetDy(s[j]);
            if (x == 0 && y == 0) {
                ++result;
            }
        }
    }

    cout << result << endl;

    return 0;
}