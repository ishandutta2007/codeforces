#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int n;

int next(int x, char c, int v) {
    if (c == '<') {
        x -= v;
        return max(x, 0);
    } else {
        x += v;
        return min(x, n + 1);
    }
}

int *next_ar;
bool dfs() {
    bool *used = new bool[n + 2];
    for (int i = 0; i <= n; i++)
        used[i] = false;
    int v = 1;
    while (!used[v] && v > 0 && v <= n) {
        used[v] = true;
        v = next_ar[v];
    }
    return v == 0 || v == n + 1;
}

int main() {
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    next_ar = new int[n + 2];
    for (int i = 1; i <= n; i++)
        next_ar[i] = next(i, s[i - 1], v[i - 1]);
    if (dfs()) {
        cout << "FINITE";
    } else {
        cout << "INFINITE" << endl;
    }
    return 0;
}