#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int bits[N];
int n;
string s;

void add(int bit)
{
        bits[bit]++;
        while (bits[bit] == 2)
        {
                bits[bit] = 0;
                bit++;
                bits[bit]++;
        }
}

signed main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> s;


        reverse(s.begin(), s.end());
        n = (int) s.size();

        for (int i = 0; i < n; i++)
        {
                bits[i] = s[i] - '0';
        }

        int cnt0 = 0;
        for (int i = 0; i < n; i++)
        {
                cnt0 += (bits[i] == 0);
        }

        if (s.back() == '1' && cnt0 == n - 1)
        {
                cout << n - 1 << "\n";
                return 0;
        }

        int res = 0;

        for (int i = 0; i + 1 < n; i++)
        {
                if (bits[i] == 1)
                {
                        res++;
                        add(i);
                }
        }
        res += n;
        cout << res << "\n";



}