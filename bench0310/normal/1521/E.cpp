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
        int m,k;
        cin >> m >> k;
        vector<array<int,2>> v;
        for(int i=1;i<=k;i++)
        {
            int c;
            cin >> c;
            if(c>0) v.push_back({c,i});
        }
        sort(v.begin(),v.end(),greater<array<int,2>>());
        int mx=v[0][0];
        int n=0;
        while(mx>((n+1)/2)*n||m>n*n-(n/2)*(n/2)) n++;
        vector<array<int,2>> ord;
        for(int i=1;i<=n;i+=2) for(int j=2;j<=n;j+=2) ord.push_back({i,j});
        for(int i=1;i<=n;i+=2) for(int j=1;j<=n;j+=2) ord.push_back({i,j});
        for(int i=2;i<=n;i+=2) for(int j=1;j<=n;j+=2) ord.push_back({i,j});
        vector<vector<int>> res(n+1,vector<int>(n+1,0));
        int idx=0;
        for(auto [cnt,a]:v)
        {
            while(cnt--)
            {
                auto [r,c]=ord[idx++];
                res[r][c]=a;
            }
        }
        cout << n << "\n";
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout << res[i][j] << " \n"[j==n];
    }
    return 0;
}