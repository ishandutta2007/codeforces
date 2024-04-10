// Codeforces Round 251 (Div. 2): A

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int t1 = 0;
    for (int i = 0; i < n; ++i) {
        t1 += t[i];
    }

    int t2 = (n - 1) * 10;

    if (t1 + t2 > d) {
        cout << -1 << endl;
        return 0;
    }

    int result = t2 / 5 + (d - (t1 + t2)) / 5;

    cout << result << endl;

    return 0;
}