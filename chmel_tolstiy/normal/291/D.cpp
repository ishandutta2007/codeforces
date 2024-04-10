#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        vector<int> v;
        v.push_back(n);
        while (v.size() < n) {
            for (int j = 0; j < (1<<i); ++j) v.push_back(n);
            for (int j = 0; j < (1<<i); ++j) v.push_back(n-(1<<i));
        }
        v.resize(n);
        reverse(v.begin(), v.end());
        for (int j = 0; j < n; ++j) {
            if (j) cout << ' ';
            cout << v[j];
        }
        cout << endl;
    }
    return 0;
}