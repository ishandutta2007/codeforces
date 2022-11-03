#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int maxResult = 0;
    int minResult = n;
    for (int i = 0; i < 7; ++i) {
        int curResult = 0;
        int curI = i;
        for (int j = 0; j < n; ++j) {
            if (curI == 6 || curI == 5) {
                ++curResult;
            }
            ++curI;
            if (curI == 7) {
                curI = 0;
            }
        }
        maxResult = max(maxResult, curResult);
        minResult = min(minResult, curResult);
    }

    cout << minResult << " " << maxResult << endl;

    return 0;
}