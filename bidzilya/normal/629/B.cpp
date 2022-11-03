#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cF(366, 0), cM(366, 0);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        for (int j = a; j <= b; ++j) {
            if (c == 'F') {
                ++cF[j];
            } else {
                ++cM[j];
            }
        }
    }

    int result = 0;
    for (int i = 0; i < 366; ++i) {
        result = max(result, min(cF[i], cM[i]) * 2);
    }
    cout << result << endl;

    return 0;
}