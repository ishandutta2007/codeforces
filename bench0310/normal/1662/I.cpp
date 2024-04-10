#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> p(n,0);
    for(int i=0;i<n;i++) cin >> p[i];
    vector<int> x(m+2,0);
    x[0]=-1000000000;
    x[m+1]=-2*x[0];
    for(int i=1;i<=m;i++) cin >> x[i];
    ranges::sort(x);
    int j=0;
    ll res=0;
    for(int i=0;i<=m;i++)
    {
        int l=x[i];
        int r=x[i+1];
        if(j<n&&100*j==l) j++;
        vector<array<int,2>> v;
        while(j<n&&100*j<r)
        {
            v.push_back({100*j,p[j]});
            j++;
        }
        int sz=v.size();
        ll now=0;
        int y=0;
        for(int a=0;a<sz;a++)
        {
            while(y<sz&&2*(v[y][0]-v[a][0])<r-l) now+=v[y++][1];
            res=max(res,now);
            now-=v[a][1];
        }
    }
    cout << res << "\n";
    return 0;
}