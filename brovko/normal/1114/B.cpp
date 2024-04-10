#include <bits/stdc++.h>
#define int long long
#define y1 sdofhdodfhd

using namespace std;

int n, m, k, a[200005];
vector <pair <int, int> > v;
vector <int> u;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        v.push_back({a[i], i});
    sort(v.begin(), v.end());

    /*for(auto to:v)
        cout << to.second << ' ';
    return 0;*/

    int ans=0;
    for(int i=n-k*m;i<n;i++)
    {
        u.push_back(v[i].second);
        ans+=v[i].first;
    }

    cout << ans << "\n";

    sort(u.begin(), u.end());
    for(int i=1;i<k;i++)
        cout << u[m*i-1]+1 << ' ';
}