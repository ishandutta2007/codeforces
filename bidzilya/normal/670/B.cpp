#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        cin >> id[i];
    }

    for (int i = 0; i < n; ++i) {
        if (k <= i + 1) {
            cout << id[k - 1] << endl;
            return 0;
        } else {
            k -= (i + 1);
        }
    }
}