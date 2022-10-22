#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[100005], c[100005], t[100005], d[100005], k;
vector < pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        {
            cin >> a[i];
            k+=a[i];
        }
    for(int i=0; i<n; i++)
        {
            cin >> c[i];
            v.push_back({c[i], i});
        }

    sort(v.begin(), v.end());

    for(int i=0; i<m; i++)
        {
            cin >> t[i] >> d[i];
            t[i]--;
        }

    int x=0;

    for(int i=0;i<m;i++)
    {
        k-=d[i];
        if(k<0)
            cout << "0\n";
        else if(a[t[i]]>=d[i])
        {
            a[t[i]]-=d[i];
            cout << c[t[i]]*d[i] << "\n";
        }
        else
        {
            int ans=c[t[i]]*a[t[i]];
            d[i]-=a[t[i]];
            a[t[i]]=0;

            while(d[i]>a[v[x].second])
            {
                int y=a[v[x].second];
                d[i]-=y;
                ans+=v[x].first*y;
                a[v[x].second]=0;
                x++;
            }

            ans+=d[i]*v[x].first;
            a[v[x].second]-=d[i];

           // cout << x << "!\n";

            cout << ans << "\n";
        }
    }
}