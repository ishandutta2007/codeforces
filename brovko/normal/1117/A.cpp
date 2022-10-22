#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    int Max=0;
    for(int i=0; i<n; i++)
        Max=max(Max, a[i]);

    int ans=0;
    int k=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]==Max)
            k++;
        else k=0;
        ans=max(ans, k);
    }
    cout << ans;
}