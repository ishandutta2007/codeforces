#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, i, m, j;
    cin >> n >> m;
    vector<int> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    j = 0;
    vector<int> ans;
    int sum = 0;
    for (i = 1; i <= m; i++)
    {
        while (j < n && i > a[j])
            j++;
        if (j < n && a[j] == i)
            continue;
        if (sum + i > m)
            break;
        sum += i;
        ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}