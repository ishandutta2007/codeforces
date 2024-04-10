#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n, a[N];
int last[N];
int value[N];
int maxS[N];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                value[i] = x;
        }
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
                int t;
                cin >> t;
                if (t == 1)
                {
                        int p, x;
                        cin >> p >> x;
                        last[p] = i;
                        value[p] = x;
                }
                else
                {
                        int x;
                        cin >> x;
                        maxS[i] = x;
                }
        }
        for (int i = q - 1; i >= 0; i--)
                maxS[i] = max(maxS[i], maxS[i + 1]);
        for (int i = 1; i <= n; i++)
                cout << max(value[i], maxS[last[i]]) << " ";
        cout << "\n";
        return 0;
}