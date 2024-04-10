#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        if(n % 2 == 0)
        {
            int k = 0;

            for(int i = 1; i < n; i += 2)
                if((s[i] - '0') % 2 == 0)
                    k++;

            if(k)
                cout << 2;
            else cout << 1;
        }
        else
        {
            int k = 0;

            for(int i = 0; i < n; i += 2)
                if((s[i] - '0') % 2 != 0)
                    k++;

            if(k)
                cout << 1;
            else cout << 2;
        }

        cout << "\n";
    }
}