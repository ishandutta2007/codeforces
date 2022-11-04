#include <bits/stdc++.h>
#define android ios

using namespace std;

int a[(int)2e5 + 10];
int ans[(int)2e5 + 10];
pair<int, int> b[(int)2e5 + 10];

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        ans[b[i].second] = a[i];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}