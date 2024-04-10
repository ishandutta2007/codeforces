#include <iostream>
#include <algorithm>

using namespace std;

string g[100];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> g[i];
    //row
    for (int i = 0; i < n; ++i) {
        if (find(g[i].begin(), g[i].end(), '.') == g[i].end())
            goto skrow;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (g[i][j] == '.') {
                cout << i + 1 << " " << j + 1 << "\n";
                break;
            }
    }

    return 0;
    skrow: ;
    for (int i = 0; i < n; ++i) {
        bool f = 0;
        for (int j = 0; j < n; ++j)
            f |= g[j][i] == '.';

        if (!f) {
            cout << "-1\n";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (g[j][i] == '.') {
                cout << j + 1 << " " << i + 1 << "\n";
                break;
            }
    }

    return 0;
}