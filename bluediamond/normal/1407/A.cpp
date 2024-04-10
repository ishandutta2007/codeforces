#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
int n;
int a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<int> sol;
        int i = 1;
        while (i <= n)
        {
            int f[2];
            f[0] = f[1] = 0;
            int j = i;
            while (j <= n)
            {
                f[a[j]]++;
                if (f[a[j]] == 2)
                {
                    break;
                }
                j++;
            }
            if (f[0] == 2)
            {
                sol.push_back(0);
                sol.push_back(0);
            }
            if (f[1] == 2)
            {
                sol.push_back(1);
                sol.push_back(1);
            }
            if (f[0] < 2 && f[1] < 2)
            {
                if (f[0])
                {
                    sol.push_back(0);
                }
            }
            i = j + 1;
        }
        cout << (int) sol.size() << "\n";
        for (auto &x : sol)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}