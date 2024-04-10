#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, s[100005], r[100005], ans[100005];
vector <int> v[100005];
vector <int> ps[100005];

bool comp(int i, int j)
{
    return i>j;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        {
            cin >> s[i] >> r[i];
            v[s[i]].push_back(r[i]);
        }

    for(int i=1;i<=m;i++)
        sort(v[i].begin(), v[i].end(), comp);

    for(int i=1;i<=m;i++)
    {
        int s=0;
        for(int j=0;j<v[i].size();j++)
        {
            s+=v[i][j];
            ps[i].push_back(s);
        }
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<ps[i].size();j++)
            if(ps[i][j]>0)
                ans[j]+=ps[i][j];
    }

    int Max=0;

    for(int j=0;j<n;j++)
        Max=max(Max, ans[j]);
    cout << Max;
}