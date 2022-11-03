#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 1 << endl;
        cout << 1 << endl;
    } else if (n == 3) {
        cout << 2 << endl;
        cout << 1 << " " << 3 << endl;
    } else if (n == 4) {
        cout << 4 << endl;
        cout << "2 4 1 3" << endl;
    } else {
        cout << n << endl;
        vector<int> ans(n);
        int c = 0;
        for (int i = 0; i < n; i += 2) {
            ans[i] = c;
            ++c;
        }
        for (int i = 1; i < n; i += 2) {
            ans[i] = c;
            ++c;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}