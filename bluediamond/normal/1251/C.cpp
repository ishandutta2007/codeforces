#include <bits/stdc++.h>

using namespace std;

const int N = 300000 + 7;
int n, a[N];
string s;

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int t;
        cin >> t;

        while (t--)
        {
                cin >> s;
                n = (int) s.size();
                for (int i = 1; i <= n; i++)
                        a[i] = s[i - 1] - '0';

                vector <vector <int>> p(2);
                int i = 1;
                while (i <= n)
                {
                        int j = i;
                        p[a[i] & 1].push_back(a[i]);
                        while (j + 1 <= n && a[j + 1] == a[i])
                        {
                                j++;
                                p[a[i] & 1].push_back(a[i]);
                        }
                        i = j + 1;
                }

                vector <int> ans;
                int p0 = 0, p1 = 0, s0 = (int) p[0].size(), s1 = (int) p[1].size();
                while (p0 < s0 || p1 < s1)
                {
                        int t = -1;
                        if (p0 == s0)
                                t = 1;
                        if (p1 == s1)
                                t = 0;
                        if (t == -1)
                        {
                                if (p[0][p0] < p[1][p1])
                                        t = 0;
                                else
                                        t = 1;
                        }
                        if (t == 0)
                                ans.push_back(p[0][p0++]);
                        else
                                ans.push_back(p[1][p1++]);
                }
                for (auto &x : ans)
                        cout << x;
                cout << "\n";
        }

        return 0;
}