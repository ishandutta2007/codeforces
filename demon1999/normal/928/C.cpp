#include <bits/stdc++.h>

using namespace std;

vector<pair<string, int> > mas[1010], ans;
map<string, int> ma;
map<pair<string, int>, int> ma2;
string s[1010];
int t[1010];
pair<int, int> di[1010];
int who[1010], used[1010];

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
        cin >> s[i] >> t[i];
        t[i] *= -1;
        ma2[{s[i], t[i]}] = i;
        if (ma.count(s[i]) == 0)
        {
            int x = ma.size();
            ma[s[i]] = x;
        }
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            string ss;
            int tt;
            cin >> ss >> tt;
            tt *= -1;
            mas[i].push_back({ss, tt});
        }
    }
    int m = ma.size();
    pair<int, int> p = {m + 10, m + 10};
    fill(di, di + m, p);
    di[ma[s[0]]] = {0, t[0]};
    who[ma[s[0]]] = 0;
    queue<int> que;
    que.push(ma[s[0]]);
    used[0] = 1;
    while(que.size())
    {
        int v = que.front();
        que.pop();
        int a = who[v];
        if (a > 0)
            ans.push_back({s[a], -t[a]});
        p = di[v];
        p.first++;
        for (auto pp: mas[a])
        {
            p.second = pp.second;
            int u = ma[pp.first];
            if (di[u] > p)
            {
                di[u] = p;
                who[u] = ma2[pp];
                if (used[u] == 0)
                {
                    used[u] = 1;
                    que.push(u);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";
    return 0;
}