#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > mas[2];
int a[(int)1e5 + 10], b[(int)1e5 + 10];

int main()
{
    srand(3228);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int a = abs((x + y) % 2);
        mas[a].push_back({(x + y - a) / 2, (x - y - a) / 2});
    }
    long long ans = 0;
    for (int i = 0; i < 2; i++)
    {
        sort(mas[i].begin(), mas[i].end());
        a[mas[i].size()] = (int)-3e5;
        b[mas[i].size()] = (int)3e6;
        for (int j = (int)mas[i].size() - 1; j >= 0; j--)
        {
            a[j] = max(a[j + 1], mas[i][j].second);
            b[j] = min(b[j + 1], mas[i][j].second);
        }
        int c = (int)-3e5;
        int d = (int)3e5;
        for (int j = 0; j + 2 < (int)mas[i].size(); j++)
        {
            c = max(c, mas[i][j].second);
            d = min(d, mas[i][j].second);
            long long le = max(b[j + 1], d);
            long long ri = min(a[j + 1], c);
            if (ri > le)
            {
                //cerr << c << " " << d << " " << a[j] << " " << b[j] << endl;
                //cerr << " " << mas[i][j].first << " " << mas[i][j + 1].first << "   " << le << " " << ri << "    " << j << endl;
                ans += (ri - le) * (mas[i][j + 1].first - mas[i][j].first);
            }
        }
    }
    cout << ans << endl;
    return 0;
}