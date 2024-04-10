#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<int,4> n;
    cin >> n[1] >> n[2] >> n[3];
    vector<ll> v[4];
    array<ll,4> sum={0,0,0,0};
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=n[i];j++)
        {
            ll a;
            cin >> a;
            v[i].push_back(a);
            sum[i]+=a;
        }
        sort(v[i].begin(),v[i].end());
    }
    auto o=[](vector<int> z)->vector<int>
    {
        array<bool,4> a={0,0,0,0};
        for(int x:z) a[x]=1;
        z.clear();
        for(int i=1;i<=3;i++) if(a[i]==0) z.push_back(i);
        return z;
    };
    ll res=0;
    for(int i=1;i<=3;i++)
    {
        if(v[i].size()==1)
        {
            vector<int> id=o({i});
            res=max(res,sum[id[0]]+sum[id[1]]-v[i][0]);
        }
        else
        {
            vector<int> id=o({i});
            res=max(res,sum[id[0]]+sum[id[1]]-sum[i]);
        }
        for(int j=i+1;j<=3;j++)
        {
            res=max(res,sum[1]+sum[2]+sum[3]-2*(v[i][0]+v[j][0]));
        }
    }
    cout << res << "\n";
    return 0;
}