#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int N = 250005;

int t[N], t2[N];

int get(int* t, int r)
{
    int ans = 1e9;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans = min(ans, t[r]);

    return ans;
}

void upd(int* t, int i, int val)
{
    for(; i < N; i = (i | i + 1))
        t[i] = min(t[i], val);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin >> _;

    while(_--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i <= n; i++)
            t[i] = 1e9, t2[i] = 1e9;

        stack <int> inc, dec;

        inc.push(-1);
        dec.push(-1);

        inc.push(0);
        dec.push(0);

        upd(t, n, a[0]);
        upd(t2, n, -a[0]);

        vector <int> dp(n + 1);

        for(int i = 1; i < n; i++)
        {
            while(inc.top() != -1 && a[inc.top()] > a[i])
                inc.pop();

            while(dec.top() != -1 && a[dec.top()] < a[i])
                dec.pop();

            int x;

//            cout << "! " << dec.top() << endl;

            if(a[i - 1] < a[i])
                x = dp[get(t, n - dec.top() - 1)] + 1;
            else x = dp[-get(t2, n - inc.top() - 1)] + 1;

            dp[a[i]] = x;

//            cout << x << ' ';

            inc.push(i);
            dec.push(i);

            upd(t, n - i, a[i]);
            upd(t2, n - i, -a[i]);
        }

        cout << dp[a[n - 1]] << "\n";
    }
}