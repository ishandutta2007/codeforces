#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, string> mp;
    vector<string> ans;
    set<string> used;

    int q;
    for (cin >> q; q; --q) {
        string f, t;
        cin >> f >> t;

        if (used.find(f) == used.end()) {
            ans.push_back(f);
            used.insert(f);
        }

        used.insert(t);
        mp[f] = t;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
        string t = ans[i];

        while (mp.find(t) != mp.end()) {
            t = mp[t];
        }

        cout << ans[i] << " " << t << endl;
    }

    return 0;
}