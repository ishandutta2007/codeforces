#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> m;
int n;

bool solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    if (n & 1 || m.size() == 1) return false;

    while (m.size() > 1) {
        int x = m.begin()->first;
        int X = m.begin()->second;
        m.erase(m.begin());
        int y = m.begin()->first;
        int Y = m.begin()->second;
        m.erase(m.begin());

        if (m.size() == 0) return x + 1 == y && X == Y;
        if (x + 1 != y || X >= Y) return false;
        Y -= X;
        m[y] = Y;
    }

    return false;
}

int main() {
    if (solve()) cout << "YES"; else cout << "NO";
    cout << endl;
    return 0;
}