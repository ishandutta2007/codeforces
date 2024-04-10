#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int bl = 0;
    int br = n;
    int resultPos = 0;
    int resultLen = 0;
    const int MAX_A = 1e6;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        bool found = false;

        vector<int> count(MAX_A + 1, 0);
        int diffCount = 0;

        const auto& add = [&diffCount, &count] (int x) {
            ++count[x];
            diffCount += (count[x] == 1);
        };

        const auto& del = [&diffCount, &count] (int x) {
            --count[x];
            diffCount -= (count[x] == 0);
        };

        for (int i = 0; i < bm; ++i) {
            add(a[i]);
        }

        for (int i = 0; i + bm <= n; ++i) {
            if (diffCount <= k) {
                resultPos = i;
                resultLen = bm;
                found = true;
            }
            del(a[i]);
            if (i + bm < n) {
                add(a[i + bm]);
            }
        }

        if (found) {
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }

    cout << resultPos + 1 << " " << resultPos + resultLen << endl;

    return 0;
}