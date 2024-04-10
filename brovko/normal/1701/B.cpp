#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        cout << "2\n";

        vector <int> used(n + 1);

        for(int i = 1; i <= n; i++)
            if(used[i] == 0)
            {
                int x = i;

                while(x <= n)
                {
                    used[x] = 1;
                    cout << x << ' ';
                    x *= 2;
                }
            }

        cout << "\n";
    }
}