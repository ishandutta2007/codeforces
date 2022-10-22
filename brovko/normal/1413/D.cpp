#include <bits/stdc++.h>
//#define int long long
#define ld long double

using namespace std;

int n, a[200005];
char c[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    n *= 2;

    for(int i = 0; i < n; i++)
    {
        cin >> c[i];

        if(c[i] == '-')
            cin >> a[i];
    }

    set <int> s;

    for(int i = n - 1; i >= 0; i--)
    {
        if(c[i] == '-')
        {
            if(s.size() > 0 && *s.begin() < a[i])
            {
                cout << "NO";
                return 0;
            }

            s.insert(a[i]);
        }
        else
            {
                if(s.size() == 0)
                {
                    cout << "NO";
                    return 0;
                }

                a[i] = *s.begin();
                s.erase(*s.begin());
            }
    }

    cout << "YES\n";

    for(int i = 0; i < n; i++)
        if(c[i] == '+')
            cout << a[i] << ' ';
}