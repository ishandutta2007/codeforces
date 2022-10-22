#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdifpghig

using namespace std;

int n, k, l, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> l;
    int m=n*k;
    for(int i=0;i<m;i++)
        cin >> a[i];
    sort(a, a+m);

    int r=0;
    while(r<m && a[r]-a[0]<=l)
        r++;
    r--;
    if(r+1<n)
    {
        cout << 0;
        return 0;
    }

    int s=0;
    for(int i=n-1;i>=0;i--)
    {
        int x=min(r, k*i);
        s+=a[x];
        r=x-1;
    }
    cout << s;
}