#include <bits/stdc++.h>

using namespace std;

#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

map<string, int> ma;
map<string, int> ans;

string s[10010];

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        set<string> se;
        for (int q = 0; q < (int)s[i].size(); q++)
        {
            string t = "";
            for (int j = q; j < (int)s[i].size(); j++)
            {
                t += s[i][j];
                se.insert(t);
            }
        }
        for (auto t: se)
        {
            ma[t]++;
            ans[t] = i;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        if (ma[t] == 0)
            cout << "0 -\n";
        else
            cout << ma[t] << " " << s[ans[t]] << "\n";
    }
    return 0;
}