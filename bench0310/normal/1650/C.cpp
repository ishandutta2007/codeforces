#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<array<int,3>> v(m);
        for(int i=0;i<m;i++)
        {
            auto &[w,x,id]=v[i];
            cin >> x >> w;
            id=i+1;
        }
        ranges::sort(v);
        int sum=0;
        vector<array<int,2>> u;
        for(int i=0;i<2*n;i++)
        {
            sum+=v[i][0];
            u.push_back({v[i][1],v[i][2]});
        }
        cout << sum << "\n";
        ranges::sort(u);
        for(int i=0;i<n;i++) cout << u[i][1] << " " << u[2*n-1-i][1] << "\n";
    }
    return 0;
}