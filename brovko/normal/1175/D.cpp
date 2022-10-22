#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, k, a[300005], ps[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    ps[0]=0;
    for(int i=0;i<n;i++)
        ps[i+1]=ps[i]+a[i];

    int x=ps[n]*k;
    sort(ps+1, ps+n);
    for(int i=0;i<k-1;i++)
        x-=ps[i+1];
    cout << x;
}