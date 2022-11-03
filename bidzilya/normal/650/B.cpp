#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, a, b, t;
string s;
vector<int> sums;

inline int GetSum(int l, int r) {
    return (l == 0 ? sums[r] : sums[r] - sums[l - 1]);
}

bool Check(int count) {
    long long minCost = 1e18;
    for (int i = 1; i <= count; ++i) {
        int j = count - i;
        long long curCost = count;
        curCost += 1LL * b * GetSum(0, i - 1);
        if (j > 0) {
            curCost += 1LL * b * GetSum(n - j, n - 1);
        }
        curCost += 1LL * a * (min(j, i - 1) + (count - 1));
        minCost = min(minCost, curCost);
    }
    return minCost <= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b >> t;

    cin >> s;
    sums.resize(n);
    sums[0] = (s[0] == 'w');
    for (int i = 1; i < n; ++i) {
        sums[i] = sums[i - 1] + (s[i] == 'w');
    }

    int result = 0;
    int bl = 0;
    int br = n;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        if (Check(bm)) {
            result = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }

    cout << result << endl;

    return 0;
}