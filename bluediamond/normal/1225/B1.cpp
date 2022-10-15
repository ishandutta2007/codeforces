#include <bits/stdc++.h>

using namespace std;

map<int, int> f;
int act;
int a[(int) 2e5 + 7];

void ins(int x)
{
        f[x]++;
        act += (f[x] == 1);
}

void del(int x)
{
        f[x]--;
        act -= (f[x] == 0);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int t;
        cin >> t;
        while (t--)
        {
                act = 0;
                f.clear();
                int n, k, d, ans = (1 << 30);
                cin >> n >> k >> d;
                for (int i = 1; i <= n; i++)
                {
                        cin >> a[i];
                        ins(a[i]);
                        if (i >= d)
                        {
                                ans = min(ans, act);
                                del(a[i - d + 1]);
                        }
                }
                cout << ans << "\n";
        }
}