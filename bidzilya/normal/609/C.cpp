#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>
#include <deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n == 0) {
        int val = sum / n;
        unsigned int result = 0;
        for (int i = 0; i < n; ++i) {
            result += abs(a[i] - val);
        }
        cout << result / 2 << endl;
    } else {
        int minVal = sum / n;
        int maxVal = minVal + 1;

        int maxValCount = sum % n;
        int minValCount = n - maxValCount;

        unsigned int result = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= minVal) {
                if (minValCount > 0) {
                    result += minVal - a[i];
                    --minValCount;
                } else {
                    result += maxVal - a[i];
                    --maxValCount;
                }
            } else {
                if (maxValCount > 0) {
                    result += a[i] - maxVal;
                    --maxValCount;
                } else {
                    result += a[i] - minVal;
                    --minValCount;
                }
            }
        }
        cout << result / 2 << endl;
    }

    return 0;
}