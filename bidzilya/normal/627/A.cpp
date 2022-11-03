#include <iostream>
#include <vector>
using namespace std;

const int MAX_BIT_COUNT = 60;

inline int GetBit(long long x, int num) {
    return (x >> num) & 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long s, x;
    cin >> s >> x;

    vector<vector<long long>> count(MAX_BIT_COUNT, vector<long long>(2, 0));
    count[0][0] = 1;
    for (int i = 0; i + 1 < MAX_BIT_COUNT; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int b = 0; b < 2; ++b) {
                int val = GetBit(s, i) - b - j;
                int newJ = 0;
                if (val < 0) {
                    val += 2;
                    ++newJ;
                }
                if (val == (b ^ GetBit(x, i))) {
                    count[i + 1][newJ] += count[i][j];
                }
            }
        }
    }

    long long result = count[MAX_BIT_COUNT - 1][0];

    if (s == x) {
        result -= 2;
    }

    cout << result << endl;

    return 0;
}