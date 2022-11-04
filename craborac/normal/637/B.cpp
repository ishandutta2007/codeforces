#include <bits/stdc++.h>

using namespace std;

pair<string, int> mas[(int)2e5 + 10];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mas[i] = {s, n - i};
    }
    sort(mas, mas + n);
    vector<pair<int, string> > ans;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || mas[i].first != mas[i - 1].first)
        {
            ans.push_back({mas[i].second, mas[i].first});
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].second << endl;
    }
    return 0;
}