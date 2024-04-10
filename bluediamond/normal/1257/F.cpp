#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
const int H = 15;
int n, a[N], b[N];
int cnt[1 << H];

vector<vector<int>> get(int a[])
{
        vector<vector<int>>ans;
        for (int m = 0; m < (1 << H); m++)
        {
                vector<int> cur;
                for (int i = 1; i <= n; i++)
                {
                        cur.push_back(cnt[m ^ a[i]]);
                }
                ans.push_back(cur);
        }
        return ans;
}

int main()
{
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                a[i] = (x >> H);
                b[i] = x & ((1 << H) - 1);
        }

        for (int i = 1; i < (1 << H); i++)
        {
                int j = i & (-i);
                cnt[i] = 1 + cnt[i - j];
        }

        vector<vector<int>> x = get(a), y = get(b);
        map<vector<int>, int> sol;
        int cur = 0;
        for (auto &vec : y)
        {
                sol[vec] = cur++;
        }
        for (int l = 0; l <= 30; l++)
        {
                int cur = 0;
                for (auto &vec : x)
                {
                        vector<int> inv;
                        for (int i = 0; i < n; i++)
                        {
                                inv.push_back(l - vec[i]);
                        }
                        if (sol.count(inv))
                        {
                                cout << cur * (1 << H) + sol[inv] << "\n";
                                return 0;
                        }
                        cur++;
                }
        }
        cout << "-1\n";
}