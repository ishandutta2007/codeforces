#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int t;
        cin >> t;

        while (t--)
        {
                string s;
                cin >> s;

                for (char c = 'a'; c <= 'z'; c++)
                {
                        bool bad = 1;
                        int len = 0;
                        for (auto &it : s)
                        {
                                if (it == c)
                                        len++;
                                else
                                {
                                        if (len & 1)
                                        {
                                                bad = 0;
                                                break;
                                        }
                                        len = 0;
                                }
                        }
                        if (len & 1)
                                bad = 0;
                        if (!bad)
                                cout << c;
                }
                cout << "\n";
        }

        return 0;
}