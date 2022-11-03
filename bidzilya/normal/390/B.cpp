#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    long long h = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 1) {
            --h;
            continue;
        }
        if (a[i] * 2 < b[i]) {
            --h;
        } else {
            h += 1LL * (b[i] / 2) * (b[i] - b[i] / 2);
        }
    }
    cout << h << endl;
    return 0;
}