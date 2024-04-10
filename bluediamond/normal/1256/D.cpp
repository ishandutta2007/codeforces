#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e6 + 7;
int n, a[N];
ll k;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--)
    {
        cin >> n >> k >> s;
        for (int i = 1; i <= n; i++)
        {
            a[i] = s[i - 1] - '0';
        }

        int one = 0, last = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                if (one <= k)
                {
                    last++;
                    k -= one;
                }
                else
                {
                    break;
                }
            }
            else
            {
                last++;
                one++;
            }
        }
        sort(a + 1, a + last + 1);
        if (last < n)
        {
            int p = last + 1;
            while (k--)
            {
                swap(a[p], a[p - 1]);
                p--;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << a[i];
        }
        cout << "\n";
    }

}