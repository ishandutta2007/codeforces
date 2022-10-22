#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, c, a[500005], k, pk[500005], dp[500005];
vector <int> v[500005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> c;
    for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i]==c)
                k++;
            else
            {
                v[a[i]].push_back(i);
            }

            pk[i]=k;
        }

    for(int i=0;i<500005;i++)
        sort(v[i].begin(), v[i].end());

    int Max=0;

    for(int i=0;i<500005;i++)
        if(v[i].size())
    {
        vector <int> u;
        for(int j=0;j<(int)v[i].size()-1;j++)
        {
            u.push_back(1);
            u.push_back(pk[v[i][j]]-pk[v[i][j+1]]);
        }
        u.push_back(1);

        int m=u.size();
        dp[0]=1;
        for(int i=1;i<m;i++)
            dp[i]=max(0, dp[i-1]+u[i]);
        for(int i=0;i<m;i++)
            Max=max(Max, dp[i]);
    }

    cout << k+Max;
}