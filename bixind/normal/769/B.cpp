#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first;
        v[i].first = -v[i].first;
        v[i].second = i;
    }
    sort(v.begin() + 1, v.end());
    int pos = 1;
    vector<pair<int, int> > ans;
    for (int i = 0; i < n && pos < n; ++i) {
        if (v[i].first == 0)
        {
            cout << "-1\n";
            return 0;
        }
        for (int j = 0; j < -v[i].first && pos < n; ++j)
            ans.push_back({v[i].second + 1, v[pos].second +1}), ++pos;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}