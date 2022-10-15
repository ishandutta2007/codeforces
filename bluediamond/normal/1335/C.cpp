#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> f;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            f[x]++;
        }
        vector<int> a;
        for (auto &it : f)
        {
            a.push_back(it.second);
        }
        sort(a.rbegin(), a.rend());
        cout << max(min((int) a.size(), a[0] - 1), min((int) a.size() - 1, a[0])) << "\n";
    }

}