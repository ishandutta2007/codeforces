#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ans;
        int pw = 1;
        while (n) {
            if (n % 10) {
                ans.push_back(n % 10 * pw);
            }
            n /= 10;
            pw *= 10;
        }
        cout << ans.size() << "\n";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}