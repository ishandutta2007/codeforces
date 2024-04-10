#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
int n, m;

struct INFO
{
        int x;
        int i;
};

bool operator < (INFO a, INFO b)
{
        return (a.x < b.x);
}

INFO a[N];
int ans[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
                cin >> a[i].x;
                a[i].i = i;
        }
        sort(a + 1, a + n + 1);
        vector <pair <int, int>> b(m);
        for (int i = 0; i < m; i++)
                cin >> b[i].first >> b[i].second;
        sort(b.begin(), b.end());
        int j = 0;
        ll curs = 0;
        for (int i = 1; i <= n; i++)
        {
                while (j < m && b[j].first <= a[i].x)
                        curs += b[j++].second;
                ans[a[i].i] = curs;
        }

        for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
        cout << "\n";

        return 0;
}