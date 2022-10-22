#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, v;
    cin >> n >> v;

    vector <int> ans;

    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        int F = 0;

        while(k--)
        {
            int a;
            cin >> a;

            if(a < v)
                F = 1;
        }

        if(F)
            ans.pb(i + 1);
    }

    cout << ans.size() << "\n";

    for(auto x:ans)
        cout << x << ' ';
}