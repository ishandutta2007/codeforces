#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 4e5 + 7;
int t;
int n;
int a[N];
bool ok[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            ok[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            ok[i] = (a[i] != a[i + 1]);
        }
        int h = n / 2;
        int bef = -1;
        for (int i = 1; i <= h; i++)
        {
            if (ok[i])
            {
                bef = i;
            }
        }
        int gg = 0, ss = 0, bb = 0;
        if (bef != -1)
        {
            int ls = 0;
            for (int g = 1; g + (g + 1) + (g + 1) <= h; g++)
            {
                if (!ok[g])
                {
                    continue;
                }
                int lm = bef;
                int sum = lm - g;
                /// avem ls - g >= g + 1
                /// ls >= 2 * g + 1
                if (ls < 2 * g + 1)
                {
                    ls = 2 * g + 1;
                }
                while (ls <= n && ok[ls] == 0)
                {
                    ls++;
                }
                if (ls <= n && ok[ls] == 1)
                {
                    int s = ls - g;
                    int b = sum - s;
                    if (g > 0 && s > 0 && b > 0 && s >= g + 1 && b >= g + 1 && g + s + b > gg + ss + bb)
                    {
                        gg = g;
                        ss = s;
                        bb = b;
                    }
                }
            }
        }
        cout << gg << " " << ss << " " << bb << "\n";
    }

}