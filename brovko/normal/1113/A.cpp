#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> k;
    int ans=0;
    int x=min(n-1, k);
    ans=x;
    for(int i=0;i<n-1-x;i++)
        ans+=i+2;
    cout << ans;

}