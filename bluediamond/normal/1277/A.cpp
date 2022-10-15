#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, cur = 1, ans = 0;
        cin >> n;
        while (1)
        {
            if (n / cur >= 9)
            {
                cur = 10 * cur + 1;
                ans += 9;
            }
            else
            {
                ans += n / cur;
                break;
            }
        }
        cout << ans << "\n";
    }
}