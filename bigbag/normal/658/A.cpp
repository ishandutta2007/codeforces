#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

const int max_n = 555;

int n, c, p[max_n], t[max_n];

int solve() {
    int res = 0;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        x += t[i];
        res += max(0, p[i] - x * c);
    }
    return res;
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int a = solve();
    reverse(p, p + n);
    reverse(t, t + n);
    int b = solve();
    if (a > b) {
        cout << "Limak" << endl;
    } else if (a < b) {
        cout << "Radewoosh" << endl;
    } else {
        cout << "Tie" << endl;
    }
    return 0;
}