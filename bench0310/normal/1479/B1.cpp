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
    vector<array<int,2>> v;
    int l=1;
    while(l<=n)
    {
        int r=l;
        while(r+1<=n&&a[r+1]==a[l]) r++;
        v.push_back({a[l],min(2,r-l+1)});
        l=r+1;
    }
    int res=0;
    vector<array<int,2>> occ[n+1]; //cnt,sum
    for(int i=1;i<=n;i++) occ[i].push_back({0,0});
    int sum=0;
    for(int i=0;i<(int)v.size();i++)
    {
        sum+=v[i][1];
        occ[v[i][0]].push_back({v[i][1],sum});
    }
    for(int i=1;i<=n;i++)
    {
        vector<array<int,2>> &x=occ[i];
        int now=0;
        for(int j=1;j<(int)x.size();j++)
        {
            int mid=(x[j][1]-x[j][0]-x[j-1][1]);
            now=max(0,now-mid);
            int c=min(2-now,x[j][0]);
            res+=c;
            now+=c;
        }
    }
    cout << res << "\n";
    return 0;
}