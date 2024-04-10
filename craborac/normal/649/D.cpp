#include<bits/stdc++.h>

using namespace std;

int a[(int)2e5 + 10];

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > mas;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            mas.push_back({i, a[i]});
        }
    }
    int q = mas.size();
    while (q < n)
    {
        mas.push_back({n + q, 0});
        q++;
    }
    sort(mas.begin(), mas.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << mas[i].second << " \n"[i == n - 1];
        if (a[i] > 0 && a[i] != mas[i].second)
            ans++;
    }
    cout << ans << endl;
    return 0;
}