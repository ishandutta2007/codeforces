#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum & 1) {
        int minValue = 1e9;
        for (int i = 0; i < n; ++i) {
            if (a[i] & 1) {
                minValue = min(minValue, a[i]);
            }
        }
        sum -= minValue;
    }

    cout << sum << endl;

    return 0;
}