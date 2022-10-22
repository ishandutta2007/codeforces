#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, l[100005], r[100005], used[100005];
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        v.erase(v.begin(), v.end());
        cin >> n;

        for(int i=0;i<n;i++)
            used[i]=0;

        for(int i=0;i<n;i++)
        {
            cin >> l[i] >> r[i];
            v.push_back({l[i], i});
        }
        sort(v.begin(), v.end());

        int Max=v[0].first;

        int f=0;

        for(auto to:v)
        {
            int x=to.second;
            if(l[x]>Max)
                f=1;
            Max=max(Max, r[x]);
            if(f==0)
                used[x]=1;
        }

        if(f==0)
            cout << -1;
        else
            for(int i=0;i<n;i++)
            if(used[i]==0)
                cout << 2 << ' ';
            else cout << 1 << ' ';
        cout << "\n";
    }
}