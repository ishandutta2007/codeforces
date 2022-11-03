#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    int curPow2 = 0;
    int curPow5 = 0;
    vector<int> result;
    for (int i = 1; ; ++i) {
        int x = i;
        while (x % 2 == 0) {
            ++curPow2;
            x /= 2;
        }
        while (x % 5 == 0) {
            ++curPow5;
            x /= 5;
        }

        int curPow = min(curPow2, curPow5);

        if (curPow == m) {
            result.push_back(i);
        }
        if (curPow > m) {
            break;
        }
    }

    cout << result.size() << endl;
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}