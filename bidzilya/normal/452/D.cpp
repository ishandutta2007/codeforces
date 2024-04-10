#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    int n[3];
    int t[3];

    cin >> k;
    for (int i = 0; i < 3; ++i) {
        cin >> n[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> t[i];
    }

    vector<int> a;
    a.push_back(0);
    --k;
    while (k > 0) {
        int ct[3];

        if (a.size() < n[0]) {
            ct[0] = a.back();
        } else {
            ct[0] = max(a[a.size() - n[0]] + t[0], a.back());
        }

        if (a.size() < n[1]) {
            ct[1] = a.back();
        } else {
            ct[1] = max(a[a.size() - n[1]] + t[1], a.back());
        }

        if (a.size() < n[2]) {
            ct[2] = a.back();
        } else {
            ct[2] = max(a[a.size() - n[2]] + t[2], a.back());
        }

        a.push_back(max(ct[0], max(ct[1], ct[2])));
        --k;
    }

    cout << a.back() + t[0] + t[1] + t[2] << endl;

    return 0;
}