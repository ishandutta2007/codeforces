#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> a(n);
    for(int i=0;i<n;i++) cin >> a[i][0] >> a[i][1];
    vector<array<int,2>> b(m);
    for(int i=0;i<m;i++) cin >> b[i][0] >> b[i][1];
    vector<array<int,2>> v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int dx=b[j][0]-a[i][0]+1;
            int dy=b[j][1]-a[i][1]+1;
            if(min(dx,dy)>0) v.push_back({dx,dy});
        }
    }
    auto solve=[&]()->int
    {
        if(v.empty()) return 0;
        sort(v.begin(),v.end());
        int sz=v.size();
        vector<int> mx(sz+1,0);
        for(int i=sz-1;i>=0;i--) mx[i]=max(mx[i+1],v[i][1]);
        int res=min(mx[0],v[sz-1][0]);
        for(int i=0;i<sz-1;i++) res=min(res,v[i][0]+mx[i+1]);
        return res;
    };
    int res=solve();
    for(array<int,2> &x:v) swap(x[0],x[1]);
    res=min(res,solve());
    cout << res << "\n";
    return 0;
}