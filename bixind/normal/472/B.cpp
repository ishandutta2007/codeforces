#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, i, ans;
    cin >> n >> k;
    vector<int> m(n);
    for (i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    sort(m.begin(), m.end());
    i = n - 1;
    ans = 0;
    while (i >= 0)
    {
        ans += 2 * (m[i] - 1);
        i-=k;
    }
    cout << ans;
    return 0;
}