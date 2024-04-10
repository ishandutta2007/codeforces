#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif // ONLINE_JUDGE
    speed;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<double>q(n), w(n);
        for (int i = 0; i < n; i++)cin >> q[i];
        for (int i = 0; i < n; i++)cin >> w[i];
        vector<double>t;
        for (int i = 0; i < n; i++)
        {
            t.push_back(q[i] - w[i]);
            t.push_back(q[i] + w[i]);
        }
        assert(sz(t) == 2 * n);
        sort(all(t));
        double ans = (double)(t[0] + t[n + n - 1]) / (double)2.0;
        cout << fixed << setprecision(8) << ans << endl;
        }
    return 0;
}