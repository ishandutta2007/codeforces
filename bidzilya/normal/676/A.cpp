#include <iostream>
#include <vector>
using namespace std;

int GetDist(const vector<int>& a, int n) {
    int onePos;
    int nPos;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            onePos = i;
        } else if (a[i] == n - 1) {
            nPos = i;
        }
    }
    return abs(nPos - onePos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(a[i], a[j]);
            result = max(result, GetDist(a, n));
            swap(a[i], a[j]);
        }
    }

    cout << result << endl;

    return 0;
}