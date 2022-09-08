#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, b, ans, a[max_n];
vector<int> all;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int x = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (a[i] % 2) {
            ++x;
        } else {
            --x;
        }
        if (x == 0) {
            all.push_back(abs(a[i] - a[i + 1]));
        }
    }
    sort(all.begin(), all.end());
    for (int x : all) {
        if (x <= b) {
            b -= x;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}