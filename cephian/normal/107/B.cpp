#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int dep[1005];

int main() {
    ios_base::sync_with_stdio(0);

    int n, m, h;
    cin >> n >> m >> h;
    int sm = -1;
    for (int i = 0; i < m; ++i) {
        cin >> dep[i];
        sm += dep[i];
    }
    --dep[--h];
    --n;

    if (sm < n) {
        cout << "-1\n";
        return 0;
    }

    if (sm - dep[h] < n) {
        cout << "1\n";
        return 0;
    }
    double prob = 1;

    for (int i = 0; i < n; ++i) {
        prob *= double(sm - dep[h]) / sm;
        --sm;
    }
    cout << 1 - prob << "\n";
    return 0;
}