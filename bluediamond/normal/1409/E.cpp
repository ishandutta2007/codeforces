#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n;
int x[N];
int mx[N];
int p[N];
int s[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /// sortez dupa [2 2 2 1 1 1 0 1 0 0 1 0]
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> cnt;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for (int i = 1; i <= n; i++)
        {
            int y;
            cin >> y;
        }
        n = 0;
        for (auto &it : cnt)
        {
            n++;
            x[n] = it.first;
            s[n] = s[n - 1] + it.second;
        }
        int j = 1;
        for (int i = 1; i <= n; i++)
        {
            while (x[i] - x[j] > k)
            {
                j++;
            }
            mx[i] = max(mx[i - 1], s[i] - s[j - 1]);
            p[i] = j;
        }
        int sol = mx[n];
        for (int i = 1; i <= n; i++)
        {
            int j = p[i];
            sol = max(sol, mx[j - 1] + s[i] - s[j - 1]);
        }
        cout << sol << "\n";
    }

}