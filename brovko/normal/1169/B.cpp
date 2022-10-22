#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[300005], b[300005], k[300005], x[300005];
vector <pair <int, int> > v;

bool comp(pair <int, int> i, pair <int, int> j)
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
    for(int i=0;i<m;i++)
        {
            cin >> a[i] >> b[i];
            k[a[i]]++;
            k[b[i]]++;
        }
    for(int i=1;i<=n;i++)
        v.push_back({k[i], i});
    sort(v.begin(), v.end(), comp);

    for(int i=0;i<min(3, n);i++)
    {
        for(int j=1;j<=n;j++)
            x[j]=0;
        int c=v[i].second;
        for(int j=0;j<m;j++)
            if(a[j]!=c && b[j]!=c)
            {
                x[a[j]]++;
                x[b[j]]++;
            }
        for(int j=1;j<=n;j++)
            if(x[j]+v[i].first==m)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}