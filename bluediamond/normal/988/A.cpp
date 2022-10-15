#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    map<int, int> id;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        id[x] = i;
    }
    if ((int) id.size() >= k)
    {
        cout << "YES\n";
        for (auto &it : id)
        {
            cout << it.second << " ";
            k--;
            if (k == 0)
            {
                break;
            }
        }
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }
}