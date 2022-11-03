#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool Can(int a, int b, int c) {
    if (b > c) {
        swap(b, c);
    }
    if (a == 0 && b == 0) {
        return false;
    }
    if (b == c) {
        return true;
    }
    if (b == 0 && c == 1) {
        return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int b = 0;
    int g = 0;
    int r = 0;

    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            ++b;
        }
        if (s[i] == 'R') {
            ++r;
        }
        if (s[i] == 'G') {
            ++g;
        }
    }

    if (Can(b, g, r)) {
        cout << 'B';
    }
    if (Can(g, b, r)) {
        cout << 'G';
    }
    if (Can(r, b, g)) {
        cout << 'R';
    }
    cout << endl;

    return 0;
}