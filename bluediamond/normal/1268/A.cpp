#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 200000 + 7;
int n;
int k;
int dig[N];
string s;
int last = -1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ///freopen ("input", "r", stdin);

    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++)
    {
        dig[i] = s[i - 1] - '0';
    }
    for (int p = 0; p <= n; p++)
    {
        if (p - k >= 1 && dig[p] != dig[p - k])
        {
            break;
        }
        if (p == n)
        {
            cout << n << "\n";
            for (int i = 1; i <= n; i++)
            {
                cout << dig[i];
            }
            cout << "\n";
            return 0;
        }
        /// dif la p + 1
        for (int val = dig[p + 1] + 1; val <= 9; val++)
        {
            /// pos p + 1
            if (p + 1 - k >= 1 && val != dig[p + 1 - k])
            {
                continue;
            }
            last = p;
            break;
        }
    }
    if (last != -1)
    {
        cout << n << "\n";
        last++;
        for (int val = dig[last] + 1; val <= 9; val++)
        {
            /// pos p + 1
            if (last - k >= 1 && val != dig[last - k])
            {
                continue;
            }
            dig[last] = val;
            break;
        }
        for (int i = last + 1; i <= n; i++)
        {
            if (i - k + 1 >= 1)
            {
                dig[i] = dig[i - k];
            }
            else
            {
                if (i == 1)
                {
                    dig[i] = 1;
                }
                else
                {
                    dig[i] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << dig[i];
        }
    }
 ///   cout << last << "\n";
}