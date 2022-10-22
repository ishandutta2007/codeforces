#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, s, a[200005], used[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    s--;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        used[a[i]]++;
    }

    int mex = 0;
    int Max = n;

    while(used[mex])
        mex++;

    while(used[Max] == 0)
        Max--;

    int ans = 0;

    if(a[s])
    {
        used[a[s]]--;
        used[0]++;
        ans++;

        while(used[mex])
            mex++;

        while(used[Max] == 0)
            Max--;
    }

    while(used[0] > 1)
    {
        used[0]--;
        used[mex]++;
        ans++;

        while(used[mex])
            mex++;

        while(used[Max] == 0)
            Max--;
    }

    while(mex <= Max)
    {
        used[Max]--;
        used[mex]++;
        ans++;

        while(used[mex])
            mex++;

        while(used[Max] == 0)
            Max--;
    }

    cout << ans;
}