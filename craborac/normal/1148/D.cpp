#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<pair<pair<int, int>, int> > mas)
{
    vector<int> ans;
    sort(mas.begin(), mas.end());
    for (int i = (int)mas.size() - 1; i >= 0; i--)
        ans.push_back(mas[i].second);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int > > arr[2];
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int q = 0;
        if (a > b)
        {
            swap(a, b);
            q = 1;
        }
        pair<int, int> p = {a, b};
        arr[q].push_back({p, i});
    }
    auto ans1 = solve(arr[0]);
    auto ans2 = solve(arr[1]);
    reverse(ans2.begin(), ans2.end());
    if (ans2.size() > ans1.size())
        ans1 = ans2;
    cout << ans1.size() << "\n";
    for (int i: ans1)
        cout << i + 1 << " ";
    cout << endl;
    return 0;
}