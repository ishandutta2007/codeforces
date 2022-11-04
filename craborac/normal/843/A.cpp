#include <bits/stdc++.h>
#define android ios

using namespace std;

vector<int> v;
int a[(int)1e5 + 10], used[(int)1e5 + 10];
pair<int, int> b[(int)1e5 + 10];

void dfs(int x)
{
    used[x] = 1;
    v.push_back(x);
    if (used[b[x].second] == 0)
        dfs(b[x].second);
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b, b + n);
    vector<vector<int> > ans;
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            v.clear();
            dfs(i);
            ans.push_back(v);
        }
    }
    cout << ans.size() << endl;
    for (auto v: ans)
    {
        cout << v.size() << " ";
        for (auto i: v)
            cout << i + 1 << " ";
        cout << "\n";
    }
    return 0;
}