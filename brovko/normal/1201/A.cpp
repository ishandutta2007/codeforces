#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[1005], b[1005][128], Max, ans, f[1005];
string s[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=0;i<m;i++)
        cin >> f[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            b[j][s[i][j]]++;
    for(int i=0;i<m;i++)
    {
        Max=0;
        for(int j='A';j<='Z';j++)
            Max=max(Max, b[i][j]);
        ans+=Max*f[i];
    }
    cout << ans;
}