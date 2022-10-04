#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 2e5;
int n, a[mx];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mn = (*min_element(a, a + n));
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mn)
            pos.push_back(i);
    }
    int ans = 1e9;
    for (int i = 0; i < pos.size() - 1; ++i) {
        ans = min(ans, pos[i + 1] - pos[i]);
    }
    cout << ans << endl;
    return 0;
}