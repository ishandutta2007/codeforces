#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct P
{
        int x;
        int y;
};

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin >> n;
        vector <P> a(4 * n + 1);
        for (int i = 0; i < 4 * n + 1; i++)
                cin >> a[i].x >> a[i].y;
        for (int i = 0; i < 4 * n + 1; i++)
        {
                int xmi, ymi;
                xmi = ymi = (1 << 30);
                int xma, yma;
                xma = yma = -(1 << 30);
                for (int j = 0; j < 4 * n + 1; j++)
                {
                        if (i == j)
                                continue;
                        xmi = min(xmi, a[j].x);
                        ymi = min(ymi, a[j].y);
                        xma = max(xma, a[j].x);
                        yma = max(yma, a[j].y);
                }
                int c1, c2, c3, c4;
                c1 = c2 = c3 = c4 = 0;
                bool ok = 1;
                for (int j = 0; j < 4 * n + 1; j++)
                {
                        if (i == j)
                                continue;
                        int f = c1 + c2 + c3 + c4;
                        c1 += (a[j].x == xmi);
                        c2 += (a[j].y == ymi);
                        c3 += (a[j].x == xma);
                        c4 += (a[j].y == yma);
                        int s = c1 + c2 + c3 + c4;
                        if (f == s)
                                ok = 0;
                }
                if (ok && min(min(c1, c2), min(c3, c4)) >= n)
                {
                        cout << a[i].x << " " << a[i].y << "\n";
                        return 0;
                }
        }

        return 0;
}