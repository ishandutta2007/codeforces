#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bool has = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            has = true;
        }
    }

    if (!has) {
        cout << 0 << endl;
        return 0;
    }

    long long result = 1;
    for (int i = 0; i < n; ) {
        if (a[i] == 1) {
            int j = i + 1;
            while (j < n && a[j] == 0) {
                ++j;
            }
            if (j == n) {
                break;
            }
            result *= (j - i);
            i = j;
        } else {
            ++i;
        }
    }

    cout << result << endl;

    return 0;
}