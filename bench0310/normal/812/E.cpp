#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> v[n+1];
    for(int i=2;i<=n;i++)
    {
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    vector<int> d(n+1,0);
    function<void(int)> dfs=[&](int e)
    {
        for(int to:v[e])
        {
            d[to]=1-d[e];
            dfs(to);
        }
    };
    dfs(1);
    array<ll,2> c={0,0};
    int x=0;
    int r=d[n];
    map<int,ll> m;
    for(int i=1;i<=n;i++)
    {
        if(d[i]!=r) m[a[i]]++;
        c[d[i]]++;
        if(d[i]==r) x^=a[i];
    }
    ll res=0;
    if(x==0) res=(c[0]*(c[0]-1)/2+c[1]*(c[1]-1)/2);
    for(int i=1;i<=n;i++) if(d[i]==r) res+=m[x^a[i]];
    cout << res << "\n";
    return 0;
}