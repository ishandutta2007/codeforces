#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector <int> ans;
    int k = 0;

    while(n + m > 0)
    {
        if(n > m || k == 2)
        {
            ans.pb(0);
            k = 0;
            n--;
        }
        else
        {
            ans.pb(1);
            k++;
            m--;
        }
    }

    if(n < 0 || m < 0)
    {
        cout << -1;
        return 0;
    }

    for(int i = 1; i < ans.size(); i++)
        if(ans[i] == 0 && ans[i - 1] == 0)
        {
            cout << -1;
            return 0;
        }

    for(int i = 2; i < ans.size(); i++)
        if(ans[i] == 1 && ans[i - 1] == 1 && ans[i - 2] == 1)
        {
            cout << -1;
            return 0;
        }

    for(auto x:ans)
        cout << x;
}