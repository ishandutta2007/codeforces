#include <bits/stdc++.h>

using namespace std;

long long mas[(int)1e5 + 10];
pair<long long, int> arr[(int)1e5 + 10];
long long a[(int)1e5 + 10], b[(int)1e5 + 10], ans[(int)1e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    sort(mas, mas + n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        long long l, r;
        cin >> l >> r;
        arr[i] = {r - l + 1, i};
    }
    sort(arr, arr + m);
    a[m - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        pair<long long, int> p = {mas[i] - mas[i - 1], 0};
        int x = lower_bound(arr, arr + m, p) - arr;
        b[x] += mas[i] - mas[i - 1];
        if (x)
            a[x - 1]++;
        //cout << p.first << " " << x << endl;
    }
    for (int i = m - 2; i >= 0; i--)
        a[i] += a[i + 1];
    for (int i = 1; i < m; i++)
        b[i] += b[i - 1];
    /*
    for (int i = 0; i < m; i++)
        cout << a[i] << " " << b[i] << endl;
    //*/
    for (int i = 0; i < m; i++)
        ans[arr[i].second] = a[i] * arr[i].first + b[i];
    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}