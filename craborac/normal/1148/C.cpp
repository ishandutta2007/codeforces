#include <bits/stdc++.h>

using namespace std;

int where[(int)3e5 + 10], p[(int)3e5 + 10];
vector<pair<int, int> > ans;
int n;

void swap1(int x, int y)
{
    if (x == y)
        return;
    swap(where[p[x]], where[p[y]]);
    swap(p[x], p[y]);
    ans.push_back({x, y});
}

void swap2(int x, int y)
{
    if (2 * abs(x - y) >= n)
        swap1(x, y);
    else if (min(x, y) >= n / 2)
    {
        swap1(x, 0);
        swap1(0, y);
        swap1(x, 0);
    }
    else if (max(x, y) < n / 2)
    {
        swap1(x, n - 1);
        swap1(y, n - 1);
        swap1(x, n - 1);
    }
    else
    {
        if (x > y)
            swap(x, y);
        swap1(x, n - 1);
        swap1(0, n - 1);
        swap1(0, y);
        swap1(0, n - 1);
        swap1(x, n - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        where[p[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        if (p[i] != i + 1)
        {
            swap2(i, where[i + 1]);
        }
    }
    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    return 0;
}