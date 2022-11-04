#include <bits/stdc++.h>

using namespace std;

int col[30];
int a[(int)1e6 + 10];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<int, int> > v;
    int b = k;
    for (int i = 2; i * i <= k; i++)
    {
        if (b % i == 0)
        {
            int num = 0;
            while (b % i == 0)
            {
                b /= i;
                num++;
            }
            v.push_back({i, num});
        }
    }
    if (b > 1)
        v.push_back({b, 1});
    for (int i = 0; i < v.size(); i++)
        col[i] = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << i << endl;
        for (int j = 0; j < v.size(); j++)
        {
            int num = 0;
            while (a[i] % v[j].first == 0)
            {
                a[i] /= v[j].first;
                num++;
            }
            if (num >= v[j].second)
                col[j] = 1;
            //cout << v[j].first << " " << v[j].second << " " << num << endl;
        }
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += col[i];
    if (sum == v.size())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}