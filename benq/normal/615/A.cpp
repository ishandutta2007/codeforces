#include <iostream>

using namespace std;

int turned[101];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int z;
        cin >> z;
        for (int j = 0; j < z; ++j) {
            int v;
            cin >> v;
            turned[v] = 1;
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (!turned[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}