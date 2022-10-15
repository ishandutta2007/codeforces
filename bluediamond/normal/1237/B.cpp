#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 1e5 + 7;

struct P
{
    int x;
    int y;
};

bool cmp(P a, P b)
{
    return a.x < b.x;
}

int n;
P v[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v[a].x = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v[a].y = i;
    }
    sort(v + 1, v + n + 1, cmp);
    int sol = 0, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i].y < mx)
        {
            sol++;
        }
        mx = max(mx, v[i].y);
    }
    cout << sol << "\n";
}