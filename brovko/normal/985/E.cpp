#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdifpghig

using namespace std;

int n, k, d, a[500005], t[500005], dp[500005];

int sum(int r)
{
    if(r==-1)
        return 0;
    int s=0;
    for(;r>=0;r = (r & r+1)-1)
        s+=t[r];
    return s;
}

void inc(int i, int d)
{
    for(;i<=n;i=(i | i+1))
        t[i]+=d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> d;
    for(int i=0;i<n;i++)
        cin >> a[i];

    sort(a, a+n);

    dp[0]=1;
    inc(0, 1);
    int L=0;
    for(int i=k-1;i<n;i++)
        {
            while(a[i]-a[L]>d)
                L++;
            if(sum(i-k+1)>sum(L-1))
            {
                dp[i+1]=1;
                inc(i+1, 1);
            }
        }
    if(dp[n])
        cout << "YES";
    else cout << "NO";
}