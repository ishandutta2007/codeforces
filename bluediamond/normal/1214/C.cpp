#include <bits/stdc++.h>

using namespace std;


int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n, op = 0, cl = 0, mnl = 0, lp, cur = 0;
        string s;
        cin >> n >> s;
        for (auto &c : s)
        {
                cur++;
                if (c == '(')
                {
                        lp = cur;
                        op++;
                }
                else
                        cl++;
                mnl = min(mnl, op - cl);
        }
        if (op == cl)
        {
                if (mnl == 0)
                {
                        cout << "Yes\n";
                        return 0;
                }
                bool taken = 0;
                cur = 0;
                int l = 0;
                for (auto &c : s)
                {
                        cur++;
                        if (cur == lp)
                                break;
                        if (c == '(')
                                l++;
                        else
                                l--;
                        if (l < 0)
                        {
                                l++;
                                if (taken)
                                {
                                        cout << "No\n";
                                        return 0;
                                }
                                taken = 1;
                        }
                }
                cout << "Yes\n";
                return 0;
        }
        cout << "No\n";
}