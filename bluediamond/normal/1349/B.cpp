#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 7;
int n, a[N], x;
vector<pair<int, int>> stk;

bool ok()
{
        bool has0 = 0;
        for (int i = 1; i <= n; i++)
                if (a[i] == 0)
                        has0 = 1;
        if (!has0)
                return 0;
        for (int i = 1; i <= n - 1; i++)
                if (a[i] >= 0 && a[i + 1] >= 0)
                        a[i] = a[i + 1] = 0;
        for (int i = n - 1; i >= 1; i--)
                if (a[i] >= 0 && a[i + 1] >= 0)
                        a[i] = a[i + 1] = 0;
        for (int i = 1; i <= n - 2; i++)
        {
                int cnt = (a[i] >= 0) + (a[i + 1] >= 0) + (a[i + 2] >= 0);
                if (cnt >= 2)
                        a[i] = a[i + 1] = a[i + 2] = 0;
        }
        for (int i = n - 2; i >= 0; i--)
        {
                int cnt = (a[i] >= 0) + (a[i + 1] >= 0) + (a[i + 2] >= 0);
                if (cnt >= 2)
                        a[i] = a[i + 1] = a[i + 2] = 0;
        }
        for (int i = 1; i <= n; i++)
                if (a[i] != 0)
                        return 0;
        return 1;
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int tt;
        cin >> tt;
        while (tt--)
        {
                cin >> n >> x;
                a[0] = a[n + 1] = -69;
                for (int i = 1; i <= n; i++)
                {
                        int val;
                        cin >> val;
                        if (val < x)
                                a[i] = -1;
                        if (val == x)
                                a[i] = 0;
                        if (val > x)
                                a[i] = +1;
                }
                bool r = ok();
                if (r)
                        cout << "yes\n";
                else
                        cout << "no\n";
        }

}