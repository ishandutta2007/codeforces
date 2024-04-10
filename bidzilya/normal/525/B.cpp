#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n, 0);

    int q;
    cin >> q;
    for (int itr = 0; itr < q; ++itr) {
        int r;
        cin >> r;
        ++a[r - 1];
    }
    for (int i = 0; 2 * i < n; ++i) {
        a[i] %= 2;
        if (a[i] == 1) {
            swap(s[i], s[n - i - 1]);
            a[i + 1] += a[i];
        }
    }
    cout << s << endl;
    return 0;
}