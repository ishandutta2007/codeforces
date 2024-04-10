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

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (a[i] != a[j] && a[i] != a[k] && a[j] != a[k] && 
                        max(a[i], max(a[j], a[k])) - min(a[i], min(a[j], a[k])) <= 2) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}