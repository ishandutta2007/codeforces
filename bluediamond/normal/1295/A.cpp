#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int t;
        cin >> t;
        while (t--)
        {
                int n;
                cin >> n;
                if (n >= 3 && n % 2)
                {
                        cout << "7";
                        n -= 3;
                }
                for (int i = 1; i <= n / 2; i++)
                        cout << "1";
                cout << "\n";
        }
}