#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], b[100005];
vector < pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
        v.push_back({b[i]-a[i], i});
    }

    sort(v.begin(), v.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int y=v[i].second;
        ans+=a[y]*i+b[y]*(n-1-i);
    }
    cout << ans;
}