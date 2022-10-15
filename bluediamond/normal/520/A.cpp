#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set <int> f;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        f.insert(tolower(c));
    }
    cout << (f.size() == 26 ? "YES" : "NO");
}