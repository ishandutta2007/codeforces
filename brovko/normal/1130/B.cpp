#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005];
vector <int> v[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<2*n;i++)
    {
        cin >> a[i];
        v[a[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)
        sort(v[i].begin(), v[i].end());

    int x=0;
    int y=0;
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        ans+=abs(v[i][0]-x)+abs(v[i][1]-y);
        x=v[i][0];
        y=v[i][1];
    }

    cout << ans;
}