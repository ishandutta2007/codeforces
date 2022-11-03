// Codeforces Round 112 (Div. 2): C

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.length();

    if (k == 0) {
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                continue;
            }
            int j = i;
            while (j + 1 < n && s[j + 1] == '0') {
                ++j;
            }

            int len = j - i + 1;

            result += 1LL * len * (len + 1) / 2;

            i = j;
        }
        cout << result << endl;
        return 0;
    }

    vector<int> zerosCountAfter(n, 0);
    zerosCountAfter[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (s[i + 1] == '1') {
            zerosCountAfter[i] = 0;
        } else {
            zerosCountAfter[i] = zerosCountAfter[i + 1] + 1;
        }
    }

    long long result = 0;
    int onesCount = 0;
    for (int l = 0, r = -1; l < n; ++l) {
        if (r < l) {
            r = l;
            onesCount = (s[l] == '1');
        }
        while (r + 1 < n && onesCount < k) {
            ++r;
            onesCount += (s[r] == '1');
        }

        if (onesCount == k) {
            result += (1 + zerosCountAfter[r]);
        }

        if (s[l] == '1') {
            --onesCount;
        }
    }

    cout << result << endl;

    return 0;
}