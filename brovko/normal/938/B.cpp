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

    cin >> n;
    a[0]=1;
    a[n+1]=1000000;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    int Min=1e9;

    for(int i=0;i<=n;i++)
        Min=min(Min, max(a[i]-1, 1000000-a[i+1]));
    cout << Min;
}